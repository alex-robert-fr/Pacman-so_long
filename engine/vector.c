/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alrobert <alrobert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 00:33:51 by alrobert          #+#    #+#             */
/*   Updated: 2023/03/28 00:34:22 by alrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pacman.h"

t_vector	v_zero(void)
{
	t_vector	vector;

	vector.x = 0;
	vector.y = 0;
	return (vector);
}

t_vector	v_init(int x, int y)
{
	t_vector	vector;

	vector.x = x;
	vector.y = y;
	return (vector);
}
