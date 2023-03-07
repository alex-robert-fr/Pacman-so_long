#include "../includes/pacman.h"

void	*generate_map(t_map map, t_window window)
{
	t_sprites	*sprites;

	int			x;
	int			y;

	y = 0;
	sprites = import_imgs(window);
	while (map.map[y])
	{
		x = 0;
		while (map.map[y][x])
		{
			if (map.map[y][x] == '1')
			{
				mlx_put_image_to_window(window.mlx, window.win, sprites->sp3_0.original, (x * 24), (y * 24));
			}
		}
	}
	return ((void *)1);
}
