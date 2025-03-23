#ifndef VIEW
#define VIEW_H

#include "../includes/game.h"
#include "../includes/map.h"
#include "../includes/character.h"
#include "../includes/controller.h"

void draw_view(t_game *game, t_map *map, t_character *character, void *mlx, void *win);

#endif