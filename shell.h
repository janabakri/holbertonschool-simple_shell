#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

extern int last_status;
extern char **environ;

/* custom getline */
ssize_t my_getline(char **lineptr, size_t *n, int fd);

/* builtins */
void handle_exit(void);
void handle_env(char **env);

/* executor */
int execute_command(char *line, char *prog, char **env, int count);

/* helpers */
char **split_line(char *line);
void free_argv(char **argv);
char *find_path(char *command, char **env);
void print_error(char *prog, char *cmd, int count);

/* custom string helpers (replace forbidden functions) */
int _strcmp(const char *s1, const char *s2);
int _strlen(const char *s);
char *_strdup(const char *s);
char *_strchr(const char *s, char c);

#endif /* SHELL_H */

