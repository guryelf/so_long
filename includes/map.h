#ifndef MAP_H
#define MAP_H
#include "../minilibx-linux/mlx.h"


#include "game.h"

typedef struct s_map {
    char data[MAP_HEIGHT][MAP_WIDTH];
    int width;
    int height;
    int collectibles;
    int player_x;
    int player_y;
} t_map;

int load_map(t_map *map, const char *filename);
int validate_map(t_map *map);
int check_surrounded_by_walls(t_map *map);
int check_valid_path(t_map *map);
int validate_components(t_map *map);

#endif