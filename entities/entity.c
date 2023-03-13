#include "../includes/pacman.h"

void		*set_spawn_entity(t_window window, t_entity *entity, t_elements elements)
{
	int	size;

	size = 33;
	entity->score = 0;
	entity->position.x *= 24;
	entity->position.y *= 24;
	entity->direction = v_init(1, 0);
	entity->next_direction = v_init(0, 0);
	if (elements == PLAYER)
	{
		entity->speed = 3;
		entity->u_sprites.player->one = mlx_xpm_file_to_image(window.mlx, "assets/pacman_r_0.xpm", &size, &size);
		entity->u_sprites.player->two = mlx_xpm_file_to_image(window.mlx, "assets/pacman_r_1.xpm", &size, &size);
		entity->u_sprites.player->three = mlx_xpm_file_to_image(window.mlx, "assets/pacman_r_2.xpm", &size, &size);
		entity->u_sprites.player->four = mlx_xpm_file_to_image(window.mlx, "assets/pacman_r_3.xpm", &size, &size);
		
	}
	else if (elements == BLINKY)
	{
		entity->speed = 2;
		entity->u_sprites.gost->one.original = mlx_xpm_file_to_image(window.mlx, "assets/blinky_r_0.xpm", &size, &size);
		entity->u_sprites.gost->two.original = mlx_xpm_file_to_image(window.mlx, "assets/blinky_r_1.xpm", &size, &size);
		entity->u_sprites.gost->three.original = mlx_xpm_file_to_image(window.mlx, "assets/blinky_r_2.xpm", &size, &size);
	}
	else if (elements == INKY)
	{
		entity->speed = 2;
		entity->u_sprites.gost->one.original = mlx_xpm_file_to_image(window.mlx, "assets/inky_r_0.xpm", &size, &size);
		entity->u_sprites.gost->two.original = mlx_xpm_file_to_image(window.mlx, "assets/inky_r_1.xpm", &size, &size);
		entity->u_sprites.gost->three.original = mlx_xpm_file_to_image(window.mlx, "assets/inky_r_2.xpm", &size, &size);
	}
	else if (elements == PINKY)
	{
		entity->speed = 2;
		entity->u_sprites.gost->one.original = mlx_xpm_file_to_image(window.mlx, "assets/pinky_r_0.xpm", &size, &size);
		entity->u_sprites.gost->two.original = mlx_xpm_file_to_image(window.mlx, "assets/pinky_r_1.xpm", &size, &size);
		entity->u_sprites.gost->three.original = mlx_xpm_file_to_image(window.mlx, "assets/pinky_r_2.xpm", &size, &size);
	}
	else if (elements == CLYDE)
	{
		entity->speed = 2;
		entity->u_sprites.gost->one.original = mlx_xpm_file_to_image(window.mlx, "assets/clyde_r_0.xpm", &size, &size);
		entity->u_sprites.gost->two.original = mlx_xpm_file_to_image(window.mlx, "assets/clyde_r_1.xpm", &size, &size);
		entity->u_sprites.gost->three.original = mlx_xpm_file_to_image(window.mlx, "assets/clyde_r_2.xpm", &size, &size);
	}
	return ((void*)1);
}

void	*anim_gost(t_window window, t_entity *entity)
{
	int	pos_x;
	int	pos_y;

	pos_x = (entity->position.x - 5);
	pos_y = (entity->position.y - 5);
	if (entity->index_anim < 2)
	{
		mlx_put_image_to_window(window.mlx, window.win, entity->u_sprites.gost->one.original, pos_x, pos_y);
		entity->index_anim++;
	}
	else if (entity->index_anim < 4)
	{
		mlx_put_image_to_window(window.mlx, window.win, entity->u_sprites.gost->two.original, pos_x, pos_y);
		entity->index_anim++;
	}
	else if (entity->index_anim < 6)
	{
		mlx_put_image_to_window(window.mlx, window.win, entity->u_sprites.gost->three.original, pos_x, pos_y);
		entity->index_anim = 0;
	}
}

void	*anim_player(t_window window, t_entity *entity)
{
	int	pos_x;
	int	pos_y;


	pos_x = (entity->position.x - 5);
	pos_y = (entity->position.y - 5);

	if (entity->index_anim == 0)
	{
		mlx_put_image_to_window(window.mlx, window.win, entity->u_sprites.player->one, pos_x, pos_y);
		entity->index_anim++;
	}
	else if (entity->index_anim == 1)
	{
		mlx_put_image_to_window(window.mlx, window.win, entity->u_sprites.player->two, pos_x, pos_y);
		entity->index_anim++;
	}
	else if (entity->index_anim == 2)
	{
		mlx_put_image_to_window(window.mlx, window.win, entity->u_sprites.player->three, pos_x, pos_y);
		entity->index_anim++;
	}
	else if (entity->index_anim == 3)
	{
		mlx_put_image_to_window(window.mlx, window.win, entity->u_sprites.player->four, pos_x, pos_y);
		entity->index_anim++;
	}
	else if (entity->index_anim == 4)
	{
		mlx_put_image_to_window(window.mlx, window.win, entity->u_sprites.player->four, pos_x, pos_y);
		entity->index_anim++;
	}
	else if (entity->index_anim == 5)
	{
		mlx_put_image_to_window(window.mlx, window.win, entity->u_sprites.player->three, pos_x, pos_y);
		entity->index_anim++;
	}
	else if (entity->index_anim == 6)
	{
		mlx_put_image_to_window(window.mlx, window.win, entity->u_sprites.player->two, pos_x, pos_y);
		entity->index_anim = 0;
	}
}

void	*move_entity(t_window window, t_map map, t_entity *entity, t_sprite_map black_sprite)
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
}