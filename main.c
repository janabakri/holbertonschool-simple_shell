#include "shell.h"

int last_status = 0;  /* آخر حالة خروج */

int main(int ac, char **argv, char **env)
{
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    int count = 0;

    (void)ac;

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
            handle_exit();  /* بدون معاملات */
        }

        last_status = execute_command(line, argv[0], env, count);
    }

    free(line);
    return last_status;
}

