#ifndef PACMAN_H
# define PACMAN_H
#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h> 
#include "../lib/libft/libft.h"
#include "../lib/get_next_line/get_next_line.h"

typedef struct s_vector
{
	int	x;
	int	y;
}	t_vector;

typedef struct s_window
{
	void	*mlx;
	void	*win;
}	t_window;

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
	t_sprites	*sprites;
}	t_map;

typedef struct s_game {
	t_map		*map;
	t_window	*window;
}	t_game;

int			start(char *map_file);
int			mlx_loop(void *mlx);
int			ft_close(t_game *game);
int			check_path(char *path);
int			check_wall(char *str, int len, t_walls wall);
char		*gnl_trim(int fd, char const *set);
char		**set_map_in_array(t_map info_map, char *map_file);
void		*mlx_xpm_file_to_image(void *mlx, char *img, int *x, int *y);
void		*generate_map(t_map map, t_window window);
void	put_map_sprite_to_window(t_window win, t_sprite *sprite, int x, int y);
void		*mlx_init();
void		*mlx_new_window(void *mlx, int x, int y, char *title);
t_vector	v_zero();
t_map		*check_file(char *map_file);
t_map		*read_and_check_map(char *map_file);
t_sprites	*import_imgs(t_window window);
t_window	*create_window(int x, int y, char *title);
#endif