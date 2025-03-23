#include "../includes/game.h"

void init_game(t_game *game)
{
    game->x = 100;
    game->y = 100;
    game->current_frame = 0;
    game->frame_count = 2;
    game->frame_delay = 30000;
    game->frame_counter = 0;
    game->is_moving = 0;
}

int update_game_state(t_game *game)
{
    if (game->is_moving)
    {
        game->frame_counter++;
        if (game->frame_counter >= game->frame_delay)
        {
            game->current_frame = (game->current_frame + 1) % game->frame_count;
            game->frame_counter = 0;
        }
    }
    return 0;
}
