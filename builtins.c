#include "shell.h"

/* تنفيذ built-in exit باستخدام آخر حالة خروج */
void handle_exit(void)
{
    exit(last_status);
}

/* تنفيذ built-in env */
void handle_env(void)
{
    int i;

    for (i = 0; environ[i]; i++)
    {
        write(STDOUT_FILENO, environ[i], strlen(environ[i]));
        write(STDOUT_FILENO, "\n", 1);
    }
}

