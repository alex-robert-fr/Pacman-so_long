#ifndef	WINDOW_H
# define WINDOW_H
#include <mlx.h>
#include <stdlib.h>
#include "../map/map.h"

typedef struct s_window
{
	void	*mlx;
	void	*win;
}	t_window;

typedef struct s_game {
	t_map		*map;
	t_window	*window;
}	t_game;

void		*mlx_init();
void		*mlx_new_window(void *mlx, int x, int y, char *title);
t_window	*create_window(int x, int y, char *title);
int			ft_close(t_game *game);
#endif
