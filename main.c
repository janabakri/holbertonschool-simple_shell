#include "shell.h"

int last_status = 0;

int main(int ac, char **argv, char **env)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read_bytes;
	int count = 0;

	(void)ac;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "($) ", 4);

		/* Task 0.1.1: use custom getline (NOT getline) */
		read_bytes = my_getline(&line, &len, STDIN_FILENO);
		if (read_bytes == -1)
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			break;
		}

		count++;

		/* remove trailing newline */
		if (read_bytes > 0 && line[read_bytes - 1] == '\n')
			line[read_bytes - 1] = '\0';

		/* handle CRLF */
		{
			int n = (int)strlen(line);

			if (n > 0 && line[n - 1] == '\r')
				line[n - 1] = '\0';
		}

		/* builtins */
		if (strcmp(line, "exit") == 0)
		{
			free(line);
			line = NULL;
			len = 0;
			handle_exit();
		}

		if (strcmp(line, "env") == 0)
		{
			handle_env(env);
			continue;
		}

		last_status = execute_command(line, argv[0], env, count);
	}

	free(line);
	return (last_status);
}

