#include "../includes/pacman.h"

t_sprites	*import_imgs(t_window window)
{
	t_sprites	*sprites;
	int		size;

	size = 24;
	sprites = malloc(sizeof(t_sprites));
	sprites->sp3_0.original = mlx_xpm_file_to_image(window.mlx, "../assets/map3_0.xpm", &size, &size);
	return (sprites);
}
