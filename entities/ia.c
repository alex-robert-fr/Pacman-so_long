/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ia.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alrobert <alrobert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 00:35:39 by alrobert          #+#    #+#             */
/*   Updated: 2023/03/28 00:47:11 by alrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pacman.h"

void	*choise_direction_ia(t_map map, t_entity *entity)
{
	int		num;
	void	*check;

	check = 0;
	while (!check)
	{
		num = (rand() % (3 - 0 + 1)) + 0;
		if (!num)
			go_left(entity);
		if (num == 1)
			go_top(entity);
		if (num == 2)
			go_right(entity);
		if (num == 3)
			go_down(entity);
		if (!check_direction(map, entity))
			check = (void *) 0;
		else
			check = (void *) 1;
	}
}
