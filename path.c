#include "shell.h"

char *find_path(char *cmd, char **env)
{
	char *path, *dir, *full;
	struct stat st;
	int i;

	if (cmd[0] == '/' || cmd[0] == '.')
	{
		if (stat(cmd, &st) == 0)
			return (strdup(cmd));
		return (NULL);
	}

	for (i = 0; env[i]; i++)
	{
		if (strncmp(env[i], "PATH=", 5) == 0)
			path = strdup(env[i] + 5);
	}

	dir = strtok(path, ":");
	while (dir)
	{
		full = malloc(strlen(dir) + strlen(cmd) + 2);
		sprintf(full, "%s/%s", dir, cmd);
		if (stat(full, &st) == 0)
		{
			free(path);
			return (full);
		}
		free(full);
		dir = strtok(NULL, ":");
	}
	free(path);
	return (NULL);
}

