#include "shell.h"

int main(int ac, char **argv, char **env)
{
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    int count = 0;
    int status = 0; /* آخر حالة خروج */

    (void)ac;

    while (1)
    {
        if (isatty(STDIN_FILENO))
            write(STDOUT_FILENO, "($) ", 4);

        read = getline(&line, &len, stdin);
        if (read == -1)
            break;

        count++;

        /* تحقق من built-in exit */
        if (strcmp(line, "exit\n") == 0)
        {
            free(line);
            handle_exit(status);  /* أرسل آخر حالة خروج */
        }

        status = execute_command(line, argv[0], env, count);
    }

    free(line);
    return status;
}

