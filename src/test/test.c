/*
 * Copyright (C) 2018 Florin Petriuc. All rights reserved.
 * Initial release: Florin Petriuc <petriuc.florin@gmail.com>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License version
 * 2 as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 */

#include "../main.h"

int test1()
{
    struct mastermind_game *game;

    int pegs[] = { 1, 2, 3, 4};
    int in[] = { 4, 3, 2, 1};
    int full_matches;
    int color_matches;

    game = game_init(6, 5, pegs);

    game_iterate(game, in, &full_matches, &color_matches);
    if(full_matches != 0 || color_matches != 4 || game->win != 0 || game->crt_row != 1 ||
       game->total_rows != 6 || game->variations != 5 || memcmp(game->code, pegs, 4 * sizeof(int)))
    {
        game_free(game);

        return -1;
    }

    game_free(game);

    return 0;
}

int test2()
{
    struct mastermind_game *game;

    int pegs[] = { 1, 2, 3, 4};
    int in[] = { 1, 2, 3, 4};
    int full_matches;
    int color_matches;

    game = game_init(6, 5, pegs);

    game_iterate(game, in, &full_matches, &color_matches);
    if(full_matches != 4 || color_matches != 0 || game->win != 1 || game->crt_row != 1 ||
       game->total_rows != 6 || game->variations != 5 || memcmp(game->code, pegs, 4 * sizeof(int)))
    {
        game_free(game);

        return -1;
    }

    game_free(game);

    return 0;
}

int test3()
{
    struct mastermind_game *game;

    int pegs[] = { 1, 1, 2, 3};
    int in[] = { 3, 1, 1, 1};
    int full_matches;
    int color_matches;

    game = game_init(6, 5, pegs);

    game_iterate(game, in, &full_matches, &color_matches);
    if(full_matches != 1 || color_matches != 2 || game->win != 0 || game->crt_row != 1 ||
       game->total_rows != 6 || game->variations != 5 || memcmp(game->code, pegs, 4 * sizeof(int)))
    {
        game_free(game);

        return -1;
    }

    game_free(game);

    return 0;
}

int main(void)
{
    itf_show("Tests starting\n");

    if(test1())
    {
        itf_show("Test 1 FAILED\n");
    }
    else
    {
        itf_show("Test 1 OK\n");
    }

    if(test2())
    {
        itf_show("Test 2 FAILED\n");
    }
    else
    {
        itf_show("Test 2 OK\n");
    }

    if(test3())
    {
        itf_show("Test 3 FAILED\n");
    }
    else
    {
        itf_show("Test 3 OK\n");
    }

    itf_show("Tests finished\n");

    return 0;
}