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
	//int			gost_collision;
	int			lifes[2];
	/*
	t_entity	*player;
	t_entity	*blinky;
	t_entity	*inky;
	t_entity	*pinky;
	t_entity	*clyde;
	*/
	t_map		*map;

	map = game->map;
	tm = game->time;
	/*
	player = game->entities->player;
	blinky = game->entities->blinky;
	pinky = game->entities->pinky;
	inky = game->entities->inky;
	clyde = game->entities->clyde;
	*/
	lifes[0] = count_lifes_gosts(*game->entities);
	tm->current_time = clock();
	tm->elapsed_time = tm->current_time - tm->previous_time;
	tm->previous_time = tm->current_time;
	tm->lag += tm->elapsed_time;
	while (tm->lag >= (1000000 / FRAME_RATE))
	{
		/*
		gost_collision = check_life_player(game->entities);
		if (tm->loop_anim % (FRAME_RATE / (FRAME_RATE / 60)) == 0)
		{
			choise_direction_ia(*map, pinky);
			choise_direction_ia(*map, inky);
			choise_direction_ia(*map, blinky);
			choise_direction_ia(*map, clyde);
		}
		*/
		if (tm->loop_anim % (FRAME_RATE / (FRAME_RATE / 2)) == 0)
		{
			/*
			if (gost_collision && !game->super_gomme)
				ft_close(game);
			move_entity(*game->window, *map, pinky, map->sprites->black);
			move_entity(*game->window, *map, blinky, map->sprites->black);
			move_entity(*game->window, *map, clyde, map->sprites->black);
			move_entity(*game->window, *map, inky, map->sprites->black);
			move_entity(*game->window, *map, player, map->sprites->black);
			//anim_player(*game->window, player);
			anim_gost(*game->window, pinky, game->super_gomme);
			anim_gost(*game->window, blinky, game->super_gomme);
			anim_gost(*game->window, inky, game->super_gomme);
			anim_gost(*game->window, clyde, game->super_gomme);
			*/
		}
		tm->loop_anim++;
		if (tm->loop_anim > (FRAME_RATE - 1))
			tm->loop_anim = 0;
		tm->lag -= (1000000 / FRAME_RATE);
	}
	return (0);
}

int	count_lifes_gosts(t_entities entities)
{
	int	lifes;

	lifes = entities.blinky->life + entities.clyde->life;
	lifes += entities.inky->life + entities.pinky->life;
	return (lifes);
}
