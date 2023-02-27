#include <stdio.h>
#include <string.h>
#include "map/map.h"

typedef struct s_game {
	t_map	*map;
}	t_game;

int	start(char *map_file);
int	mlx_loop(void *mlx);
