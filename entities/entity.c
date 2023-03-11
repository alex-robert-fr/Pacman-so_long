#include "../includes/pacman.h"

void		*set_spawn_entity(t_window window, t_entity *entity, t_elements elements)
{
	int	size;

	size = 33;
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

void	*anim_gost(t_window window, t_entity *entity)
{
	int	pos_x;
	int	pos_y;

	pos_x = (entity->position.x * 24) - 5;
	pos_y = (entity->position.y * 24) - 5;
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

void	*anim_player(t_window window, t_entity *entity)
{
	int	pos_x;
	int	pos_y;


	pos_x = (entity->position.x * 24) - 5;
	pos_y = (entity->position.y * 24) - 5;
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