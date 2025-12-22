int main(int ac, char **argv, char **env)
{
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    int count = 0;
    int status = 0;

    (void)ac;

    while (1)
    {
        if (isatty(STDIN_FILENO))
            write(STDOUT_FILENO, "($) ", 4);

        read = getline(&line, &len, stdin);
        if (read == -1)
            break;

        count++;
        status = execute_command(line, argv[0], env, count);
    }

    free(line);
    return status;
}

