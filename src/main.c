#include "game.h"
#include "view.h"
#include "controller.h"
#include "map.h"
#include <mlx.h>

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Error\nUsage: ./game <map_file.ber>\n");
        return 1;
    }

    t_map map;
    if (!load_map(&map, argv[1])) return 1;

    void *mlx = mlx_init();
    void *win = mlx_new_window(mlx, 640, 480, "Game");

    void *player_img = mlx_xpm_file_to_image(mlx, "player.xpm", &(int){64}, &(int){64});
    void *wall_img = mlx_xpm_file_to_image(mlx, "wall.xpm", &(int){64}, &(int){64});
    void *collectible_img = mlx_xpm_file_to_image(mlx, "collectible.xpm", &(int){64}, &(int){64});

    display_map(&map, mlx, win, player_img, wall_img, collectible_img);
    mlx_key_hook(win, key_press, &map);

    mlx_loop(mlx);

    return 0;
}
