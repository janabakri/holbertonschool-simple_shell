#include "shell.h"

#define TOK_BUFSIZE 64
#define TOK_DELIM " \t\r\n\a"

char **split_line(char *line)
{
    int bufsize, pos;
    char **tokens;
    char *token;

    bufsize = TOK_BUFSIZE;
    pos = 0;
    tokens = malloc(bufsize * sizeof(char *));
    if (!tokens)
    {
        fprintf(stderr, "allocation error\n");
        exit(EXIT_FAILURE);
    }

    token = strtok(line, TOK_DELIM);
    while (token != NULL)
    {
        tokens[pos] = strdup(token);
        pos++;

        if (pos >= bufsize)
        {
            bufsize += TOK_BUFSIZE;
            tokens = realloc(tokens, bufsize * sizeof(char *));
            if (!tokens)
            {
                fprintf(stderr, "allocation error\n");
                exit(EXIT_FAILURE);
            }
        }

        token = strtok(NULL, TOK_DELIM);
    }
    tokens[pos] = NULL;
    return tokens;
}

