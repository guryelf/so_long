#include "../includes/character.h"
#include "../includes/game.h"

void load_character(t_character *character, void *mlx)
{
    character->frames[0] = mlx_xpm_file_to_image(mlx, "assets/ersoy/frame1.xpm", &(int){0}, &(int){0});
    character->frames[1] = mlx_xpm_file_to_image(mlx, "assets/ersoy/frame2.xpm", &(int){0}, &(int){0});
    character->x = 100;
    character->y = 100;
    character->current_frame = 0;
    character->frame_delay = 30000;
    character->frame_counter = 0;
}

void update_character(t_character *character)
{
    character->frame_counter++;
    if (character->frame_counter >= character->frame_delay)
    {
        character->current_frame = (character->current_frame + 1) % 2;  // Assuming 2 frames
        character->frame_counter = 0;
    }
}

void move_character(t_character *character, int dx, int dy)
{
    character->x += dx;
    character->y += dy;

  if (key == 'w') move_character(&game->character, 0, -1);  // Move up
if (key == 's') move_character(&game->character, 0, 1);   // Move down
if (key == 'a') move_character(&game->character, -1, 0);  // Move left
if (key == 'd') move_character(&game->character, 1, 0);   // Move right

}
