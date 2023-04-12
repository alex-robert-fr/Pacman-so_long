/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alrobert <alrobert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 14:08:59 by alrobert          #+#    #+#             */
/*   Updated: 2023/03/28 14:09:24 by alrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "pacman.h"

int	check_life_player(t_entities *entities)
{
	t_vector	player_pos;

	player_pos.x = ceilf(entities->player->position.x / 24);
	player_pos.y = ceilf(entities->player->position.y / 24);
	if (check_collision_with_gost(player_pos, entities->blinky->position))
		return (1);
	if (check_collision_with_gost(player_pos, entities->inky->position))
		return (2);
	if (check_collision_with_gost(player_pos, entities->pinky->position))
		return (3);
	if (check_collision_with_gost(player_pos, entities->clyde->position))
		return (4);
	return (0);
}

int	check_collision_with_gost(t_vector player_pos, t_vector pos)
{	
	if ((player_pos.x == (pos.x / 24) || player_pos.x == (pos.x / 24) + 1) \
		&& (player_pos.y == (pos.y / 24) || player_pos.y == (pos.y / 24) + 1))
		return (1);
	return (0);
}
