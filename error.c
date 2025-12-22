#include "shell.h"

void print_error(char *prog, char *cmd, int count)
{
    char buffer[1024];

    /* صياغة الرسالة */
    sprintf(buffer, "%s: %d: %s: not found\n", prog, count, cmd);

    /* اطبع على stderr */
    write(STDERR_FILENO, buffer, strlen(buffer));
}

