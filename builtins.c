#include "shell.h"

void handle_exit(void)
{
	exit(last_status);
}

void handle_env(char **env)
{
	int i = 0;

	while (env && env[i])
	{
		write(STDOUT_FILENO, env[i], strlen(env[i]));
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
}

