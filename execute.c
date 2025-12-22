#include "shell.h"

void execute_command(char *line, char *prog, char **env, int count)
{
	char **argv;
	char *path;
	pid_t pid;

	argv = split_line(line);
	if (!argv || !argv[0])
	{
		free_argv(argv);
		return;
	}

	path = find_path(argv[0], env);
	if (!path)
	{
		print_error(prog, argv[0], count);
		free_argv(argv);
		return;
	}

	pid = fork();
	if (pid == 0)
		execve(path, argv, env);
	else
		wait(NULL);

	free(path);
	free_argv(argv);
}

