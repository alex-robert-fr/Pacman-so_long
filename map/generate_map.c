#include <mlx.h>
#include "../includes/pacman.h"

void	*generate_map(t_map *map, t_window window)
{
	int			x;
	int			y;

	y = 0;
	// map.sprites = malloc(sizeof(t_sprites));
	map->sprites = import_imgs(window);
	while (y < map->size.y)
	{
		x = 0;
		while (map->map[y][x])
		{
			if (map->map[y][x] == '1')
			{
				put_map_sprite_to_window(window, map->sprites->spxxx.original, x, y);
			}
			x++;
		}
		y++;		
	}
	return ((void *)1);
}

void	put_map_sprite_to_window(t_window win, t_sprite_map *sprite, int x, int y)
{
	mlx_put_image_to_window(win.mlx, win.win, sprite, (x * 24), (y * 24));
}
