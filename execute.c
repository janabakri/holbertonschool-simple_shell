#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// --- utils.c functions ---
void free_argv(char **argv) {
    if (!argv)
        return;
    for (int i = 0; argv[i] != NULL; i++) {
        free(argv[i]);
    }
    free(argv);
}

// --- execute.c functions ---
int execute_command(char *command) {
    char **argv = NULL;
    int argc = 0;

    // Split command by space
    char *token = strtok(command, " ");
    while (token != NULL) {
        argv = realloc(argv, sizeof(char*) * (argc + 2));
        if (!argv) {
            perror("realloc failed");
            return -1;
        }
        argv[argc] = strdup(token);
        argc++;
        token = strtok(NULL, " ");
    }
    if (argv)
        argv[argc] = NULL;

    // Print command parts
    printf("Command parts:\n");
    for (int i = 0; i < argc; i++) {
        printf("[%d]: %s\n", i, argv[i]);
    }

    // Free memory
    free_argv(argv);

    return 0;
}

// --- main ---
int main() {
    char command[] = "echo Hello World";
    execute_command(command);
    return 0;
}
