#include "main.h"

/**
 * execute_command - Execute a command with arguments (no PATH)
 * @args: tokenized args (args[0] is command)
 * @argv0: program name
 * @last_status: last status (unused for now)
 *
 * Return: exit status if exited, else 0
 */
int execute_command(char **args, char *argv0, int last_status)
{
	pid_t pid;
	int status;

	(void)last_status;

	if (args == NULL || args[0] == NULL)
		return (0);

	pid = fork();
	if (pid == -1)
		return (0);

	if (pid == 0)
	{
		execve(args[0], args, environ);

		write(STDERR_FILENO, argv0, strlen(argv0));
		write(STDERR_FILENO, ": ", 2);
		write(STDERR_FILENO, args[0], strlen(args[0]));
		write(STDERR_FILENO, ": No such file or directory\n", 28);
		_exit(127);
	}

	waitpid(pid, &status, 0);

	if (WIFEXITED(status))
		return (WEXITSTATUS(status));

	return (0);
}
