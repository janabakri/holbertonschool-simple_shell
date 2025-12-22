#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

extern char **environ;

/**
 * struct shell_state - shell state
 * @argv0: program name
 */
typedef struct shell_state
{
	char *argv0;
} shell_state_t;

int prompt_if_interactive(void);
int run_line(shell_state_t *st, char *line);
int execute_command(shell_state_t *st, char *cmd);
void print_not_found(shell_state_t *st, const char *cmd);

#endif /* SHELL_H */

