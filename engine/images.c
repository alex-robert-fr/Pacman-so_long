/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alrobert <alrobert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 22:58:19 by alrobert          #+#    #+#             */
/*   Updated: 2023/03/29 16:46:37 by alrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "pacman.h"

t_sprites	*import_imgs(t_window win)
{
	t_sprites	*sprites;
	int			size;
	int			blk_x;
	int			blk_y;

	size = 24;
	blk_x = 5;
	blk_y = 33;
	sprites = malloc(sizeof(t_sprites));
	import_imgs_2(win, sprites, size, size);
	sprites->black.original = load_img(win, "assets/black_x.xpm", blk_x, blk_y);
	sprites->black.white = load_img(win, "assets/black_y.xpm", blk_y, blk_x);
	return (sprites);
}

void	import_imgs_2(t_window win, t_sprites *sprites, int x, int y)
{
	sprites->sp12_2.original = load_img(win, "assets/map12_2.xpm", x, y);
	sprites->spxxx.original = load_img(win, "assets/no_valid.xpm", x, y);
}

void	import_imgs_player(t_window win, t_player_anim *player, int s)
{
	player->original = load_img(win, "assets/pacman_0.xpm", s, s);
	player->right[0] = load_img(win, "assets/pacman_r_1.xpm", s, s);
	player->right[1] = load_img(win, "assets/pacman_r_2.xpm", s, s);
	player->right[2] = load_img(win, "assets/pacman_r_3.xpm", s, s);
	player->left[0] = load_img(win, "assets/pacman_l_1.xpm", s, s);
	player->left[1] = load_img(win, "assets/pacman_l_2.xpm", s, s);
	player->left[2] = load_img(win, "assets/pacman_l_3.xpm", s, s);
	player->top[0] = load_img(win, "assets/pacman_t_1.xpm", s, s);
	player->top[1] = load_img(win, "assets/pacman_t_2.xpm", s, s);
	player->top[2] = load_img(win, "assets/pacman_t_3.xpm", s, s);
	player->bottom[0] = load_img(win, "assets/pacman_b_1.xpm", s, s);
	player->bottom[1] = load_img(win, "assets/pacman_b_2.xpm", s, s);
	player->bottom[2] = load_img(win, "assets/pacman_b_3.xpm", s, s);
}

void	imprt_imgs_gost(t_window win, t_gost_anim *gost, t_elements type, int s)
{
	char	*text;
	int		index;
	int		direction;

	direction = 0;
	while (direction < 4)
	{
		index = 0;
		while (index < 3)
		{
			text = get_text_imgs_gosts(direction, index, type);
			if (!direction)
				gost->right[index].original = load_img(win, text, s, s);
			else if (direction == 1)
				gost->left[index].original = load_img(win, text, s, s);
			else if (direction == 2)
				gost->top[index].original = load_img(win, text, s, s);
			else if (direction == 3)
				gost->bottom[index].original = load_img(win, text, s, s);
			index++;
		}
		imprt_imgs_gosts_eyes(direction++, win, gost, s);
	}
}

char	*get_text_imgs_gosts(int direction, int index, t_elements type_gost)
{
	char	*text;

	if (!direction)
		text = "r";
	else if (direction == 1)
		text = "l";
	else if (direction == 2)
		text = "t";
	else if (direction == 3)
		text = "b";
	if (type_gost == BLINKY)
		text = ft_strjoin("assets/blinky_", text);
	else if (type_gost == INKY)
		text = ft_strjoin("assets/inky_", text);
	else if (type_gost == PINKY)
		text = ft_strjoin("assets/pinky_", text);
	else if (type_gost == CLYDE)
		text = ft_strjoin("assets/clyde_", text);
	text = ft_strjoin(text, "_");
	text = ft_strjoin(text, ft_itoa(index));
	text = ft_strjoin(text, ".xpm");
	return (text);
}

void	imprt_imgs_gosts_eyes(int dirct, t_window win, t_gost_anim *gost, int s)
{
	char	*text;

	if (!dirct)
	{
		text = ft_strjoin("assets/blinky_eye_", "r.xpm");
		gost->right[3].original = load_img(win, text, s, s);
	}
	else if (dirct == 1)
	{
		text = ft_strjoin("assets/blinky_eye_", "l.xpm");
		gost->left[3].original = load_img(win, text, s, s);
	}
	else if (dirct == 2)
	{
		text = ft_strjoin("assets/blinky_eye_", "t.xpm");
		gost->top[3].original = load_img(win, text, s, s);
	}
	else if (dirct == 3)
	{
		text = ft_strjoin("assets/blinky_eye_", "b.xpm");
		gost->bottom[3].original = load_img(win, text, s, s);
	}
}

void	import_imgs_gosts_blue(t_window win, t_gost_anim *gost, int s)
{
	gost->right[0].blue = load_img(win, "assets/blue_gost_r_0.xpm", s, s);
	gost->right[1].blue = load_img(win, "assets/blue_gost_r_1.xpm", s, s);
	gost->right[2].blue = load_img(win, "assets/blue_gost_r_2.xpm", s, s);
	gost->left[0].blue = load_img(win, "assets/blue_gost_l_0.xpm", s, s);
	gost->left[1].blue = load_img(win, "assets/blue_gost_l_1.xpm", s, s);
	gost->left[2].blue = load_img(win, "assets/blue_gost_l_2.xpm", s, s);
	gost->top[0].blue = load_img(win, "assets/blue_gost_t_0.xpm", s, s);
	gost->top[1].blue = load_img(win, "assets/blue_gost_t_1.xpm", s, s);
	gost->top[2].blue = load_img(win, "assets/blue_gost_t_2.xpm", s, s);
	gost->bottom[0].blue = load_img(win, "assets/blue_gost_b_0.xpm", s, s);
	gost->bottom[1].blue = load_img(win, "assets/blue_gost_b_1.xpm", s, s);
	gost->bottom[2].blue = load_img(win, "assets/blue_gost_b_2.xpm", s, s);
}

void	*load_img(t_window win, char *name, int x, int y)
{
	void	*mlx_img;

	mlx_img = mlx_xpm_file_to_image(win.mlx, name, &x, &y);
	return (mlx_img);
}
