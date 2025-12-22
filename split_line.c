#include "main.h"

/**
 * split_line - split a command line into tokens
 * @line: line to split (will be modified)
 *
 * Return: array of tokens (NULL terminated) or NULL on failure
 */
char **split_line(char *line)
{
	char *tmp, *tok;
	int count, i;
	char **args;

	tmp = strdup(line);
	if (tmp == NULL)
		return (NULL);

	count = 0;
	tok = strtok(tmp, " \t");
	while (tok != NULL)
	{
		count++;
		tok = strtok(NULL, " \t");
	}
	free(tmp);

	args = malloc(sizeof(char *) * (count + 1));
	if (args == NULL)
		return (NULL);

	i = 0;
	tok = strtok(line, " \t");
	while (tok != NULL)
	{
		args[i++] = tok;
		tok = strtok(NULL, " \t");
	}
	args[i] = NULL;

	return (args);
}

/**
 * free_args - free args array
 * @args: args array
 */
void free_args(char **args)
{
	free(args);
}
