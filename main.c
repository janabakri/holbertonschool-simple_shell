#include "main.h"

/**
 * main - simple shell 0.1
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

		/* if empty after leading trim, continue */
		if (*cmd == '\0')
			continue;

		/* trim trailing spaces/tabs */
		end = cmd + strlen(cmd) - 1;
		while (end > cmd && (*end == ' ' || *end == '\t'))
		{
			*end = '\0';
			end--;
		}

		if (strcmp(cmd, "exit") == 0)
			break;

		status = execute_command(NULL, av[0], cmd, status);
	}

	free(line);
	return (0);
}
