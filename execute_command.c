#include "main.h"

/**
 * execute_command - Execute a command
 * @args: Array of arguments (for future use)
 * @argv0: Program name
 * @line: Command line
 * @last_status: Last exit status
 *
 * Return: Exit status
 */
int execute_command(char **args, char *argv0, char *line, int last_status)
{
    pid_t pid;
    int status;
    char *full_cmd;
    char *cmd_args[] = {NULL, NULL};
    struct stat st;

    (void)args;
    (void)last_status;

    /* Check if command exists */
    if (access(line, X_OK) == 0 && stat(line, &st) == 0 && S_ISREG(st.st_mode))
    {
        full_cmd = line;
    }
    else
    {
        /* Try with /bin/ prefix */
        size_t len = strlen(line) + 6;
        full_cmd = malloc(len);
        if (full_cmd == NULL)
            return (1);
        
        snprintf(full_cmd, len, "/bin/%s", line);
        
        if (access(full_cmd, X_OK) != 0 || stat(full_cmd, &st) != 0 || !S_ISREG(st.st_mode))
        {
            free(full_cmd);
            full_cmd = NULL;
        }
    }

    if (full_cmd == NULL)
    {
        write(STDERR_FILENO, argv0, strlen(argv0));
        write(STDERR_FILENO, ": 1: ", 5);
        write(STDERR_FILENO, line, strlen(line));
        write(STDERR_FILENO, ": not found\n", 12);
        return (127);
    }

    cmd_args[0] = full_cmd;

    pid = fork();
    if (pid == 0)
    {
        /* Child process */
        if (execve(full_cmd, cmd_args, environ) == -1)
        {
            perror(argv0);
            if (full_cmd != line)
                free(full_cmd);
            _exit(127);
        }
    }
    else if (pid < 0)
    {
        /* Fork failed */
        perror("fork");
        if (full_cmd != line)
            free(full_cmd);
        return (1);
    }
    else
    {
        /* Parent process */
        waitpid(pid, &status, 0);
        if (full_cmd != line)
            free(full_cmd);
        
        if (WIFEXITED(status))
            return (WEXITSTATUS(status));
        return (1);
    }

    return (0);
}
