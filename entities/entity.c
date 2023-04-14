/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entity.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alrobert <alrobert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 14:10:55 by alrobert          #+#    #+#             */
/*   Updated: 2023/03/29 16:46:05 by alrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <math.h>
#include <stdlib.h>
#include "ft_printf.h"
#include "pacman.h"

void	*set_spawn_entity(t_window win, t_entity *entity, t_elements elements)
{
	int	s;
	int	pos_x;
	int	pos_y;

	s = 33;
	entity->position.x *= 24;
	entity->position.y *= 24;
	entity->direction = v_init(1, 0);
	pos_x = (entity->position.x - 5);
	pos_y = (entity->position.y - 5);
	if (elements == PLAYER)
	{
		entity->u_sprites.player = load_img(win, "assets/pacman_r_2.xpm", s, s);
		mlx_put_image_to_window(win.mlx, win.win, entity->u_sprites.player, pos_x, pos_y);
	}
	else
	{
		if (elements == BLINKY)
			entity->u_sprites.gost = load_img(win, "blinky_r_0.xpm", 24, 24);
		if (elements == INKY)
			entity->u_sprites.gost = load_img(win, "inky_r_0.xpm", 24, 24);
		if (elements == PINKY)
			entity->u_sprites.gost = load_img(win, "pinky_r_0.xpm", 24, 24);
		if (elements == CLYDE)
			entity->u_sprites.gost = load_img(win, "clyde_r_0.xpm", 24, 24);
	}
	return ((void*)1);
}

void	anim_gost(t_window window, t_entity *entity, int super_gomme)
{
	(void)window;
	(void)entity;
	(void)super_gomme;
	//int time_anim[3] = {2, 4, 6};
	//anim_move_gost(window, entity, time_anim, super_gomme);
}

void	anim_move_gost(t_window window, t_entity *entity)
{
	int	pos_x;
	int	pos_y;

	pos_x = (entity->position.x - 5);
	pos_y = (entity->position.y - 5);
	mlx_put_image_to_window(window.mlx, window.win, entity->u_sprites.gost, pos_x, pos_y);
}

void	anim_player(t_window window, t_entity *entity)
{
	int time_anim[4] = {2, 4, 6 ,8};
	anim_move_player(window, entity, time_anim);
}

void	anim_move_player(t_window window, t_entity *entity, int *img_time)
{
	int	pos_x;
	int	pos_y;

	(void)img_time;
	pos_x = (entity->position.x - 5);
	pos_y = (entity->position.y - 5);
	mlx_put_image_to_window(window.mlx, window.win, entity->u_sprites.player, pos_x, pos_y);
}

void	move_entity(t_window window, t_map map, t_entity *entity)//, t_sprite_map black_sprite
{
	(void)window;
	float	x_pos = entity->position.x / 24;
	float	y_pos = entity->position.y / 24;

	ft_printf("X: %i, Y: %i\n", entity->position.x, entity->position.y);
//	check_direction(map, entity);
	if (entity->direction.x > 0)
	{
		if (map.map[(int)y_pos][(int)x_pos + 1] == '1')
			entity->position.x += 0;
		else
			entity->position.x++;
//		mlx_put_image_to_window(window.mlx, window.win, black_sprite.original, (entity->position.x - 10), (entity->position.y - 5));

	}
	if (entity->direction.x < 0)
	{
		if (map.map[(int)y_pos][(int)ceilf(x_pos) - 1] == '1')
			entity->position.x -= 0;
		else
			entity->position.x++;
//		mlx_put_image_to_window(window.mlx, window.win, black_sprite.original, (entity->position.x + 28), (entity->position.y - 5));
	}
	if (entity->direction.y > 0)
	{
		if (map.map[(int)y_pos + 1][(int)x_pos] == '1')
			entity->position.y += 0;
		else
			entity->position.x++;
//		mlx_put_image_to_window(window.mlx, window.win, black_sprite.white, (entity->position.x - 5), (entity->position.y - 10));
	}
	if (entity->direction.y < 0)
	{
		if (map.map[(int)ceilf(y_pos) - 1][(int)x_pos] == '1')
			entity->position.y -= 0;
		else
			entity->position.x++;
//		mlx_put_image_to_window(window.mlx, window.win, black_sprite.white, (entity->position.x - 5), (entity->position.y + 28));
	}
}

void	go_left(t_entity *entity)
{
	entity->direction.x = -1;
	entity->direction.y = 0;
}

void	go_right(t_entity *entity)
{
	entity->direction.x = 1;
	entity->direction.y = 0;
}

void	go_top(t_entity *entity)
{
	entity->direction.x = 0;
	entity->direction.y = -1;
}

void	go_down(t_entity *entity)
{
	entity->direction.x = 0;
	entity->direction.y = 1;
}
