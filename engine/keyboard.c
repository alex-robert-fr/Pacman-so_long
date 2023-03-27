/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alrobert <alrobert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 23:25:39 by alrobert          #+#    #+#             */
/*   Updated: 2023/03/28 00:49:30 by alrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pacman.h"

int	keyboard(int keycode, t_entity *player)
{
	if (keycode == 65361)
		go_left(player);
	if (keycode == 65362)
		go_top(player);
	if (keycode == 65363)
		go_right(player);
	if (keycode == 65364)
		go_down(player);
}
