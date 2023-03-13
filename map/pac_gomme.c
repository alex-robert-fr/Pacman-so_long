#include "../includes/pacman.h"

void *manage_pacgomme(t_window window, t_map *map)
{
	int	x;
	int y;

	y = 0;
	while (y < map->size.y)
	{
		x = 0;
		while (map->map[y][x])
		{
			if (map->map[y][x] == '0')
				put_map_sprite_to_window(window, map->sprites->sp13_2.original, x, y);
			x++;
		}
		y++;		
	}
}