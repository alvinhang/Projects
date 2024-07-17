#define _XOPEN_SOURCE 700 // needed for sigaction to be defined error
#define _POSIX_C_SOURCE 200112
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <semaphore.h>
#include "dungeon_info.h"

// created a global pointer for the shared memory
struct Dungeon *dungeon;
sem_t *lever_one;

// barbarian attack function for when receiving a signal from dungeon
void barbarian_attack(int sig) {
    if (sig == SIGUSR1) {
        printf("Signal received: DUNGEON_SIGNAL\n");
        printf("Current enemy health before attack: %d\n", dungeon->enemy.health);
        dungeon->barbarian.attack = dungeon->enemy.health;
        printf("Barbarian attack set to: %d\n", dungeon->barbarian.attack);

        sleep(SECONDS_TO_ATTACK);

        if (dungeon->barbarian.attack == dungeon->enemy.health) {
            printf("Barbarian attack successful!\n");
        } else {
            printf("Barbarian attack failed!\n");
        }
    }
    if (!dungeon->running) {
        printf("Process termination signal received during operation. Exiting handler early.\n");
        return;
    }
}

// This is the signal handler for the semaphore signal
void handle_semaphore_signal(int sig) {
    if (sig == SIGUSR2) {
        sem_wait(lever_one);  // Assuming access to lever_one
        printf("Barbarian is holding the door open.\n");
    }
    if (!dungeon->running) {
        printf("Process termination signal received during operation. Exiting handler early.\n");
        return;
    }
}

int main() {
    // This opens shared memory
    int shm_fd = shm_open(dungeon_shm_name, O_RDWR, 0666);
    if (shm_fd == -1) {
        perror("Failed to open shared memory");
        exit(EXIT_FAILURE);
    }

    // This is a map of the shared memory
    dungeon = mmap(NULL, sizeof(struct Dungeon), PROT_READ | PROT_WRITE, MAP_SHARED, shm_fd, 0);
    if (dungeon == MAP_FAILED) {
        perror("Failed to map the shared memory");
        close(shm_fd);
        exit(EXIT_FAILURE);
    }

    // This opens the lever semaphores
    lever_one = sem_open(dungeon_lever_one, 0);
    if (lever_one == SEM_FAILED) {
        perror("Failed to open semaphore lever_one");
        exit(EXIT_FAILURE);
    }

    // This sets up a signal handler for DUNGEON_SIGNAL
    struct sigaction sa;
    sigemptyset(&sa.sa_mask);
    sa.sa_handler = barbarian_attack;
    sa.sa_flags = SA_RESTART; // Restart functions if it is interrupted by the handler
    if (sigaction(SIGUSR1, &sa, NULL) == -1) {
        perror("Failed to set up the signal handler for DUNGEON_SIGNAL");
        munmap(dungeon, sizeof(struct Dungeon));
        close(shm_fd);
        exit(EXIT_FAILURE);
    }

    // This sets up the signal handler for the semaphore signal
    struct sigaction sa_semaphore;
    sigemptyset(&sa_semaphore.sa_mask);
    sa_semaphore.sa_handler = handle_semaphore_signal;
    sa_semaphore.sa_flags = 0;
    if (sigaction(SIGUSR2, &sa_semaphore, NULL) == -1) {
        perror("Failed to setup semaphore signal handler for Barbarian");
        exit(EXIT_FAILURE);
    }

    // This is a loop that will pause the process until a signal is received
    while (dungeon->running) {
        pause();
        if (!dungeon->running) {
            printf("Shutting down process due to dungeon->running being set to false.\n");
            break;
        }
    }

    // This closes the shared memory
    munmap(dungeon, sizeof(struct Dungeon));
    close(shm_fd);
    sem_close(lever_one);
    exit(EXIT_SUCCESS);

    return 0;
}