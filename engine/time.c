#include "../includes/pacman.h"
#define FRAME_RATE 100

void	loop_time(t_game *game)
{
	game->time->current_time = clock();
	game->time->elapsed_time = game->time->current_time - game->time->previous_time;
	game->time->previous_time = game->time->current_time;
	game->time->lag += game->time->elapsed_time;
	while (game->time->lag >= (1000000 / FRAME_RATE))
	{
		if (game->time->loop_anim % (FRAME_RATE / (FRAME_RATE / 60)) == 0)
		{
			choise_direction_ia(*game->map, game->entities->pinky);
			choise_direction_ia(*game->map, game->entities->inky);
			choise_direction_ia(*game->map, game->entities->blinky);
			choise_direction_ia(*game->map, game->entities->clyde);
		}
		if (game->time->loop_anim % (FRAME_RATE / (FRAME_RATE / 2)) == 0)
		{
			// printf("Player: [%f, %f]\n", game->entities->player->position.x, game->entities->player->position.y);
			// printf("Pinky: [%f, %f]\n", game->entities->pinky->position.x / 24, game->entities->pinky->position.y / 24);
			
			move_entity(*game->window, *game->map, game->entities->pinky, game->map->sprites->black);
			move_entity(*game->window, *game->map, game->entities->blinky, game->map->sprites->black);
			move_entity(*game->window, *game->map, game->entities->clyde, game->map->sprites->black);
			move_entity(*game->window, *game->map, game->entities->inky, game->map->sprites->black);
			move_entity(*game->window, *game->map, game->entities->player, game->map->sprites->black);
			anim_player(*game->window, game->entities->player);
			anim_gost(*game->window, game->entities->pinky);
			anim_gost(*game->window, game->entities->blinky);
			anim_gost(*game->window, game->entities->inky);
			anim_gost(*game->window, game->entities->clyde);
		}
		game->time->loop_anim++;
		if (game->time->loop_anim > (FRAME_RATE - 1))
			game->time->loop_anim = 0;
		game->time->lag -= (1000000 / FRAME_RATE);
	}
}
