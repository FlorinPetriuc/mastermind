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

void game_print(struct mastermind_game *game);

#endif