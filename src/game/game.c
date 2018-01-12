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

struct mastermind_game *game_init(const int rows, const int variations, const int *code)
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

    if(code)
    {
        memcpy(ret->code, code, 4 * sizeof(int));
    }
    else
    {
        ret->code[0] = rand() % variations;
        ret->code[1] = rand() % variations;
        ret->code[2] = rand() % variations;
        ret->code[3] = rand() % variations;
    }

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
    if(game->win)
    {
        return 1;
    }

    if(game->crt_row < game->total_rows)
    {
        return 0;
    }

    return 1;
}

static int get_full_matches(const int *code, const int *input)
{
    int i;
    int ret = 0;

    for(i = 0; i < 4; ++i)
    {
        if(code[i] != input[i])
        {
            continue;
        }

        ++ret;
    }

    return ret;
}

static int get_color_matches(const int *code, const int *input)
{
    int i;
    int j;
    int ret = 0;

    int _code[4];

    memcpy(_code, code, 4 * sizeof(int));

    for(i = 0; i < 4; ++i)
    {
        if(code[i] == input[i])
        {
            //we counted the current input as full match
            continue;
        }

        for(j = 0; j < 4; ++j)
        {
            if(code[j] == input[j])
            {
                //we counted the current input as full match
                continue;
            }

            if(input[i] != _code[j])
            {
                continue;
            }

            //we mark code[j] so we don't count the same color twice
            _code[j] = -1;

            ++ret;

            break;
        }
    }

    return ret;
}

void game_iterate(struct mastermind_game *game, const int *input,
                        int *full_matches, int *color_matches)
{
    ++game->crt_row;

    *full_matches = get_full_matches(game->code, input);
    if(*full_matches == 4)
    {
        *color_matches = 0;

        game->win = 1;

        return;
    }

    *color_matches = get_color_matches(game->code, input);
}

int game_input_sanity_check(struct mastermind_game *game, const int *input)
{
    int i;

    for(i = 0; i < 4; ++i)
    {
        if(input[i] >= game->variations)
        {
            return 0;
        }

        if(input[i] < 0)
        {
            return 0;
        }
    }

    return 1;
}