#ifndef PACMAN_H
# define PACMAN_H

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
	float	x;
	float	y;
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

typedef struct s_sprites
{
	void	*sp12_2;
	void	*spxxx;
	void	*black_x;
	void	*black_y;
}	t_sprites;

typedef struct s_map
{
	t_vector	size;
	char		**map;
	t_sprites	*sprites;
}	t_map;

typedef struct s_check_map
{
	int fd;
	int error;
	int	last_line;
	int	have_player;
}	t_check_map;

typedef struct s_entity
{
	t_vector	position;
	t_vector	direction;
	int			life;
	union
	{
		void			*gost;
		void			*player;
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

/*----GAME----*/
int			start(char *map_file);
t_game		*init_game(void);
void		*init_entity(void);

/*----MAP----*/
void		*check_file(char *map_file, t_game *game);
int			check_path(char *path);
t_map		*check_map(char *map_file);
int			check_wall_and_entity(char *str, int len, t_walls wall, t_check_map *checks);

int			mlx_loop(void *mlx);
int			ft_close(t_game *game);
int			spawn_entities(t_game *game);
void		import_imgs_1(t_window win, t_sprites *sprites, int x, int y);
void		import_imgs_2(t_window win, t_sprites *sprites, int x, int y);
//void		import_imgs_player(t_window win, t_player_anim *sprites, int size);
//void		imprt_imgs_gost(t_window win, t_gost_anim *gost, t_elements type , int s);
char		*get_text_imgs_gosts(int direction, int index, t_elements type_gost);
void		go_left(t_entity *entity);
void		go_right(t_entity *entity);
void		go_top(t_entity *entity);
void		go_down(t_entity *entity);
void		*load_img(t_window win, char *name, int x, int y);
void		anim_gost(t_window window, t_entity *entity, int super_gomme);
char		*gnl_trim(int fd, char const *set);
char		**set_map_in_array(t_map info_map, char *map_file);
void		*mlx_xpm_file_to_image(void *mlx, char *img, int *x, int *y);
void		*generate_map(t_map *map, t_window window);
void		put_map_sprite_to_window(t_window win, t_sprites *sprite, int x, int y);
void		manage_pacgomme(t_game *game);
int			check_life_player(t_entities *entities);
void		get_point(t_game *game, t_map *map, t_entity *player);
void		*mlx_init();
void		anim_player(t_window window, t_entity *entity);
void		*mlx_new_window(void *mlx, int x, int y, char *title);
void		*set_entities_map(char	**map, t_entities *entities);
void		*set_spawn_entity(t_window window, t_entity *entity, t_elements element);
int			loop_time(t_game *game);
int			render_next_frame(t_game *game);
void    	display_ui(t_game *game);
//void		move_entity(t_window window, t_map map, t_entity *entity, t_sprite_map black_sprite);
void		anim_move_player(t_window window, t_entity *entity, int *img_time);
void		anim_move_gost(t_window window, t_entity *entity);
void		choise_direction_ia(t_entity *entity);
int			keyboard(int keycode, t_entity *player);
void		*check_direction(t_map map, t_entity *entity);
t_vector	v_zero();
t_vector	v_init(int x, int y);
t_sprites	*import_imgs(t_window window);
t_window	*create_window(int x, int y, char *title);
void		gost_is_dead(t_entity *gost);
int			check_collision_with_gost(t_vector player_pos, t_vector pos);
int			count_lifes_gosts(t_entities entities);
#endif
