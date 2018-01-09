#include "main.h"

int main(void)
{
    char *rows;

    int _rows;

    itf_init();

    rows = itf_ask("Number of rows (12, 19, 8 or 6):");
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

    if(_rows != 12 && _rows != 10 && _rows != 8 && _rows != 6)
    {
        free(rows);

        itf_error("The number of rows can be 12, 10, 8 or 6");

        return 1;
    }

    itf_clear();

    return 0;
}