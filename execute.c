#include "shell.h"
#include <string.h>

/**
 * run_line - process one command line
 * @st: shell state
 * @line: input line
 *
 * Return: 0 to continue, -1 to exit
 */
int run_line(shell_state_t *st, char *line)
{
	char *cmd;

	cmd = strtok(line, " \t\n");
	if (cmd == NULL)
		return (0);

	if (strcmp(cmd, "exit") == 0)
		return (-1);

	return (execute_command(st, cmd));
}

/**
 * execute_command - fork and execve command
 * @st: shell state
 * @cmd: command
 *
 * Return: 0
 */
int execute_command(shell_state_t *st, char *cmd)
{
	pid_t pid;
	int status;
	char *args[2];

	args[0] = cmd;
	args[1] = NULL;

	pid = fork();
	if (pid == -1)
		return (0);

	if (pid == 0)
	{
		execve(cmd, args, environ);
		print_not_found(st, cmd);
		_exit(127);
	}

	waitpid(pid, &status, 0);
	return (0);
}

