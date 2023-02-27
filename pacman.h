#ifndef	PACMAN_H
# define PACMAN_H
#include <stdio.h>
#include <string.h>
#include "map/map.h"
#include "window/window.h"

typedef struct s_game {
	t_map		*map;
	t_window	*window;
}	t_game;

int	start(char *map_file);
int	mlx_loop(void *mlx);
#endif