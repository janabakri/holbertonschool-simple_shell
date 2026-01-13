#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void free_argv(char **argv);  // Declare the function from utils.c

// Function to execute a command
int execute_command(char *command) {
    char **argv = NULL;   // Assume argv is created here from command
    int argc = 0;

    // For demonstration, let's split command by space
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
    if (argv) {
        argv[argc] = NULL;  // NULL-terminate the array
    }

    // Normally you would fork and exec here
    printf("Command parts:\n");
    for (int i = 0; i < argc; i++) {
        printf("[%d]: %s\n", i, argv[i]);
    }

    // Free memory
    free_argv(argv);

    return 0;
}

int main() {
    char command[] = "echo Hello World";
    execute_command(command);
    return 0;
}
