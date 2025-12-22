#include "shell.h"

/**
 * main - Entry point for simple shell 0.1
 * @ac: argument count
 * @av: argument vector
 *
 * Return: 0 on success
 */
int main(int ac, char **av)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t nread;
	shell_state_t st;

	(void)ac;

	st.argv0 = av[0];
	st.line_number = 0;

	while (1)
	{
		st.line_number++;

		if (prompt_if_interactive() == -1)
			break;

		nread = getline(&line, &len, stdin);
		if (nread == -1)
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

