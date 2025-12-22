#include "shell.h"

void print_error(char *prog, char *cmd, int count)
{
	fprintf(stderr, "%s: %d: %s: not found\n", prog, count, cmd);
}

