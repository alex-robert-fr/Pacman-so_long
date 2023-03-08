#include "../includes/pacman.h"

t_sprites	*import_imgs(t_window window)
{
	t_sprites	*sprites;
	int		size;

	size = 24;
	sprites = malloc(sizeof(t_sprites));
	sprites->sp0_0.original = mlx_xpm_file_to_image(window.mlx, "assets/map0_0.xpm", &size, &size);
	sprites->sp1_0.original = mlx_xpm_file_to_image(window.mlx, "assets/map1_0.xpm", &size, &size);
	sprites->sp2_0.original = mlx_xpm_file_to_image(window.mlx, "assets/map2_0.xpm", &size, &size);
	sprites->sp3_0.original = mlx_xpm_file_to_image(window.mlx, "assets/map3_0.xpm", &size, &size);
	sprites->sp4_0.original = mlx_xpm_file_to_image(window.mlx, "assets/map4_0.xpm", &size, &size);
	sprites->sp5_0.original = mlx_xpm_file_to_image(window.mlx, "assets/map5_0.xpm", &size, &size);
	sprites->sp10_0.original = mlx_xpm_file_to_image(window.mlx, "assets/map10_0.xpm", &size, &size);
	sprites->sp13_0.original = mlx_xpm_file_to_image(window.mlx, "assets/map13_0.xpm", &size, &size);
	sprites->spxxx.original = mlx_xpm_file_to_image(window.mlx, "assets/no_valid.xpm", &size, &size);
	return (sprites);
}
