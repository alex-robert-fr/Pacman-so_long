#include "../includes/pacman.h"

void		*set_spawn_entity(t_window window, t_entity *entity)
{
	int	size;

	size = 33;
	entity->u_sprites.sprite = mlx_xpm_file_to_image(window.mlx, "assetsu_sprites
u_sprites/pacman_r_0.xpm", &size, &size);
	mlx_put_image_to_window(window.mlx, window.win, entity->u_sprites.sprite, (entity->position.x * 24), (entity->position.y * 24));
	return ((void*)1);
}