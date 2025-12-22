#include "shell.h"

/**
 * main - simple shell 0.1
 * @ac: argument count
 * @av: argument vector
 *
 * Return: 0
 */
int main(int ac, char **av)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	shell_state_t st;

	(void)ac;
	st.argv0 = av[0];

	while (1)
	{
		prompt_if_interactive();

		read = getline(&line, &len, stdin);
		if (read == -1)
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			break;
		}

		if (run_line(&st, line) == -1)
			break;
	}

	free(line);
	return (0);
}

