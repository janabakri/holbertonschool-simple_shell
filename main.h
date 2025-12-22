#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

void display_prompt(void);
int execute_command(char **args, char *argv0, char *line, int last_status);

#endif /* MAIN_H */

