#include "../includes/pacman.h"

void	loop_time(t_game *game)
{
	game->time->current_time = clock();
	game->time->elapsed_time = game->time->current_time - game->time->previous_time;
	game->time->previous_time = game->time->current_time;
	game->time->lag += game->time->elapsed_time;
	// printf("CLOCK: %i, %i\n", game->time->current_time, game->time->lag);
	while (game->time->lag >= (1000000 / 60))
	{
		printf("\033[31mLAG: %i\033[0m\n", game->time->lag);
		game->time->lag -= (1000000 / 60);
	}
	
}