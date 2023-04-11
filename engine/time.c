/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alrobert <alrobert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 23:26:26 by alrobert          #+#    #+#             */
/*   Updated: 2023/03/28 00:30:40 by alrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <time.h>
#include "ft_printf.h"
#include "pacman.h"
#define FRAME_RATE 100

int	loop_time(t_game *game)
{
	t_time		*tm;
	int			gost_collision;
	int			count_combo;
	int			lifes[2];
	t_entity	*player;
	t_entity	*blinky;
	t_entity	*inky;
	t_entity	*pinky;
	t_entity	*clyde;
	t_map		*map;

	count_combo = 0;
	game->combo = 0;
	map = game->map;
	tm = game->time;
	player = game->entities->player;
	blinky = game->entities->blinky;
	pinky = game->entities->pinky;
	inky = game->entities->inky;
	clyde = game->entities->clyde;
	lifes[0] = count_lifes_gosts(*game->entities);
	tm->current_time = clock();
	tm->elapsed_time = tm->current_time - tm->previous_time;
	tm->previous_time = tm->current_time;
	tm->lag += tm->elapsed_time;
	while (tm->lag >= (1000000 / FRAME_RATE))
	{
		gost_collision = check_life_player(game->entities);
		if (tm->loop_anim % (FRAME_RATE / (FRAME_RATE / 60)) == 0)
		{
			if (game->super_gomme < 10 && game->super_gomme != 0)
			{
				ft_printf("Time: %i\n", game->super_gomme);
				if (game->super_gomme == 9)
				{
					game->super_gomme = 0;
					blinky->life = 1;
					inky->life = 1;
					pinky->life = 1;
					clyde->life = 1;
				}
				else
					game->super_gomme++;
			}
		}
		if (tm->loop_anim % (FRAME_RATE / (FRAME_RATE / 60)) == 0)
		{
			choise_direction_ia(*map, pinky);
			choise_direction_ia(*map, inky);
			choise_direction_ia(*map, blinky);
			choise_direction_ia(*map, clyde);
		}
		if (tm->loop_anim % (FRAME_RATE / (FRAME_RATE / 2)) == 0)
		{
			display_ui(game);
			manage_pacgomme(game);
			if (game->super_gomme)
			{
				player->speed = 4;
				if (blinky->life == 1)
					blinky->speed = 2;
				if (inky->life == 1)
					inky->speed = 2;
				if (pinky->life == 1)
					pinky->speed = 2;
				if (clyde->life == 1)
					clyde->speed = 2;
				if (gost_collision == 1)
					gost_is_dead(blinky);
				if (gost_collision == 2)
					gost_is_dead(inky);
				if (gost_collision == 3)
					gost_is_dead(pinky);
				if (gost_collision == 4)
					gost_is_dead(clyde);
				if (gost_collision)
				{
					while (count_combo < 4)
					{
						if (count_combo == 0 && (game->entities))
							if (blinky->life == 0)
								game->combo++;
						if (count_combo == 1)
							if (inky->life == 0)
								game->combo++;
						if (count_combo == 2)
							if (pinky->life == 0)
								game->combo++;
						if (count_combo == 3)
							if (clyde->life == 0)
								game->combo++;
						count_combo++;
					}
					lifes[1] = count_lifes_gosts(*game->entities);
					if (game->combo == 1 && (lifes[1] != lifes[0]))
						player->score += 200;
					if (game->combo == 2 && (lifes[1] != lifes[0]))
						player->score += 400;
					if (game->combo == 3 && (lifes[1] != lifes[0]))
						player->score += 800;
					if (game->combo == 4 && (lifes[1] != lifes[0]))
						player->score += 1600;
				}
			}
			else if (gost_collision && !game->super_gomme)
				ft_close(game);
			else if (!game->super_gomme)
			{
				blinky->speed = 4;
				inky->speed = 4;
				pinky->speed = 4;
				clyde->speed = 4;
			}
			get_point(game, map, player);
			move_entity(*game->window, *map, pinky, map->sprites->black);
			move_entity(*game->window, *map, blinky, map->sprites->black);
			move_entity(*game->window, *map, clyde, map->sprites->black);
			move_entity(*game->window, *map, inky, map->sprites->black);
			move_entity(*game->window, *map, player, map->sprites->black);
			anim_player(*game->window, player);
			anim_gost(*game->window, pinky, game->super_gomme);
			anim_gost(*game->window, blinky, game->super_gomme);
			anim_gost(*game->window, inky, game->super_gomme);
			anim_gost(*game->window, clyde, game->super_gomme);
		}
		tm->loop_anim++;
		if (tm->loop_anim > (FRAME_RATE - 1))
			tm->loop_anim = 0;
		tm->lag -= (1000000 / FRAME_RATE);
	}
	game->entities->player->speed = 4;
	return (0);
}

int	count_lifes_gosts(t_entities entities)
{
	int	lifes;

	lifes = entities.blinky->life + entities.clyde->life;
	lifes += entities.inky->life + entities.pinky->life;
	return (lifes);
}

void	gost_is_dead(t_entity *gost)
{
	gost->life = 0;
	gost->speed = 6;
}
