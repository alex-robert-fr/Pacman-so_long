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
				/* -------------------------------------------------------------------------- */
				/*                                     MUR                                    */
				/* -------------------------------------------------------------------------- */
				//Angle 0,0
				if (y == 0 && x == 0)
					put_map_sprite_to_window(window, map->sprites->sp1_0.original, x, y);
				//Angle 1,0
				else  if (y == map->size.y - 1 && x == 0)
					put_map_sprite_to_window(window, map->sprites->sp5_0.original, x, y);
				//Angle 0,1
				else if (y == 0 && x == map->size.x - 1)
					put_map_sprite_to_window(window, map->sprites->sp0_0.original, x, y);
				//Angle 1,1
				else if (y == map->size.y - 1 && x == map->size.x - 1)
					put_map_sprite_to_window(window, map->sprites->sp4_0.original, x, y);
				//Mur Haut
				else if (y == 0 && map->map[y][x + 1] == '1' && map->map[y][x - 1] == '1')
				{
					if (map->map[y + 1][x] == '0' || map->map[y + 1][x] == SUPER)
						put_map_sprite_to_window(window, map->sprites->sp10_0.original, x, y);
					else if (map->map[y + 1][x + 1] == '1' && map->map[y + 1][x - 1] == '0' || map->map[y + 1][x - 1] == SUPER)
						put_map_sprite_to_window(window, map->sprites->sp11_2.original, x, y);
					else if (map->map[y + 1][x - 1] == '1' && map->map[y + 1][x + 1] == '0' || map->map[y + 1][x + 1] == SUPER)
						put_map_sprite_to_window(window, map->sprites->sp10_2.original, x, y);
				}
				//Mur Bas
				else if (y == (map->size.y - 1) && map->map[y][x + 1] == '1' && map->map[y][x - 1] == '1')
				{
					if (map->map[y - 1][x] == '0' || map->map[y - 1][x] == SUPER)
						put_map_sprite_to_window(window, map->sprites->sp13_0.original, x, y);
					else if (map->map[y - 1][x + 1] == '1' && map->map[y - 1][x - 1] == '0' || map->map[y - 1][x - 1] == SUPER)
						put_map_sprite_to_window(window, map->sprites->sp12_3.original, x, y);
					else if (map->map[y - 1][x - 1] == '1' && map->map[y - 1][x + 1] == '0' || map->map[y - 1][x + 1] == SUPER)
						put_map_sprite_to_window(window, map->sprites->sp13_3.original, x, y);
				}
				//Mur Gauche
				else if (x == 0 && map->map[y - 1][x] == '1' && map->map[y + 1][x] == '1')
				{
					if (map->map[y][x + 1] == '0' || map->map[y][x + 1] == SUPER)
						put_map_sprite_to_window(window, map->sprites->sp3_0.original, x, y);
					else if (map->map[y + 1][x + 1] == '1' && map->map[y - 1][x + 1] == '0' || map->map[y - 1][x + 1] == SUPER)
						put_map_sprite_to_window(window, map->sprites->sp7_0.original, x, y);
					else if (map->map[y - 1][x + 1] == '1' && map->map[y + 1][x + 1] == '0' || map->map[y + 1][x + 1] == SUPER)
						put_map_sprite_to_window(window, map->sprites->sp9_0.original, x, y);
				}
				// Mur Droite
				else if (x == (map->size.x - 1) && map->map[y - 1][x] == '1' && map->map[y + 1][x] == '1')
				{
					if (map->map[y][x - 1] == '0' || map->map[y][x - 1] == SUPER)
						put_map_sprite_to_window(window, map->sprites->sp2_0.original, x, y);
					else if (map->map[y + 1][x - 1] == '1' && map->map[y - 1][x - 1] == '0' || map->map[y - 1][x - 1] == SUPER)
						put_map_sprite_to_window(window, map->sprites->sp6_0.original, x, y);
					else if (map->map[y - 1][x - 1] == '1' && map->map[y + 1][x - 1] == '0' || map->map[y + 1][x - 1] == SUPER)
						put_map_sprite_to_window(window, map->sprites->sp8_0.original, x, y);
				}
				/* -------------------------------------------------------------------------- */
				/*                                    BLOC                                    */
				/* -------------------------------------------------------------------------- */
				//Angle 0,0
				else if ((map->map[y - 1][x] == '0' || map->map[y - 1][x] == SUPER) && map->map[y + 1][x] == '1' && (map->map[y][x - 1] == '0' || map->map[y][x - 1] == SUPER) && map->map[y][x + 1] == '1')
					put_map_sprite_to_window(window, map->sprites->sp7_1.original, x, y);
				//Angle 0,1
				else if ((map->map[y - 1][x] == '0' || map->map[y - 1][x] == SUPER) && map->map[y + 1][x] == '1' && map->map[y][x - 1] == '1' && (map->map[y][x + 1] == '0' || map->map[y][x + 1] == SUPER))
					put_map_sprite_to_window(window, map->sprites->sp6_1.original, x, y);
				//Angle 1,0
				else if (map->map[y - 1][x] == '1' && (map->map[y + 1][x] == '0' || map->map[y + 1][x] == SUPER) && (map->map[y][x - 1] == '0' || map->map[y][x - 1] == SUPER) && map->map[y][x + 1] == '1')
					put_map_sprite_to_window(window, map->sprites->sp9_2.original, x, y);
				//Angle 1,1
				else if (map->map[y - 1][x] == '1' && (map->map[y + 1][x] == '0' || map->map[y + 1][x] == SUPER) && map->map[y][x - 1] == '1' && (map->map[y][x + 1] == '0' || map->map[y][x + 1] == SUPER))
					put_map_sprite_to_window(window, map->sprites->sp10_1.original, x, y);
				//Mur Haut
				else if ((map->map[y - 1][x] == '0' || map->map[y - 1][x] == SUPER) && map->map[y + 1][x] == '1' && map->map[y][x - 1] == '1' && map->map[y][x + 1] == '1')
					put_map_sprite_to_window(window, map->sprites->sp14_0.original, x, y);
				//Mur Bas
				else if (map->map[y - 1][x] == '1' && (map->map[y + 1][x] == '0' || map->map[y + 1][x] == SUPER) && map->map[y][x - 1] == '1' && map->map[y][x + 1] == '1')
					put_map_sprite_to_window(window, map->sprites->sp4_1.original, x, y);
				//Mur Gauche
				else if (map->map[y - 1][x] == '1' && map->map[y + 1][x] == '1' && (map->map[y][x - 1] == '0' || map->map[y][x - 1] == SUPER) && map->map[y][x + 1] == '1')
					put_map_sprite_to_window(window, map->sprites->sp9_1.original, x, y);
				//Mur Droite
				else if (map->map[y - 1][x] == '1' && map->map[y + 1][x] == '1' && map->map[y][x - 1] == '1' && (map->map[y][x + 1] == '0' || map->map[y][x + 1] == SUPER))
					put_map_sprite_to_window(window, map->sprites->sp8_1.original, x, y);
				// Par default
				else
				{
					/* -------------------------------------------------------------------------- */
					/*                                  EXTRUSION                                 */
					/* -------------------------------------------------------------------------- */
					if (map->map[y - 1][x] == '1' && map->map[y + 1][x] == '1' && map->map[y][x - 1] == '1' && map->map[y][x + 1] == '1')
					{
						//Vide
						put_map_sprite_to_window(window, map->sprites->sp12_2.original, x, y);
						//Angle 0,0
						if (map->map[y - 1][x - 1] == '0')
							put_map_sprite_to_window(window, map->sprites->sp5_2.original, x, y);
						//Angle 0,1
						if (map->map[y - 1][x + 1] == '0')
							put_map_sprite_to_window(window, map->sprites->sp4_2.original, x, y);
						//Angle 1,0
						if (map->map[y + 1][x - 1] == '0')
							put_map_sprite_to_window(window, map->sprites->sp3_2.original, x, y);
						//Angle 1,1
						if (map->map[y + 1][x + 1] == '0')
							put_map_sprite_to_window(window, map->sprites->sp2_2.original, x, y);
					}
				}
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