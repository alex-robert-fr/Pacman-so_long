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
