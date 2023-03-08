#include "../includes/pacman.h"

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
	int	i;

	i = 0;
	mlx_loop_end(game->window->mlx);
	mlx_destroy_image(game->window->mlx, game->map->sprites->sp0_0.original);
	mlx_destroy_image(game->window->mlx, game->map->sprites->sp1_0.original);
	mlx_destroy_image(game->window->mlx, game->map->sprites->sp2_0.original);
	mlx_destroy_image(game->window->mlx, game->map->sprites->sp3_0.original);
	mlx_destroy_image(game->window->mlx, game->map->sprites->sp4_0.original);
	mlx_destroy_image(game->window->mlx, game->map->sprites->sp5_0.original);
	mlx_destroy_image(game->window->mlx, game->map->sprites->sp10_0.original);
	mlx_destroy_image(game->window->mlx, game->map->sprites->sp13_0.original);
	mlx_destroy_image(game->window->mlx, game->map->sprites->spxxx.original);
	mlx_destroy_window(game->window->mlx, game->window->win);
	mlx_destroy_display(game->window->mlx);
	free(game->window->mlx);
	free(game->window);
	while (i < game->map->size.y)
	{
		free(game->map->map[i]);
		i++;
	}
	
	free(game->map->map);
	free(game->map->sprites);
	free(game->map);
	exit(0);
}