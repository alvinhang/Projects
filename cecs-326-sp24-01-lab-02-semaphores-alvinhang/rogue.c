#define _XOPEN_SOURCE 600 // needed for sigaction to be defined error
#define _POSIX_C_SOURCE 200112
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>
#include <semaphore.h>
#include "dungeon_info.h"

// created a global pointer for the shared memory
struct Dungeon *dungeon;
sem_t *lever_one, *lever_two;

// This is the function to adjust the pick based on the feedback from the dungeon
void adjust_pick() {
    float low = 0.0;
    float high = MAX_PICK_ANGLE;
    float threshold = LOCK_THRESHOLD;
    float mid = 0.0;

    while (low <= high) {
        mid = (low + high) / 2.0; // Calculate midpoint and cast to int
        dungeon->rogue.pick = mid; // Set the current guess in the dungeon

        usleep(TIME_BETWEEN_ROGUE_TICKS); // Wait for dungeon feedback

        char direction = dungeon->trap.direction;
        printf("Current pick: %f, direction: %c\n", mid, direction);

        // Reset direction after reading to detect changes in the next iteration
        dungeon->trap.direction = 't'; // Resetting the direction to temp after processing

        if (direction == '-') {
            printf("Lock picked successfully!\n");
            dungeon->trap.locked = false;
            break;
        }

        if (direction == 'u') {
            low = mid + threshold; // Adjust low to be just above the current midpoint
        } else if (direction == 'd') {
            high = mid - threshold; // Adjust high to the current midpoint
        }
    }
}


// This is the treasure collection function it will collect the treasure and exit
void collect_treasure() {
    int index = 0;
    while (index < 4 && dungeon->running) {
        if (dungeon->treasure[index] != '\0') {
            dungeon->spoils[index] = dungeon->treasure[index];
            index++;
        }
        usleep(TIME_TREASURE_AVAILABLE); // This should have a delay between treasure availability
    }

    // releases the lever semaphores
    sem_post(lever_one);
    sem_post(lever_two);

    exit(EXIT_SUCCESS);
}

// This is the signal handler for dungeon signal
void rogue_action(int sig) {
    if (sig == SIGUSR1) {
        adjust_pick();
    }

    if (!dungeon->running) {
        printf("Process termination signal received during operation. Exiting handler early.\n");
        return;
    }
}

// This is the signal handler for the semaphore signal
void handle_semaphore_signal(int sig) {
    if (sig == SIGUSR2) {
        collect_treasure();
    }

    if (!dungeon->running) {
        printf("Process termination signal received during operation. Exiting handler early.\n");
        return;
    }
}

int main() {
    // This opens the shared memory and maps it to the dungeon pointer
    int shm_fd = shm_open(dungeon_shm_name, O_RDWR, 0666);
    dungeon = mmap(NULL, sizeof(struct Dungeon), PROT_READ | PROT_WRITE, MAP_SHARED, shm_fd, 0);
    if (dungeon == MAP_FAILED) {
        perror("Failed to map shared memory");
        close(shm_fd);
        exit(EXIT_FAILURE);
    }

    // This opens the lever semaphores
    lever_one = sem_open(dungeon_lever_one, 0);
    lever_two = sem_open(dungeon_lever_two, 0);
    if (lever_one == SEM_FAILED || lever_two == SEM_FAILED) {
        perror("Failed to open semaphores");
        if (lever_one != SEM_FAILED) sem_close(lever_one);
        if (lever_two != SEM_FAILED) sem_close(lever_two);
        exit(EXIT_FAILURE);
    }

    // This sets up the signal handler for the rogue
    struct sigaction sa;
    sigemptyset(&sa.sa_mask);
    sa.sa_handler = rogue_action;
    sa.sa_flags = 0;
    if (sigaction(SIGUSR1, &sa, NULL) == -1) {
        perror("Failed to setup signal handler for SIGUSR1");
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
        perror("Failed to setup semaphore signal handler for Rogue");
        exit(EXIT_FAILURE);
    }

    // This is the main loop for the rogue which will pause until a signal is received
    while (dungeon->running) {
        pause();
    }

    // This unmaps the shared memory and closes the file descriptor and semaphores
    munmap(dungeon, sizeof(struct Dungeon));
    close(shm_fd);
    sem_close(lever_one);
    sem_close(lever_two);
    exit(EXIT_SUCCESS);
    return 0;
}
