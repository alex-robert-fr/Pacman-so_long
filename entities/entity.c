#include "../includes/pacman.h"

void		*set_spawn_entity(t_window window, t_entity *entity, t_elements elements)
{
	int	size;

	size = 33;
	if (elements == PLAYER)
		entity->u_sprites.sprite = mlx_xpm_file_to_image(window.mlx, "assets/pacman_r_0.xpm", &size, &size);
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
	//! TMP
	if (elements == BLINKY || elements == INKY || elements == PINKY || elements == CLYDE)
		mlx_put_image_to_window(window.mlx, window.win, entity->u_sprites.gost->one.original, (entity->position.x * 24), (entity->position.y * 24));
	else
		mlx_put_image_to_window(window.mlx, window.win, entity->u_sprites.sprite, (entity->position.x * 24), (entity->position.y * 24));
	return ((void*)1);
}

void	*anim_gost(t_window window, t_entity *entity)
{
	if (entity->index_anim == 0)
	{
		mlx_put_image_to_window(window.mlx, window.win, entity->u_sprites.gost->one.original, (entity->position.x * 24), (entity->position.y * 24));
		entity->index_anim++;
	}
	else if (entity->index_anim == 1)
	{
		mlx_put_image_to_window(window.mlx, window.win, entity->u_sprites.gost->two.original, (entity->position.x * 24), (entity->position.y * 24));
		entity->index_anim++;
	}
	else if (entity->index_anim == 2)
	{
		mlx_put_image_to_window(window.mlx, window.win, entity->u_sprites.gost->three.original, (entity->position.x * 24), (entity->position.y * 24));
		entity->index_anim = 0;
	}
}