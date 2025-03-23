#include "../includes/game.h"
#include "../includes/map.h"
#include "../includes/character.h"
#include "../includes/view.h"


void display_map(t_map *map, void *mlx, void *win, void *player_img, void *wall_img, void *collectible_img) {
    for (int i = 0; i < map->height; i++) {
        for (int j = 0; j < map->width; j++) {
            int x = j * 64;
            int y = i * 64;

            if (map->data[i][j] == 'P') {
                mlx_put_image_to_window(mlx, win, player_img, x, y);
            } else if (map->data[i][j] == '1') {
                mlx_put_image_to_window(mlx, win, wall_img, x, y);
            } else if (map->data[i][j] == 'C') {
                mlx_put_image_to_window(mlx, win, collectible_img, x, y);
            }
        }
    }
}

