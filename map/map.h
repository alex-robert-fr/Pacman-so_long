#ifndef MAP_H
# define MAP_H
#include <fcntl.h>
#include <unistd.h>
#include "../engine/vector.h"
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

typedef struct s_sprite
{
	void	*original;
	void	*white;
}	t_sprite;

typedef struct s_sprites
{
	t_sprite	sp0_0;
	t_sprite	sp1_0;
	t_sprite	sp2_0;
	t_sprite	sp3_0;
	t_sprite	sp4_0;
	t_sprite	sp4_1;
	t_sprite	sp5_0;
	t_sprite	sp6_1;
	t_sprite	sp7_1;
	t_sprite	sp8_1;
	t_sprite	sp9_1;
	t_sprite	sp9_2;
	t_sprite	sp10_0;
	t_sprite	sp10_1;
	t_sprite	sp10_2;
	t_sprite	*sp12_2;
	t_sprite	sp11_2;
	t_sprite	sp13_0;
	t_sprite	sp14_0;
	t_sprite	spxxx;
}	t_sprites;


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
char	**set_map(t_map info_map, char *map_file);
#endif
