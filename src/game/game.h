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

#ifndef _GAME_H_
#define _GAME_H_

struct mastermind_game
{
    int crt_row;
    int total_rows;
    int variations;
    int win;

    int code[4];
};

struct mastermind_game *game_init(const int rows, const int variations, const int *code);
void game_free(struct mastermind_game *game);
void game_iterate(struct mastermind_game *game, const int *input,
                            int *full_matches, int *color_matches);
int game_over(struct mastermind_game *game);
int game_input_sanity_check(struct mastermind_game *game, const int *input);

void game_print(struct mastermind_game *game);

#endif