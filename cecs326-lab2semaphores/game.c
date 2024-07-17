#define _XOPEN_SOURCE 600
#define _POSIX_C_SOURCE 200112
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <signal.h>
#include <semaphore.h>
#include "dungeon_info.h"

int main() {
    // Create shared memory
    int shm_fd = shm_open(dungeon_shm_name, O_CREAT | O_RDWR, 0666);
    if (shm_fd == -1) {
        perror("Failed to create/open shared memory");
        exit(EXIT_FAILURE);
    }
    // Set the size of the shared memory
    ftruncate(shm_fd, sizeof(struct Dungeon));
    struct Dungeon* dungeon = mmap(0, sizeof(struct Dungeon), PROT_READ | PROT_WRITE, MAP_SHARED, shm_fd, 0);
    if (dungeon == MAP_FAILED) {
        perror("Failed to map shared memory");
        close(shm_fd);
        exit(EXIT_FAILURE);
    }
    // Initialize the dungeon
    dungeon->running = true;

    // Create semaphores
    sem_t* lever_one = sem_open(dungeon_lever_one, O_CREAT, 0666, 1);
    if (lever_one == SEM_FAILED) {
        perror("Failed to open semaphore lever_one");
        exit(EXIT_FAILURE);
    }
    sem_t* lever_two = sem_open(dungeon_lever_two, O_CREAT, 0666, 1);
    if (lever_two == SEM_FAILED) {
        perror("Failed to open semaphore lever_two");
        exit(EXIT_FAILURE);
    }

    // Fork the processes for the Barbarian, Wizard, and Rogue
    pid_t pid_barbarian, pid_wizard, pid_rogue;
    pid_barbarian = fork();
    if (pid_barbarian == 0) {
        execl("./barbarian", "barbarian", NULL);
        perror("Failed to start Barbarian");
        exit(EXIT_FAILURE);
    }
    pid_wizard = fork();
    if (pid_wizard == 0) {
        execl("./wizard", "wizard", NULL);
        perror("Failed to start Wizard");
        exit(EXIT_FAILURE);
    }
    pid_rogue = fork();
    if (pid_rogue == 0) {
        execl("./rogue", "rogue", NULL);
        perror("Failed to start Rogue");
        exit(EXIT_FAILURE);
    }

    // Wait for the processes to start
    sleep(1);

    // Runs the dungeon
    RunDungeon(pid_wizard, pid_rogue, pid_barbarian);
    
    // Cleans up the dungeon and exits, killing all processes
    dungeon->running = false;

    while (wait(NULL) > 0); // Properly wait for all children

    kill(pid_barbarian, SIGKILL);
    kill(pid_wizard, SIGKILL);
    kill(pid_rogue, SIGKILL);

    munmap(dungeon, sizeof(struct Dungeon));
    close(shm_fd);
    shm_unlink(dungeon_shm_name);
    sem_close(lever_one);
    sem_unlink(dungeon_lever_one);
    sem_close(lever_two);
    sem_unlink(dungeon_lever_two);

    return 0;
}
