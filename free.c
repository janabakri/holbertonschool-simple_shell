#include "shell.h"

void free_argv(char **argv)
{
    int i;

    if (!argv)
        return;

    for (i = 0; argv[i]; i++)
        free(argv[i]);
    free(argv);
}

