#include "../includes/pacman.h"

void manage_pacgomme(t_game *game)
{
	int	x;
	int y;
	int	is_win;

	y = 0;
	is_win = 1;
	while (y < game->map->size.y)
	{
		x = 0;
		while (game->map->map[y][x])
		{
			if (game->map->map[y][x] == '0' && (game->map->map[y][x - 1] == '1' || game->map->map[y - 1][x] == '1' || game->map->map[y][x + 1] == '1' || game->map->map[y + 1][x] == '1'))
			{
				put_map_sprite_to_window(*game->window, game->map->sprites->sp13_2.original, x, y);
				is_win = 0;
			}
			else if (game->map->map[y][x] == SUPER)
			{
				put_map_sprite_to_window(*game->window, game->map->sprites->sp15_2.original, x, y);
			}
			x++;
		}
		y++;		
	}
	if (is_win)
		ft_close(game);
}
