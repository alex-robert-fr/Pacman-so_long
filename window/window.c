#include "window.h"

t_window	*create_window(int x, int y, char *title)
{
	t_window	*window;

	window = malloc(sizeof(t_window));
	window->mlx = mlx_init();
	if (!window->mlx)
		return (window);
	window->win = mlx_new_window(window->mlx, x, y, title);
	return (window);
}

int			ft_close(t_game *game)
{
	mlx_loop_end(game->window->mlx);
	mlx_destroy_window(game->window->mlx, game->window->win);
	mlx_destroy_display(game->window->mlx);
	free(game->window->mlx);
	free(game->window);
	free(game->map->map);
	free(game->map);
	exit(0);
}