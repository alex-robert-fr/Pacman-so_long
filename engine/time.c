#include "../includes/pacman.h"
#define FRAME_RATE 100

void	loop_time(t_game *game)
{
	int gost_collision;
	int	count_combo;
	int lifes;

	count_combo = 0;
	game->combo = 0;
	lifes = game->entities->blinky->life + game->entities->inky->life + game->entities->pinky->life + game->entities->clyde->life;
	game->time->current_time = clock();
	game->time->elapsed_time = game->time->current_time - game->time->previous_time;
	game->time->previous_time = game->time->current_time;
	game->time->lag += game->time->elapsed_time;
	while (game->time->lag >= (1000000 / FRAME_RATE))
	{
		gost_collision = check_life_player(game->entities);
		if (game->time->loop_anim % (FRAME_RATE / (FRAME_RATE / 60)) == 0)
		{
			if (game->super_gomme < 10 && game->super_gomme != 0)
			{
				printf("Time: %i\n", game->super_gomme);
				if (game->super_gomme == 9)
				{
					game->super_gomme = 0;
					game->entities->blinky->life = 1;
					game->entities->inky->life = 1;
					game->entities->pinky->life = 1;
					game->entities->clyde->life = 1;
				}
				else
					game->super_gomme++;
			}
		}
		if (game->time->loop_anim % (FRAME_RATE / (FRAME_RATE / 60)) == 0)
		{
			choise_direction_ia(*game->map, game->entities->pinky);
			choise_direction_ia(*game->map, game->entities->inky);
			choise_direction_ia(*game->map, game->entities->blinky);
			choise_direction_ia(*game->map, game->entities->clyde);
		}
		if (game->time->loop_anim % (FRAME_RATE / (FRAME_RATE / 2)) == 0)
		{
			display_ui(game);

			// printf("Player: [%f, %f]\n", game->entities->player->position.x, game->entities->player->position.y);
			// printf("Pinky: [%f, %f]\n", game->entities->pinky->position.x / 24, game->entities->pinky->position.y / 24);
			manage_pacgomme(game);
			if (game->super_gomme)
			{
				if (gost_collision == 1)
					game->entities->blinky->life = 0;
				if (gost_collision == 2)
					game->entities->inky->life = 0;
				if (gost_collision == 3)
					game->entities->pinky->life = 0;
				if (gost_collision == 4)
					game->entities->clyde->life = 0;

				if (gost_collision)
				{
					while (count_combo < 4)
					{
						if (count_combo == 0 && (game->entities))
							if (game->entities->blinky->life == 0)
								game->combo++;
						if (count_combo == 1)
							if (game->entities->inky->life == 0)
								game->combo++;
						if (count_combo == 2)
							if (game->entities->pinky->life == 0)
								game->combo++;
						if (count_combo == 3)
							if (game->entities->clyde->life == 0)
								game->combo++;
						count_combo++;
					}
					
					// printf("Combo: %i ====>> %i | GOST COLLISION %i | %i\n", game->combo, game->entities->player->score, game->gost_collision, gost_collision);
					if (game->combo == 1 && ((game->entities->blinky->life + game->entities->inky->life + game->entities->pinky->life + game->entities->clyde->life) != lifes))
					{
						game->entities->player->score += 200;
						printf("+200 -----> %i\n", game->entities->player->score);
					}
					if (game->combo == 2 && ((game->entities->blinky->life + game->entities->inky->life + game->entities->pinky->life + game->entities->clyde->life) != lifes))
					{
						game->entities->player->score += 400;
						printf("+400 -----> %i\n", game->entities->player->score);
					}
					if (game->combo == 3 && ((game->entities->blinky->life + game->entities->inky->life + game->entities->pinky->life + game->entities->clyde->life) != lifes))
					{
						game->entities->player->score += 800;
						printf("+800 -----> %i\n", game->entities->player->score);
					}
					if (game->combo == 4 && ((game->entities->blinky->life + game->entities->inky->life + game->entities->pinky->life + game->entities->clyde->life) != lifes))
					{
						game->entities->player->score += 1600;
						printf("+1600 -----> %i\n", game->entities->player->score);
					}
				}
			}
			else if (gost_collision && !game->super_gomme)
				ft_close(game);
			get_point(game, game->map, game->entities->player);
			move_entity(*game->window, *game->map, game->entities->pinky, game->map->sprites->black);
			move_entity(*game->window, *game->map, game->entities->blinky, game->map->sprites->black);
			move_entity(*game->window, *game->map, game->entities->clyde, game->map->sprites->black);
			move_entity(*game->window, *game->map, game->entities->inky, game->map->sprites->black);
			move_entity(*game->window, *game->map, game->entities->player, game->map->sprites->black);
			anim_player(*game->window, game->entities->player);
			anim_gost(*game->window, game->entities->pinky, game->super_gomme);
			anim_gost(*game->window, game->entities->blinky, game->super_gomme);
			anim_gost(*game->window, game->entities->inky, game->super_gomme);
			anim_gost(*game->window, game->entities->clyde, game->super_gomme);
		}
		game->time->loop_anim++;
		if (game->time->loop_anim > (FRAME_RATE - 1))
			game->time->loop_anim = 0;
		game->time->lag -= (1000000 / FRAME_RATE);
	}
	game->entities->player->speed = 4;
}
