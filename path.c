#include <sys/stat.h>
#include "shell.h"


char *find_path(char *command, char **env)
{
    int i;
    char *path_env;
    char *path_dup;
    char *dir;
    char *fullpath;
    struct stat st;

    if (strchr(command, '/'))
    {
        if (stat(command, &st) == 0)
            return strdup(command);
        else
            return NULL;
    }

    path_env = NULL;
    for (i = 0; env[i]; i++)
    {
        if (strncmp(env[i], "PATH=", 5) == 0)
        {
            path_env = env[i] + 5;
            break;
        }
    }

    if (!path_env)
        return NULL;

    path_dup = strdup(path_env);
    dir = strtok(path_dup, ":");
    while (dir)
    {
        fullpath = malloc(strlen(dir) + strlen(command) + 2);
        sprintf(fullpath, "%s/%s", dir, command);
        if (stat(fullpath, &st) == 0)
        {
            free(path_dup);
            return fullpath;
        }
        free(fullpath);
        dir = strtok(NULL, ":");
    }

    free(path_dup);
    return NULL;
}

