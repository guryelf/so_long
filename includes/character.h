#ifndef CHARACTER_H
#define CHARACTER_H

#include "../minilibx-linux/mlx.h"


typedef struct s_character
{
    void *frames[2];
    int x;
    int y;
    int current_frame;
    int frame_delay;
    int frame_counter;
} t_character;

void load_character(t_character *character, void *mlx);
void update_character(t_character *character);
void move_character(t_character *character, int dx, int dy);

#endif
