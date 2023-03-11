#include "../includes/pacman.h"

t_sprites	*import_imgs(t_window window)
{
	t_sprites	*sprites;
	int		size;

	size = 24;
	sprites = malloc(sizeof(t_sprites));
	sprites->sp0_0.original = mlx_xpm_file_to_image(window.mlx, "assets/map0_0.xpm", &size, &size);
	sprites->sp0_1.original = mlx_xpm_file_to_image(window.mlx, "assets/map0_1.xpm", &size, &size);
	sprites->sp1_0.original = mlx_xpm_file_to_image(window.mlx, "assets/map1_0.xpm", &size, &size);
	sprites->sp2_0.original = mlx_xpm_file_to_image(window.mlx, "assets/map2_0.xpm", &size, &size);
	sprites->sp2_2.original = mlx_xpm_file_to_image(window.mlx, "assets/map2_2.xpm", &size, &size);
	sprites->sp3_0.original = mlx_xpm_file_to_image(window.mlx, "assets/map3_0.xpm", &size, &size);
	sprites->sp3_2.original = mlx_xpm_file_to_image(window.mlx, "assets/map3_2.xpm", &size, &size);
	sprites->sp4_0.original = mlx_xpm_file_to_image(window.mlx, "assets/map4_0.xpm", &size, &size);
	sprites->sp4_1.original = mlx_xpm_file_to_image(window.mlx, "assets/map4_1.xpm", &size, &size);
	sprites->sp4_2.original = mlx_xpm_file_to_image(window.mlx, "assets/map4_2.xpm", &size, &size);
	sprites->sp5_0.original = mlx_xpm_file_to_image(window.mlx, "assets/map5_0.xpm", &size, &size);
	sprites->sp5_2.original = mlx_xpm_file_to_image(window.mlx, "assets/map5_2.xpm", &size, &size);
	sprites->sp6_0.original = mlx_xpm_file_to_image(window.mlx, "assets/map6_0.xpm", &size, &size);
	sprites->sp6_1.original = mlx_xpm_file_to_image(window.mlx, "assets/map6_1.xpm", &size, &size);
	sprites->sp7_0.original = mlx_xpm_file_to_image(window.mlx, "assets/map7_0.xpm", &size, &size);
	sprites->sp7_1.original = mlx_xpm_file_to_image(window.mlx, "assets/map7_1.xpm", &size, &size);
	sprites->sp8_0.original = mlx_xpm_file_to_image(window.mlx, "assets/map8_0.xpm", &size, &size);
	sprites->sp8_1.original = mlx_xpm_file_to_image(window.mlx, "assets/map8_1.xpm", &size, &size);
	sprites->sp9_0.original = mlx_xpm_file_to_image(window.mlx, "assets/map9_0.xpm", &size, &size);
	sprites->sp9_1.original = mlx_xpm_file_to_image(window.mlx, "assets/map9_1.xpm", &size, &size);
	sprites->sp9_2.original = mlx_xpm_file_to_image(window.mlx, "assets/map9_2.xpm", &size, &size);
	sprites->sp10_0.original = mlx_xpm_file_to_image(window.mlx, "assets/map10_0.xpm", &size, &size);
	sprites->sp10_1.original = mlx_xpm_file_to_image(window.mlx, "assets/map10_1.xpm", &size, &size);
	sprites->sp10_2.original = mlx_xpm_file_to_image(window.mlx, "assets/map10_2.xpm", &size, &size);
	sprites->sp11_2.original = mlx_xpm_file_to_image(window.mlx, "assets/map11_2.xpm", &size, &size);
	sprites->sp12_2.original = mlx_xpm_file_to_image(window.mlx, "assets/map12_2.xpm", &size, &size);
	sprites->sp12_3.original = mlx_xpm_file_to_image(window.mlx, "assets/map12_3.xpm", &size, &size);
	sprites->sp13_0.original = mlx_xpm_file_to_image(window.mlx, "assets/map13_0.xpm", &size, &size);
	sprites->sp13_3.original = mlx_xpm_file_to_image(window.mlx, "assets/map13_3.xpm", &size, &size);
	sprites->sp14_0.original = mlx_xpm_file_to_image(window.mlx, "assets/map14_0.xpm", &size, &size);
	sprites->spxxx.original = mlx_xpm_file_to_image(window.mlx, "assets/no_valid.xpm", &size, &size);
	sprites->black.original = mlx_xpm_file_to_image(window.mlx, "assets/black.xpm", &size, &size);
	return (sprites);
}
