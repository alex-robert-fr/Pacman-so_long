#ifndef PACMAN_H
# define PACMAN_H
#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h> 
#include <time.h>
#include "../lib/libft/libft.h"
#include "../lib/get_next_line/get_next_line.h"

typedef struct s_time
{
	int	current_time;
	int	previous_time;
	int	elapsed_time;
	int	lag;
	int	loop_anim;
}	t_time;


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
	EMPTY = '0',
	PLAYER = 'P',
	BLINKY = 'B',
	INKY = 'I',
	PINKY = 'p',
	CLYDE = 'C',
}	t_elements;

typedef struct s_sprite_map
{
	void	*original;
	void	*white;
}	t_sprite_map;

typedef struct s_sprites
{
	t_sprite_map	sp0_0;
	t_sprite_map	sp0_1;
	t_sprite_map	sp1_0;
	t_sprite_map	sp2_0;
	t_sprite_map	sp2_2;
	t_sprite_map	sp3_0;
	t_sprite_map	sp3_2;
	t_sprite_map	sp4_0;
	t_sprite_map	sp4_1;
	t_sprite_map	sp4_2;
	t_sprite_map	sp5_0;
	t_sprite_map	sp5_2;
	t_sprite_map	sp6_0;
	t_sprite_map	sp6_1;
	t_sprite_map	sp7_0;
	t_sprite_map	sp7_1;
	t_sprite_map	sp8_0;
	t_sprite_map	sp8_1;
	t_sprite_map	sp9_0;
	t_sprite_map	sp9_1;
	t_sprite_map	sp9_2;
	t_sprite_map	sp10_0;
	t_sprite_map	sp10_1;
	t_sprite_map	sp10_2;
	t_sprite_map	sp12_2;
	t_sprite_map	sp11_2;
	t_sprite_map	sp12_3;
	t_sprite_map	sp13_0;
	t_sprite_map	sp13_3;
	t_sprite_map	sp14_0;
	t_sprite_map	spxxx;
}	t_sprites;

typedef struct s_sprite_gost
{
	void	*original;
	void	*blue;
	void	*white;
}	t_sprite_gost;


typedef struct s_gost_anim
{
	t_sprite_gost	one;
	t_sprite_gost	two;
	t_sprite_gost	three;
}	t_gost_anim;


typedef struct s_map
{
	t_vector	size;
	char		**map;
	t_sprites	*sprites;
}	t_map;

typedef struct s_entity
{
	t_vector	position;
	union
	{
		void			*sprite;
		t_gost_anim		*gost;
	}	u_sprites;
}	t_entity;

typedef struct s_entities
{
	t_entity	*player;
	t_entity	*blinky;
	t_entity	*inky;
	t_entity	*pinky;
	t_entity	*clyde;
}	t_entities;

typedef struct s_game {
	t_window	*window;
	t_map		*map;
	t_entities	*entities;
	t_time		*time;
}	t_game;

t_game		*init_game();
int			start(char *map_file);
int			mlx_loop(void *mlx);
int			ft_close(t_game *game);
int			check_path(char *path);
int			check_wall(char *str, int len, t_walls wall);
char		*gnl_trim(int fd, char const *set);
char		**set_map_in_array(t_map info_map, char *map_file);
void		*mlx_xpm_file_to_image(void *mlx, char *img, int *x, int *y);
void		*generate_map(t_map *map, t_window window);
void		put_map_sprite_to_window(t_window win, t_sprite_map *sprite, int x, int y);
void		*mlx_init();
void		*mlx_new_window(void *mlx, int x, int y, char *title);
void		*set_entities_map(char	**map, t_entities *entities);
void		*set_spawn_entity(t_window window, t_entity *entity, t_elements element);
void		loop_time(t_game *game);
int			render_next_frame(t_game *game);
t_vector	v_zero();
t_vector	v_init(int x, int y);
void		*check_file(char *map_file, t_game *game);
t_map		*read_and_check_map(char *map_file);
t_sprites	*import_imgs(t_window window);
t_window	*create_window(int x, int y, char *title);
#endif