#include "../includes/pacman.h"

void	*generate_map(t_map map, t_window window)
{
	t_sprites	*sprites;

	sprites = import_imgs(window);
	mlx_put_image_to_window(window.mlx, window.win, sprites->sp3_0.original, (1 * 24), (1 * 24));
	// int			x;
	// int			y;

	// printf("Hello\n");
	// fflush(stdout);
	// y = 0;
	// while (map.map[y])
	// {
		// printf("%s\n", map.map[y]);
		// fflush(stdout);
		// x = 0;
		// while (map.map[y][x])
		// {
		// 	printf("IN WHILE\n");
		// 	fflush(stdout);
			// if (!mlx_put_image_to_window(window.mlx, window.win, sprites->sp3_0.original, (1 * 24), (1 * 24)))
			// 	ft_putstr_fd("IMAGE NULL", 1);
		// 	if (map.map[y][x] == '1')
		// 	{
		// 	}
		// 	x++;
		// }
	// 	y++;
	// }
	return ((void *)1);
}
