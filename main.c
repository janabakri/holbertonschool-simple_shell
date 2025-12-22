#include "shell.h"

/**
 * main - Simple shell skeleton (Betty compliant)
 * @ac: Number of arguments
 * @av: Arguments array
 *
 * Return: Always 0
 */
int main(int ac, char **av)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	int interactive;

	(void)ac;
	(void)av;

	interactive = isatty(STDIN_FILENO);

	while (1)
	{
		if (interactive)
			write(STDOUT_FILENO, "($) ", 4);

		read = getline(&line, &len, stdin);
		if (read == -1)
		{
			if (interactive)
				write(STDOUT_FILENO, "\n", 1);
			break;
		}

		if (read >= 5 &&
		    line[0] == 'e' &&
		    line[1] == 'x' &&
		    line[2] == 'i' &&
		    line[3] == 't' &&
		    (line[4] == '\n' || line[4] == ' '))
			break;
	}

	free(line);
	return (0);
}

