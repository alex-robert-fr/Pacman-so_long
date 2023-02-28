#ifndef IMAGES_H
#define IMAGES_H
#include <mlx.h>
#include "../window/window.h"

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

t_sprites	import_imgs(t_window window);
#endif
