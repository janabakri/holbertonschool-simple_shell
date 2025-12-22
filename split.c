#include "shell.h"

char **split_line(char *line)
{
	char **argv;
	char *token;
	int i = 0;

	argv = malloc(sizeof(char *) * 64);
	token = strtok(line, " \n");
	while (token)
	{
		argv[i++] = strdup(token);
		token = strtok(NULL, " \n");
	}
	argv[i] = NULL;
	return (argv);
}

