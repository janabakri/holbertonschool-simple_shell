#include "shell.h"

void handle_exit(void)
{
    exit(last_status);  /* يخرج باستخدام آخر حالة خروج */
}

