#include "../includes/pacman.h"

void    *display_ui(t_game *game)
{
	mlx_string_put(game->window->mlx, game->window->win, 3 * 24, (game->map->size.y + 1) * 24, 0x00FF0000, "Life: ");
}

