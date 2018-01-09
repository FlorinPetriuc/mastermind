#include "main.h"

int main(void)
{
    char *rows;

    int _rows;

    itf_init();

    rows = itf_ask("Number of rows:");
    if(rows == NULL)
    {
        itf_error("Error reading the number of rows");

        return 1;
    }

    if(sscanf(rows, "%d", &_rows) != 1)
    {
        free(rows);

        itf_error("Invalid number of rows");

        return 1;
    }

    itf_clear();

    return 0;
}