#ifndef GAME_H
#define GAME_H

#include "../minilibx-linux/mlx.h"

#define WIDTH 800
#define HEIGHT 600
#define CHAR_SIZE 50
#define MAP_WIDTH 10
#define MAP_HEIGHT 10

typedef struct s_game {
    int player_x;
    int player_y;
    int moves;
    char map[MAP_HEIGHT][MAP_WIDTH];
    int collectibles;
} t_game;

void init_game(t_game *game);
int update_game_state(t_game *game);

#endif
