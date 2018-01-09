#ifndef _GAME_H_
#define _GAME_H_

struct mastermind_game
{
    int crt_row;
    int total_rows;
    int variations;

    int code[4];
};

struct mastermind_game *game_init(const int rows, const int variations);
void game_free(struct mastermind_game *game);

void game_print(struct mastermind_game *game);

#endif