#include "shell.h"

int last_status = 0;

static char *trim_spaces(char *s)
{
	int end, i;

	if (!s)
		return (s);

	while (*s == ' ' || *s == '\t')
		s++;

	if (*s == '\0')
		return (s);

	end = 0;
	while (s[end] != '\0')
		end++;
	end--;

	while (end >= 0 && (s[end] == ' ' || s[end] == '\t'))
	{
		s[end] = '\0';
		end--;
	}

	i = 0;
	while (s[i] != '\0')
		i++;
	if (i > 0 && s[i - 1] == '\r')
		s[i - 1] = '\0';

	return (s);
}

static void builtin_env(void)
{
	int i = 0;

	while (environ && environ[i])
	{
		write(STDOUT_FILENO, environ[i], strlen(environ[i]));
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
}

static void builtin_exit(char **args)
{
	int code = last_status;

	if (args && args[1])
	{
		int i = 0;

		while (args[1][i])
		{
			if (args[1][i] < '0' || args[1][i] > '9')
				exit(2);
			i++;
		}
		code = atoi(args[1]) & 255;
	}

	exit(code);
}

int main(int ac, char **argv, char **env)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read_bytes;
	int count = 0;
	char *cmd;
	char **args;

	(void)ac;
	(void)env;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "($) ", 4);

		read_bytes = my_getline(&line, &len, STDIN_FILENO);
		if (read_bytes == -1)
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			break;
		}

		count++;

		if (read_bytes > 0 && line[read_bytes - 1] == '\n')
			line[read_bytes - 1] = '\0';

		cmd = trim_spaces(line);

		if (*cmd == '\0')
			continue;

		args = split_line(cmd);
		if (!args || !args[0])
		{
			free_args(args);
			continue;
		}

		if (strcmp(args[0], "exit") == 0)
		{
			free(line);
			line = NULL;
			len = 0;
			free_args(args);
			builtin_exit(args);
		}
		else if (strcmp(args[0], "env") == 0)
		{
			builtin_env();
			free_args(args);
			continue;
		}

		last_status = execute_command(args, argv[0], last_status);

		free_args(args);
	}

	free(line);
	return (last_status);
}

