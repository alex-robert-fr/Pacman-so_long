#include "../includes/pacman.h"

void		*set_spawn_entity(t_window window, t_entity *entity, t_elements elements)
{
	int	size;

	size = 33;
	if (elements == PLAYER)
		entity->u_sprites.sprite = mlx_xpm_file_to_image(window.mlx, "assets/pacman_r_0.xpm", &size, &size);
	else if (elements == BLINKY)
		entity->u_sprites.sprite = mlx_xpm_file_to_image(window.mlx, "assets/blinky_r_0.xpm", &size, &size);
	else if (elements == INKY)
		entity->u_sprites.sprite = mlx_xpm_file_to_image(window.mlx, "assets/inky_r_0.xpm", &size, &size);
	else if (elements == PINKY)
		entity->u_sprites.sprite = mlx_xpm_file_to_image(window.mlx, "assets/pinky_r_0.xpm", &size, &size);
	else if (elements == CLYDE)
		entity->u_sprites.sprite = mlx_xpm_file_to_image(window.mlx, "assets/clyde_r_0.xpm", &size, &size);
	mlx_put_image_to_window(window.mlx, window.win, entity->u_sprites.sprite, (entity->position.x * 24), (entity->position.y * 24));
	return ((void*)1);
}