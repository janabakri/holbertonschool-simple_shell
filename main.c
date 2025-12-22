#include "main.h"

/**
 * main - simple shell 0.1
 * @ac: argument count
 * @av: argument vector
 *
 * Return: 0
 */
int main(int ac, char **av)
{
    char *line = NULL;
    size_t len = 0;
    ssize_t read_bytes;
    shell_state_t st;
    int status = 0;

    (void)ac;
    st.argv0 = av[0];

    while (1)
    {
        /* Display prompt if in interactive mode */
        if (isatty(STDIN_FILENO))
            display_prompt();

        /* Read command line */
        read_bytes = getline(&line, &len, stdin);
        if (read_bytes == -1)
        {
            if (isatty(STDIN_FILENO))
                write(STDOUT_FILENO, "\n", 1);
            break;
        }

        /* Remove newline character */
        if (read_bytes > 0 && line[read_bytes - 1] == '\n')
            line[read_bytes - 1] = '\0';

        /* Skip empty lines */
        if (line[0] == '\0')
            continue;

        /* Check for exit command */
        if (strcmp(line, "exit") == 0)
            break;

        /* Execute command */
        status = execute_command(NULL, av[0], line, status);
    }

    free(line);
    return (0);
}
