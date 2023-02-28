#ifndef MAP_H
# define MAP_H
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "../engine/vector.h"
#include "../window/window.h"
#include "../lib/get_next_line/get_next_line.h"

typedef enum e_wall
{
	UP,
	DOWN,
	CENTER
}	t_walls;

typedef enum e_elements
{
	WALL = '1',
	EMPTY = '0'
}	t_elements;




typedef struct s_map
{
	t_vector	size;
	char		**map;
}	t_map;

int		check_path(char *path);
int		check_wall(char *str, int len, t_walls wall);
t_map	*check_file(char *map_file);
t_map	*read_and_check_map(char *map_file);
char	*gnl_trim(int fd, char const *set);
void	*mlx_xpm_file_to_image(void *mlx, char *img, int *x, int *y);
char	**set_map_in_array(t_map info_map, char *map_file);
void	*generate_map(t_map map, t_window window);
#endif
