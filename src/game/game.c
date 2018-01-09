#include "../main.h"

struct mastermind_game *game_init(const int rows, const int variations)
{
    struct mastermind_game *ret;

    ret = malloc(sizeof(struct mastermind_game));
    if(ret == NULL)
    {
        return NULL;
    }

    ret->crt_row = 0;
    ret->total_rows = rows;
    ret->variations = variations;
    ret->win = 0;

    ret->code[0] = rand() % variations;
    ret->code[1] = rand() % variations;
    ret->code[2] = rand() % variations;
    ret->code[3] = rand() % variations;

    return ret;
}

void game_print(struct mastermind_game *game)
{
    itf_show("Game has %d rows, %d variations. Code is %d %d %d %d.", game->total_rows,
                                                                      game->variations,
                                                                      game->code[0],
                                                                      game->code[1],
                                                                      game->code[2],
                                                                      game->code[3]);
}

void game_free(struct mastermind_game *game)
{
    free(game);
}

int game_over(struct mastermind_game *game)
{
    if(game->crt_row < game->total_rows)
    {
        return 0;
    }

    return 1;
}

void game_iterate(struct mastermind_game *game, const int *input,
                        int *full_matches, int *color_matches)
{
    ++game->crt_row;

    *full_matches = 0;
    *color_matches = 0;
}