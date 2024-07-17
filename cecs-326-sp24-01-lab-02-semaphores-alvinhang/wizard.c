#define _XOPEN_SOURCE 700 // needed for sigaction to be defined error
#define _POSIX_C_SOURCE 200112
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <ctype.h>
#include <semaphore.h>
#include "dungeon_info.h"

// created a global pointer for the shared memory
struct Dungeon *dungeon;
sem_t *lever_two;

// This is the Caesar Cipher Decoding Function
void decodeCaesarCipher(char *encoded, char *decoded, int len) {
    int shift = (encoded[0]) % 26;
    int i, j;
    for (i = 0, j = 0; i < len; i++) {
        char c = encoded[i + 1];
        if ((isalpha(c)) && (c != '\0')) {
            if (isupper(c)) {
                int current_char_ascii_dec = c - 'A';
                int shifted_char = (current_char_ascii_dec - shift + 26) % 26;
                decoded[j++] = shifted_char + 'A';
            } else if (islower(c)) {
                int current_char_ascii_dec = c - 'a';
                int shifted_char = (current_char_ascii_dec - shift + 26) % 26;
                decoded[j++] = shifted_char + 'a';
            }
        } else {
            decoded[j++] = c;
        }
    }
    decoded[j] = '\0';
}

// This is the signal handler for the wizard
void wizard_action(int sig) {
    if (sig == SIGUSR1) {
        int length = strlen(dungeon->barrier.spell) - 1;
        decodeCaesarCipher(dungeon->barrier.spell, dungeon->wizard.spell, length);
        printf("Wizard decoded the spell: %s\n", dungeon->wizard.spell);
    }
    if (!dungeon->running) {
        printf("Process termination signal received during operation. Exiting handler early.\n");
        return;
    }
}

// This is the signal handler for the semaphore signal
void handle_semaphore_signal(int sig) {
    if (sig == SIGUSR2) {
        sem_wait(lever_two);  // Assuming access to lever_two
        printf("Wizard is holding the door open.\n");
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
    lever_two = sem_open(dungeon_lever_two, 0);
    if (lever_two == SEM_FAILED) {
        perror("Failed to open semaphore lever_two");
        exit(EXIT_FAILURE);
    }

    // This sets up the signal handler for the wizard
    struct sigaction sa;
    sigemptyset(&sa.sa_mask);
    sa.sa_handler = wizard_action;
    sa.sa_flags = 0;
    if (sigaction(SIGUSR1, &sa, NULL) == -1) {
        perror("Failed to setup signal handler for SIGUSR1");
        return 1;
    }

    // This sets up the signal handler for the semaphore signal
    struct sigaction sa_semaphore;
    sigemptyset(&sa_semaphore.sa_mask);
    sa_semaphore.sa_handler = handle_semaphore_signal;
    sa_semaphore.sa_flags = 0;
    if (sigaction(SIGUSR2, &sa_semaphore, NULL) == -1) {
        perror("Failed to setup semaphore signal handler for Wizard");
        exit(EXIT_FAILURE);
    }

    // Calculate the total number of iterations based on SECONDS_TO_GUESS_BARRIER and TIME_BETWEEN_ROGUE_TICKS
    int total_iterations = SECONDS_TO_GUESS_BARRIER * 1000000 / TIME_BETWEEN_ROGUE_TICKS;
    int i = 0; // Counter for number of iterations

    // This is the main loop for the wizard
    while (dungeon->running && i < total_iterations) {
        pause();

        if (!dungeon->running) {
            printf("Shutting down process due to dungeon->running being set to false.\n");
            break;
        }

        i++; // Increments the counter
    }

    // This closes the shared memory and semaphore
    munmap(dungeon, sizeof(struct Dungeon));
    close(shm_fd);
    sem_close(lever_two);
    exit(EXIT_SUCCESS);

    return 0;
}