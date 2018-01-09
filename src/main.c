#include "main.h"

int main(void)
{
    char *in;

    int rows;
    int variations;

    struct mastermind_game *game;

    itf_init();

    in = itf_ask("Number of rows (12, 19, 8 or 6):");
    if(in == NULL)
    {
        itf_error("Error reading the number of rows");

        return 1;
    }

    if(sscanf(in, "%d", &rows) != 1)
    {
        free(in);

        itf_error("Invalid number of rows");

        return 1;
    }

    free(in);

    if(rows != 12 && rows != 10 && rows != 8 && rows != 6)
    {
        itf_error("The number of rows can be 12, 10, 8 or 6");

        return 1;
    }

    in = itf_ask("Number of variations:");
    if(in == NULL)
    {
        itf_error("Error reading the number of variations");

        return 1;
    }

    if(sscanf(in, "%d", &variations) != 1)
    {
        free(in);

        itf_error("Invalid number of variations");

        return 1;
    }

    free(in);

    game = game_init(rows, variations);
    if(game == NULL)
    {
        itf_error("Cannot instantiate game");

        return 1;
    }

    game_free(game);
    itf_clear();

    return 0;
}