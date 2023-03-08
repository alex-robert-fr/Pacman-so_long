#include "../includes/pacman.h"

void	*generate_map(t_map map, t_window window)
{
	int			x;
	int			y;

	y = 0;
	map.sprites = import_imgs(window);
	while (y < map.size.y)
	{
		x = 0;
		while (map.map[y][x])
		{
			if (map.map[y][x] == '1')
			{
				/* -------------------------------------------------------------------------- */
				/*                                     MUR                                    */
				/* -------------------------------------------------------------------------- */
				//Angle 0,0
				// if (y == 0 && x == 0)
				// 	put_map_sprite_to_window(window, sprites->sp1_0.original, x, y);
				// //Angle 1,0
				// else  if (y == map.size.y - 1 && x == 0)
				// 	put_map_sprite_to_window(window, sprites->sp5_0.original, x, y);
				// //Angle 0,1
				// else if (y == 0 && x == map.size.x - 1)
				// 	put_map_sprite_to_window(window, sprites->sp0_0.original, x, y);
				// //Angle 1,1
				// else if (y == map.size.y - 1 && x == map.size.x - 1)
				// 	put_map_sprite_to_window(window, sprites->sp4_0.original, x, y);
				// //Mur Haut
				// else if (y == 0 && map.map[y + 1][x] == '0' && map.map[y][x + 1] == '1' && map.map[y][x - 1] == '1')
				// 	put_map_sprite_to_window(window, sprites->sp10_0.original, x, y);
				// // Mur Bas
				// else if (y == (map.size.y - 1) && map.map[y - 1][x] == '0' && map.map[y][x + 1] == '1' && map.map[y][x - 1] == '1')
				// 	put_map_sprite_to_window(window, sprites->sp13_0.original, x, y);
				// //Mur Gauche
				// else if (x == 0 && map.map[y][x + 1] == '0' && map.map[y - 1][x] == '1' && map.map[y + 1][x] == '1')
				// 	put_map_sprite_to_window(window, sprites->sp3_0.original, x, y);
				// // Mur Droite
				// else if (x == (map.size.x - 1) && map.map[y][x - 1] == '0' && map.map[y - 1][x] == '1' && map.map[y + 1][x] == '1')
				// 	put_map_sprite_to_window(window, sprites->sp2_0.original, x, y);
				// // Par default
				// else
					put_map_sprite_to_window(window, map.sprites->spxxx.original, x, y);
			}
			x++;
		}
		y++;		
	}
	return ((void *)1);
}

void	put_map_sprite_to_window(t_window win, t_sprite *sprite, int x, int y)
{
	mlx_put_image_to_window(win.mlx, win.win, sprite, (x * 24), (y * 24));
}