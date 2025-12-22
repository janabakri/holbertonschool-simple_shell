#include "main.h"

/**
 * execute_command - Execute a command (single word, no args)
 * @args: unused (future use)
 * @argv0: program name
 * @line: command line (single word)
 * @last_status: unused
 *
 * Return: exit status of last command or 0
 */
int execute_command(char **args, char *argv0, char *line, int last_status)
{
	pid_t pid;
	int status;
	char *cmd_args[2];

	(void)args;
	(void)last_status;

	cmd_args[0] = line;
	cmd_args[1] = NULL;

	pid = fork();
	if (pid == -1)
		return (0);

	if (pid == 0)
	{
		execve(line, cmd_args, environ);

		/* If execve fails */
		write(STDERR_FILENO, argv0, strlen(argv0));
		write(STDERR_FILENO, ": ", 2);
		write(STDERR_FILENO, line, strlen(line));
		write(STDERR_FILENO, ": No such file or directory\n", 28);
		_exit(127);
	}

	waitpid(pid, &status, 0);

	if (WIFEXITED(status))
		return (WEXITSTATUS(status));

	return (0);
}

