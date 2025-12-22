#include "shell.h"

int main(int ac, char **argv, char **env)
{
    char *line;
    size_t len;
    ssize_t read;
    int count;
    int status;

    (void)ac;

    line = NULL;
    len = 0;
    count = 0;
    status = 0;

    while (1)
    {
        if (isatty(STDIN_FILENO))
            write(STDOUT_FILENO, "($) ", 4);

        read = getline(&line, &len, stdin);
        if (read == -1)
            break;

        count++;

        if (strcmp(line, "exit\n") == 0)
        {
            free(line);
            handle_exit(status);
        }

        status = execute_command(line, argv[0], env, count);
    }

    free(line);
    return status;
}

