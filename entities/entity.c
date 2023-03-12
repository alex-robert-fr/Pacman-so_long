#include "../includes/pacman.h"

void		*set_spawn_entity(t_window window, t_entity *entity, t_elements elements)
{
	int	size;

	size = 33;
	entity->position.x *= 24;
	entity->position.y *= 24;
	entity->direction = v_init(1, 0);
	entity->next_direction = v_init(0, 1);
	if (elements == PLAYER)
	{
		entity->u_sprites.player->one = mlx_xpm_file_to_image(window.mlx, "assets/pacman_r_0.xpm", &size, &size);
		entity->u_sprites.player->two = mlx_xpm_file_to_image(window.mlx, "assets/pacman_r_1.xpm", &size, &size);
		entity->u_sprites.player->three = mlx_xpm_file_to_image(window.mlx, "assets/pacman_r_2.xpm", &size, &size);
		entity->u_sprites.player->four = mlx_xpm_file_to_image(window.mlx, "assets/pacman_r_3.xpm", &size, &size);
		
	}
	else if (elements == BLINKY)
	{
		entity->u_sprites.gost->one.original = mlx_xpm_file_to_image(window.mlx, "assets/blinky_r_0.xpm", &size, &size);
		entity->u_sprites.gost->two.original = mlx_xpm_file_to_image(window.mlx, "assets/blinky_r_1.xpm", &size, &size);
		entity->u_sprites.gost->three.original = mlx_xpm_file_to_image(window.mlx, "assets/blinky_r_2.xpm", &size, &size);
	}
	else if (elements == INKY)
	{
		entity->u_sprites.gost->one.original = mlx_xpm_file_to_image(window.mlx, "assets/inky_r_0.xpm", &size, &size);
		entity->u_sprites.gost->two.original = mlx_xpm_file_to_image(window.mlx, "assets/inky_r_1.xpm", &size, &size);
		entity->u_sprites.gost->three.original = mlx_xpm_file_to_image(window.mlx, "assets/inky_r_2.xpm", &size, &size);
	}
	else if (elements == PINKY)
	{
		entity->u_sprites.gost->one.original = mlx_xpm_file_to_image(window.mlx, "assets/pinky_r_0.xpm", &size, &size);
		entity->u_sprites.gost->two.original = mlx_xpm_file_to_image(window.mlx, "assets/pinky_r_1.xpm", &size, &size);
		entity->u_sprites.gost->three.original = mlx_xpm_file_to_image(window.mlx, "assets/pinky_r_2.xpm", &size, &size);
	}
	else if (elements == CLYDE)
	{
		entity->u_sprites.gost->one.original = mlx_xpm_file_to_image(window.mlx, "assets/clyde_r_0.xpm", &size, &size);
		entity->u_sprites.gost->two.original = mlx_xpm_file_to_image(window.mlx, "assets/clyde_r_1.xpm", &size, &size);
		entity->u_sprites.gost->three.original = mlx_xpm_file_to_image(window.mlx, "assets/clyde_r_2.xpm", &size, &size);
	}
	return ((void*)1);
}

void	*anim_gost(t_window window, t_entity *entity, void *black_sprite)
{
	int	pos_x;
	int	pos_y;

	pos_x = (entity->position.x - 5);
	pos_y = (entity->position.y - 5);
	mlx_put_image_to_window(window.mlx, window.win, black_sprite, (entity->position.x - 29), (entity->position.y - 5));
	if (entity->index_anim == 0)
	{
		mlx_put_image_to_window(window.mlx, window.win, entity->u_sprites.gost->one.original, pos_x, pos_y);
		entity->index_anim++;
	}
	else if (entity->index_anim == 1)
	{
		mlx_put_image_to_window(window.mlx, window.win, entity->u_sprites.gost->two.original, pos_x, pos_y);
		entity->index_anim++;
	}
	else if (entity->index_anim == 2)
	{
		mlx_put_image_to_window(window.mlx, window.win, entity->u_sprites.gost->three.original, pos_x, pos_y);
		entity->index_anim = 0;
	}
}

void	*anim_player(t_window window, t_entity *entity, void *black_sprite)
{
	int	pos_x;
	int	pos_y;


	pos_x = (entity->position.x - 5);
	pos_y = (entity->position.y - 5);
	mlx_put_image_to_window(window.mlx, window.win, black_sprite, (entity->position.x - 29), (entity->position.y - 5));
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

void	*move_entity(t_map map, t_entity *entity)
{
	check_direction(map, entity);
	if (entity->direction.x > 0)
	{
		entity->position.x += 1;
		entity->position.y += 0;
	}
	if (entity->direction.x < 0)
	{
		entity->position.x -= 1;
		entity->position.y += 0;
	}
	if (entity->direction.y > 0)
	{
		entity->position.x += 0;
		entity->position.y += 1;
	}
	if (entity->direction.y < 0)
	{
		entity->position.x += 0;
		entity->position.y -= 1;
	}
}

void	*check_direction(t_map map, t_entity *entity)
{
	float	x_pos = entity->position.x / 24;
	float	y_pos = entity->position.y / 24;
	if (entity->next_direction.y > 0)
	{
		if (map.map[(int)y_pos + 1][(int)x_pos] == '0' && x_pos == ceilf(x_pos))
		{
			entity->direction.x = 0;
			entity->direction.y = 1;
		}
	}
	if (entity->next_direction.y < 0)
	{
		if (map.map[(int)y_pos - 1][(int)x_pos] == '0' && x_pos == ceilf(x_pos))
		{
			entity->direction.x = 0;
			entity->direction.y = -1;
		}
	}
	if (entity->next_direction.x > 0)
	{
		if (map.map[(int)y_pos][(int)x_pos + 1] == '0' && y_pos == ceilf(y_pos))
		{
			entity->direction.x = 1;
			entity->direction.y = 0;
		}
	}
	if (entity->next_direction.x < 0)
	{
		if (map.map[(int)y_pos][(int)x_pos - 1] == '0' && y_pos == ceilf(y_pos))
		{
			entity->direction.x = -1;
			entity->direction.y = 0;
		}
	}
	// printf("%f == %f\n", entity->position.x / 24, ceilf(entity->position.x / 24));
	// if ((entity->position.x / 24) == ceilf(entity->position.x / 24))
	// 	printf("PASS\n");

	// if (map.map[((int)entity->position.y / 24) + 1][(int)entity->position.x / 24] == '0')
	// {
	// 	entity->position.y += 1;
	// 	entity->position.x += 0;
	// }
	// else
	// {
	// 	entity->position.y += 0;
	// 	entity->position.x += 1;

	// }

}