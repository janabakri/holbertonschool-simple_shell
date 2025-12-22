#include "shell.h"

void print_error(char *prog, char *cmd, int count)
{
    char buffer[1024];
    sprintf(buffer, "%s: %d: %s: not found\n", prog, count, cmd);
    write(STDERR_FILENO, buffer, strlen(buffer));
}

