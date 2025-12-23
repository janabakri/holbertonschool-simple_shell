#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

extern int last_status;
extern char **environ;

/* Task 0.1.1: your custom getline */
ssize_t my_getline(char **lineptr, size_t *n, int fd);

/* Builtins */
void handle_exit(void);
void handle_env(char **env);

/* MUST match execute.c exactly */
int execute_command(char *line, char *prog, char **env, int count);

/* Helpers used by execute.c */
char *find_path(char *command, char **env);
void print_error(char *prog, char *cmd, int count);

/* If execute.c calls free_argv, declare it */
void free_argv(char **argv);

/* If you use these */
char **split_line(char *line);
void free_args(char **args);

#endif /* SHELL_H */

