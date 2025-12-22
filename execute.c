int execute_command(char *line, char *prog, char **env, int count)
{
    char **argv = split_line(line);
    char *path = find_path(argv[0], env);

    if (!path)
    {
        print_error(prog, argv[0], count);
        free_argv(argv);
        return 127;
    }

    pid_t pid = fork();
    int status;

    if (pid == 0)
    {
        execve(path, argv, env);
        print_error(prog, argv[0], count);
        exit(127);
    }
    else
    {
        waitpid(pid, &status, 0);
        free(path);
        free_argv(argv);
        if (WIFEXITED(status))
            return WEXITSTATUS(status);
    }

    return 0;
}

