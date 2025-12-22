#include "shell.h"

int main(int ac, char **av, char **env)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	int count = 0;

	(void)ac;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "($) ", 4);

		read = getline(&line, &len, stdin);
		if (read == -1)
			break;

		count++;
		execute_command(line, av[0], env, count);
	}
	free(line);
	return (0);
}

