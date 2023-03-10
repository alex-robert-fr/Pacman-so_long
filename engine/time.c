#include "../includes/pacman.h"

void	loop_time(t_game *game)
{
	game->time->current_time = clock();
	game->time->elapsed_time = game->time->current_time - game->time->previous_time;
	game->time->previous_time = game->time->current_time;
	game->time->lag += game->time->elapsed_time;
	while (game->time->lag >= (1000000 / 60))
	{
		printf("%i => %i\n", game->time->loop_anim, game->time->loop_anim % (60 / 10));
		if (game->time->loop_anim % (60 / 10) == 0)
		{
			anim_gost(*game->window, game->entities->blinky);
			anim_gost(*game->window, game->entities->inky);
			printf("\033[31mMA BITE !\033[0m\n");
		}
		game->time->loop_anim++;
		if (game->time->loop_anim > 59)
			game->time->loop_anim = 0;
		game->time->lag -= (1000000 / 60);
	}
	
}