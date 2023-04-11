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

void	*load_img(t_window win, char *name, int x, int y)
{
	void	*mlx_img;

	mlx_img = mlx_xpm_file_to_image(win.mlx, name, &x, &y);
	return (mlx_img);
}
