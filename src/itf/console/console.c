#include "../../main.h"

void itf_init()
{
    printf("\033[H\033[J");
}

void itf_clear()
{
    printf("\033[H\033[J");
}

char *itf_ask(const char *pattern, ...)
{
    va_list args;

    size_t len = 0;
    size_t _len = 0;

    char *ret = NULL;

    va_start(args, pattern);
    vprintf(pattern, args);
    va_end(args);

    len = getline(&ret, &_len, stdin);
    if(len > 0)
    {
        return ret;
    }

    if(ret)
    {
        free(ret);
    }

    return NULL;
}

void itf_error(const char *pattern, ...)
{
    va_list args;

    va_start(args, pattern);
    vprintf(pattern, args);
    va_end(args);
}

void itf_show(const char *pattern, ...)
{
    va_list args;

    va_start(args, pattern);
    vprintf(pattern, args);
    va_end(args);
}