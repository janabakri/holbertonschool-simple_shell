#include <stdio.h>
#include <stdlib.h>

// Function to free an array of strings
void free_argv(char **argv) {
    if (!argv)
        return;
    for (int i = 0; argv[i] != NULL; i++) {
        free(argv[i]);
    }
    free(argv);
}

// You can add other utility functions here if needed
