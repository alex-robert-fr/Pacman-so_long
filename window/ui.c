#include <mlx.h>
#include <stdlib.h>
#include "libft.h"
#include "pacman.h"

void    display_ui(t_game *game)
{
	char	*score;

	score = ft_itoa(game->entities->player->score);
	mlx_put_image_to_window(game->window->mlx, game->window->win, game->map->sprites->sp12_2.original, 3 * 24, (game->map->size.y) * 24  + 5);
	mlx_string_put(game->window->mlx, game->window->win, 3 * 24, (game->map->size.y + 1) * 24, 0x00FF0000, score);
	free(score);
}
