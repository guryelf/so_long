#include "../includes/game.h"
#include "../includes/controller.h"
#include "../includes/character.h"

void key_press(int key, t_game *game) {
    if (key == 65307) exit(0); // ESC to quit
    if (key == 'w') move_character(&game->character, 0, -1);  // Move up
    if (key == 's') move_character(&game->character, 0, 1);   // Move down
    if (key == 'a') move_character(&game->character, -1, 0);  // Move left
    if (key == 'd') move_character(&game->character, 1, 0);   // Move right
    
}