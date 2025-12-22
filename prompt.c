#include "shell.h"

/**
 * prompt_if_interactive - print prompt if interactive
 *
 * Return: 0
 */
int prompt_if_interactive(void)
{
	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "($) ", 4);

	return (0);
}

