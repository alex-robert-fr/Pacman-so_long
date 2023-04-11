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
#include "pacman.h"

void	*set_spawn_entity(t_window win, t_entity *entity, t_elements elements)
{
	int	s;
	int	pos_x;
	int	pos_y;

	s = 33;
	entity->score = 0;
	entity->position.x *= 24;
	entity->position.y *= 24;
	entity->direction = v_init(1, 0);
	entity->next_direction = v_init(0, 0);
	pos_x = (entity->position.x - 5);
	pos_y = (entity->position.y - 5);
	if (elements == PLAYER)
	{
		entity->speed = 0;
		import_imgs_player(win, entity->u_sprites.player, s);
		mlx_put_image_to_window(win.mlx, win.win, entity->u_sprites.player->right[1], pos_x, pos_y);
	}
	else
	{
		entity->speed = 4;
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
	int time_anim[3] = {2, 4, 6};
	anim_move_gost(window, entity, time_anim, super_gomme);
}

void	anim_move_gost(t_window window, t_entity *entity, int *img_time, int super_gomme)
{
	int	pos_x;
	int	pos_y;

	pos_x = (entity->position.x - 5);
	pos_y = (entity->position.y - 5);
	if (entity->index_anim < img_time[0])
	{
		if (entity->direction.x > 0)
		{
			if (!entity->life)
				mlx_put_image_to_window(window.mlx, window.win, entity->u_sprites.gost, pos_x, pos_y);
			else if (super_gomme)
				mlx_put_image_to_window(window.mlx, window.win, entity->u_sprites.gost, pos_x, pos_y);
			else
				mlx_put_image_to_window(window.mlx, window.win, entity->u_sprites.gost, pos_x, pos_y);
		}
		if (entity->direction.x < 0)
		{
			if (!entity->life)
				mlx_put_image_to_window(window.mlx, window.win, entity->u_sprites.gost, pos_x, pos_y);
			else if (super_gomme)
				mlx_put_image_to_window(window.mlx, window.win, entity->u_sprites.gost, pos_x, pos_y);
			else
				mlx_put_image_to_window(window.mlx, window.win, entity->u_sprites.gost, pos_x, pos_y);
		}
		if (entity->direction.y > 0)
		{
			if (!entity->life)
				mlx_put_image_to_window(window.mlx, window.win, entity->u_sprites.gost, pos_x, pos_y);
			else if (super_gomme)
				mlx_put_image_to_window(window.mlx, window.win, entity->u_sprites.gost, pos_x, pos_y);
			else
				mlx_put_image_to_window(window.mlx, window.win, entity->u_sprites.gost, pos_x, pos_y);
		}
		if (entity->direction.y < 0)
		{
			if (!entity->life)
				mlx_put_image_to_window(window.mlx, window.win, entity->u_sprites.gost, pos_x, pos_y);
			else if (super_gomme)
				mlx_put_image_to_window(window.mlx, window.win, entity->u_sprites.gost, pos_x, pos_y);
			else
				mlx_put_image_to_window(window.mlx, window.win, entity->u_sprites.gost, pos_x, pos_y);
		}
		entity->index_anim++;
	}
	else if (entity->index_anim < img_time[1])
	{
		if (entity->direction.x > 0)
		{
			if (!entity->life)
				mlx_put_image_to_window(window.mlx, window.win, entity->u_sprites.gost, pos_x, pos_y);
			else if (super_gomme)
				mlx_put_image_to_window(window.mlx, window.win, entity->u_sprites.gost, pos_x, pos_y);
			else
				mlx_put_image_to_window(window.mlx, window.win, entity->u_sprites.gost, pos_x, pos_y);
		}
		if (entity->direction.x < 0)
		{
			if (!entity->life)
				mlx_put_image_to_window(window.mlx, window.win, entity->u_sprites.gost, pos_x, pos_y);
			else if (super_gomme)
				mlx_put_image_to_window(window.mlx, window.win, entity->u_sprites.gost, pos_x, pos_y);
			else
				mlx_put_image_to_window(window.mlx, window.win, entity->u_sprites.gost, pos_x, pos_y);
		}
		if (entity->direction.y > 0)
		{
			if (!entity->life)
				mlx_put_image_to_window(window.mlx, window.win, entity->u_sprites.gost, pos_x, pos_y);
			else if (super_gomme)
				mlx_put_image_to_window(window.mlx, window.win, entity->u_sprites.gost, pos_x, pos_y);
			else
				mlx_put_image_to_window(window.mlx, window.win, entity->u_sprites.gost, pos_x, pos_y);
		}
		if (entity->direction.y < 0)
		{
			if (!entity->life)
				mlx_put_image_to_window(window.mlx, window.win, entity->u_sprites.gost, pos_x, pos_y);
			else if (super_gomme)
				mlx_put_image_to_window(window.mlx, window.win, entity->u_sprites.gost, pos_x, pos_y);
			else
				mlx_put_image_to_window(window.mlx, window.win, entity->u_sprites.gost, pos_x, pos_y);
		}
		entity->index_anim++;
	}
	else if (entity->index_anim < img_time[2])
	{
		if (entity->direction.x > 0)
		{
			if (!entity->life)
				mlx_put_image_to_window(window.mlx, window.win, entity->u_sprites.gost, pos_x, pos_y);
			else if (super_gomme)
				mlx_put_image_to_window(window.mlx, window.win, entity->u_sprites.gost, pos_x, pos_y);
			else
				mlx_put_image_to_window(window.mlx, window.win, entity->u_sprites.gost, pos_x, pos_y);
		}
		if (entity->direction.x < 0)
		{
			if (!entity->life)
				mlx_put_image_to_window(window.mlx, window.win, entity->u_sprites.gost, pos_x, pos_y);
			else if (super_gomme)
				mlx_put_image_to_window(window.mlx, window.win, entity->u_sprites.gost, pos_x, pos_y);
			else
				mlx_put_image_to_window(window.mlx, window.win, entity->u_sprites.gost, pos_x, pos_y);
		}
		if (entity->direction.y > 0)
		{
			if (!entity->life)
				mlx_put_image_to_window(window.mlx, window.win, entity->u_sprites.gost, pos_x, pos_y);
			else if (super_gomme)
				mlx_put_image_to_window(window.mlx, window.win, entity->u_sprites.gost, pos_x, pos_y);
			else
				mlx_put_image_to_window(window.mlx, window.win, entity->u_sprites.gost, pos_x, pos_y);
		}
		if (entity->direction.y < 0)
		{
			if (!entity->life)
				mlx_put_image_to_window(window.mlx, window.win, entity->u_sprites.gost, pos_x, pos_y);
			else if (super_gomme)
				mlx_put_image_to_window(window.mlx, window.win, entity->u_sprites.gost, pos_x, pos_y);
			else
				mlx_put_image_to_window(window.mlx, window.win, entity->u_sprites.gost, pos_x, pos_y);
		}
		entity->index_anim = 0;
	}
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


	pos_x = (entity->position.x - 5);
	pos_y = (entity->position.y - 5);
	if (entity->index_anim < img_time[0])
	{
		mlx_put_image_to_window(window.mlx, window.win, entity->u_sprites.player->original, pos_x, pos_y);
		entity->index_anim++;
	}
	else if (entity->index_anim < img_time[1])
	{
		if (entity->direction.x > 0)
			mlx_put_image_to_window(window.mlx, window.win, entity->u_sprites.player->right[0], pos_x, pos_y);
		if (entity->direction.x < 0)
			mlx_put_image_to_window(window.mlx, window.win, entity->u_sprites.player->left[0], pos_x, pos_y);
		if (entity->direction.y > 0)
			mlx_put_image_to_window(window.mlx, window.win, entity->u_sprites.player->bottom[0], pos_x, pos_y);
		if (entity->direction.y < 0)
			mlx_put_image_to_window(window.mlx, window.win, entity->u_sprites.player->top[0], pos_x, pos_y);
		entity->index_anim++;
	}
	else if (entity->index_anim < img_time[2])
	{
		if (entity->direction.x > 0)
			mlx_put_image_to_window(window.mlx, window.win, entity->u_sprites.player->right[1], pos_x, pos_y);
		if (entity->direction.x < 0)
			mlx_put_image_to_window(window.mlx, window.win, entity->u_sprites.player->left[1], pos_x, pos_y);
		if (entity->direction.y > 0)
			mlx_put_image_to_window(window.mlx, window.win, entity->u_sprites.player->bottom[1], pos_x, pos_y);
		if (entity->direction.y < 0)
			mlx_put_image_to_window(window.mlx, window.win, entity->u_sprites.player->top[1], pos_x, pos_y);
		entity->index_anim++;
	}
	else if (entity->index_anim < img_time[3])
	{
		if (entity->direction.x > 0)
			mlx_put_image_to_window(window.mlx, window.win, entity->u_sprites.player->right[2], pos_x, pos_y);
		if (entity->direction.x < 0)
			mlx_put_image_to_window(window.mlx, window.win, entity->u_sprites.player->left[2], pos_x, pos_y);
		if (entity->direction.y > 0)
			mlx_put_image_to_window(window.mlx, window.win, entity->u_sprites.player->bottom[2], pos_x, pos_y);
		if (entity->direction.y < 0)
			mlx_put_image_to_window(window.mlx, window.win, entity->u_sprites.player->top[2], pos_x, pos_y);
		entity->index_anim++;
	}
	else if (entity->index_anim < (img_time[3] + (img_time[3] - img_time[2])))
	{
		if (entity->direction.x > 0)
			mlx_put_image_to_window(window.mlx, window.win, entity->u_sprites.player->right[1], pos_x, pos_y);
		if (entity->direction.x < 0)
			mlx_put_image_to_window(window.mlx, window.win, entity->u_sprites.player->left[1], pos_x, pos_y);
		if (entity->direction.y > 0)
			mlx_put_image_to_window(window.mlx, window.win, entity->u_sprites.player->bottom[1], pos_x, pos_y);
		if (entity->direction.y < 0)
			mlx_put_image_to_window(window.mlx, window.win, entity->u_sprites.player->top[1], pos_x, pos_y);
		entity->index_anim++;
	}
	else if (entity->index_anim < (img_time[3] + (img_time[3] - img_time[1])))
	{
		if (entity->direction.x > 0)
			mlx_put_image_to_window(window.mlx, window.win, entity->u_sprites.player->right[0], pos_x, pos_y);
		if (entity->direction.x < 0)
			mlx_put_image_to_window(window.mlx, window.win, entity->u_sprites.player->left[0], pos_x, pos_y);
		if (entity->direction.y > 0)
			mlx_put_image_to_window(window.mlx, window.win, entity->u_sprites.player->bottom[0], pos_x, pos_y);
		if (entity->direction.y < 0)
			mlx_put_image_to_window(window.mlx, window.win, entity->u_sprites.player->top[0], pos_x, pos_y);
		entity->index_anim = 0;
	}
}

void	move_entity(t_window window, t_map map, t_entity *entity, t_sprite_map black_sprite)
{
	float	x_pos = entity->position.x / 24;
	float	y_pos = entity->position.y / 24;

	check_direction(map, entity);
	if (entity->direction.x > 0)
	{
		if (map.map[(int)y_pos][(int)x_pos + 1] == '1')
			entity->position.x += 0;
		else
			entity->position.x += entity->speed;
		mlx_put_image_to_window(window.mlx, window.win, black_sprite.original, (entity->position.x - 10), (entity->position.y - 5));

	}
	if (entity->direction.x < 0)
	{
		if (map.map[(int)y_pos][(int)ceilf(x_pos) - 1] == '1')
			entity->position.x -= 0;
		else
			entity->position.x -= entity->speed;
		mlx_put_image_to_window(window.mlx, window.win, black_sprite.original, (entity->position.x + 28), (entity->position.y - 5));
	}
	if (entity->direction.y > 0)
	{
		if (map.map[(int)y_pos + 1][(int)x_pos] == '1')
			entity->position.y += 0;
		else
			entity->position.y += entity->speed;
		mlx_put_image_to_window(window.mlx, window.win, black_sprite.white, (entity->position.x - 5), (entity->position.y - 10));
	}
	if (entity->direction.y < 0)
	{
		if (map.map[(int)ceilf(y_pos) - 1][(int)x_pos] == '1')
			entity->position.y -= 0;
		else
			entity->position.y -= entity->speed;
		mlx_put_image_to_window(window.mlx, window.win, black_sprite.white, (entity->position.x - 5), (entity->position.y + 28));
	}
}

void	*check_direction(t_map map, t_entity *entity)
{
	float	x_pos = entity->position.x / 24;
	float	y_pos = entity->position.y / 24;
	if (entity->next_direction.y > 0)
	{
		if ((map.map[(int)y_pos + 1][(int)x_pos] == '0' || map.map[(int)y_pos + 1][(int)x_pos] == 'x') && x_pos == ceilf(x_pos))
		{
			entity->direction.x = 0;
			entity->direction.y = 1;
		}
		if (map.map[(int)y_pos + 1][(int)x_pos] == '1' && x_pos == ceilf(x_pos))
			return (NULL);
		
	}
	if (entity->next_direction.y < 0)
	{
		if ((map.map[(int)y_pos - 1][(int)x_pos] == '0' || map.map[(int)y_pos - 1][(int)x_pos] == 'x') && x_pos == ceilf(x_pos))
		{
			entity->direction.x = 0;
			entity->direction.y = -1;
		}
		if (map.map[(int)y_pos - 1][(int)x_pos] == '1' && x_pos == ceilf(x_pos))
			return (NULL);
	}
	if (entity->next_direction.x > 0)
	{
		if ((map.map[(int)y_pos][(int)x_pos + 1] == '0' || map.map[(int)y_pos][(int)x_pos + 1] == 'x') && y_pos == ceilf(y_pos))
		{
			entity->direction.x = 1;
			entity->direction.y = 0;
		}
		if (map.map[(int)y_pos][(int)x_pos + 1] == '1' && y_pos == ceilf(y_pos))
			return (NULL);
	}
	if (entity->next_direction.x < 0)
	{
		if ((map.map[(int)y_pos][(int)x_pos - 1] == '0' || map.map[(int)y_pos][(int)x_pos - 1] == 'x') && y_pos == ceilf(y_pos))
		{
			entity->direction.x = -1;
			entity->direction.y = 0;
		}
		if (map.map[(int)y_pos][(int)x_pos - 1] == '1' && y_pos == ceilf(y_pos))
			return (NULL);
	}
	return ((void*)1);
}

void	go_left(t_entity *entity)
{
	entity->next_direction.x = -1;
	entity->next_direction.y = 0;
}

void	go_right(t_entity *entity)
{
	entity->next_direction.x = 1;
	entity->next_direction.y = 0;
}

void	go_top(t_entity *entity)
{
	entity->next_direction.x = 0;
	entity->next_direction.y = -1;
}

void	go_down(t_entity *entity)
{
	entity->next_direction.x = 0;
	entity->next_direction.y = 1;
}
