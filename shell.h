#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

extern char **environ;

/* المتغير العالمي لتخزين آخر حالة خروج */
extern int last_status;

/* الدوال الأساسية */
int execute_command(char *line, char *prog, char **env, int count);
char **split_line(char *line);
char *find_path(char *command, char **env);
void print_error(char *prog, char *cmd, int count);
void free_argv(char **argv);

/* built-in */
void handle_exit(void);  /* بدون معاملات */

#endif /* SHELL_H */

