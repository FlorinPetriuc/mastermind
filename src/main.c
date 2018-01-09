#include "main.h"

int main(void)
{
    char *in;

    int rows;
    int variations;
    int pegs[4];
    int full_matches;
    int color_matches;

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

    if(variations < 2)
    {
        itf_error("The number of variations must be positive");

        return 1;
    }

    in = itf_ask("Code (leave empty for random):");
    if(in == NULL)
    {
        itf_error("Cannot read user code");

        return 1;
    }

    if(strcmp(in, "\n") == 0)
    {
        game = game_init(rows, variations, NULL);
    }
    else
    {
        if(sscanf(in, "%d %d %d %d", &pegs[0], &pegs[1], &pegs[2], &pegs[3]) != 4)
        {
            free(in);

            itf_error("Invalid input");

            return 1;
        }

        game = game_init(rows, variations, pegs);
    }

    free(in);

    if(game == NULL)
    {
        itf_error("Cannot instantiate game");

        return 1;
    }

    while(!game_over(game))
    {
        in = itf_ask("Pegs %d:", game->crt_row);
        if(in == NULL)
        {
            game_free(game);

            itf_error("Cannot read user input");

            return 1;
        }

        if(sscanf(in, "%d %d %d %d", &pegs[0], &pegs[1], &pegs[2], &pegs[3]) != 4)
        {
            free(in);

            itf_error("Invalid input");

            continue;
        }

        free(in);

        game_iterate(game, pegs, &full_matches, &color_matches);
        itf_show("Got %d black pegs and %d white pegs\n", full_matches, color_matches);
    }

    if(game->win)
    {
        itf_show("Game over: You won\n");
    }
    else
    {
        itf_show("Game over: You lost.\nCode was %d %d %d %d.\n",
                    game->code[0], game->code[1], game->code[2], game->code[3]);
    }

    game_free(game);

    return 0;
}