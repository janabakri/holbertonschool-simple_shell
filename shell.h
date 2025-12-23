#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

extern char **environ;

/* Prompt */
void display_prompt(void);

/* Required: custom getline (do NOT use getline) */
ssize_t my_getline(char **lineptr, size_t *n, int fd);

/* Split + free */
char **split_line(char *line);
void free_args(char **args);

/* Execute */
int execute_command(char **args, char *argv0, int last_status);

#endif /* SHELL_H */

