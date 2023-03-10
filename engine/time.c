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
		// printf("\033[31mLAG: %i, \033[32m%i\033[0m\n", game->time->lag, (game->time->current_time % 1000000) % 2);
		printf("%i => %i\n", game->time->loop_anim, game->time->loop_anim % (60 / 1));
		if (game->time->loop_anim % (60 / 1) == 0)
		{

			printf("\033[31mMA BITE !\033[0m\n");
		}
		game->time->loop_anim++;
		if (game->time->loop_anim > 59)
			game->time->loop_anim = 0;
		game->time->lag -= (1000000 / 60);
	}
	
}