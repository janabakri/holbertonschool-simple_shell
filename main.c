#include "main.h"

/**
 * main - simple shell 0.2
 * @ac: argument count
 * @av: argument vector
 *
 * Return: 0
 */
int main(int ac, char **av)
{
	char *line, *cmd, *end;
	size_t len;
	ssize_t read_bytes;
	int status;
	char **args;

	(void)ac;
	line = NULL;
	len = 0;
	status = 0;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			display_prompt();

		read_bytes = getline(&line, &len, stdin);
		if (read_bytes == -1)
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			break;
		}

		if (read_bytes > 0 && line[read_bytes - 1] == '\n')
			line[read_bytes - 1] = '\0';

		/* trim leading spaces/tabs */
		cmd = line;
		while (*cmd == ' ' || *cmd == '\t')
			cmd++;

		if (*cmd == '\0')
			continue;

		/* trim trailing spaces/tabs */
		end = cmd + strlen(cmd) - 1;
		while (end > cmd && (*end == ' ' || *end == '\t'))
		{
			*end = '\0';
			end--;
		}

		args = split_line(cmd);
		if (args == NULL)
			continue;

		if (args[0] != NULL && strcmp(args[0], "exit") == 0)
		{
			free_args(args);
			break;
		}

		status = execute_command(args, av[0], status);
		free_args(args);
	}

	free(line);
	return (0);
}
