/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alrobert <alrobert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 22:58:19 by alrobert          #+#    #+#             */
/*   Updated: 2023/03/27 23:25:29 by alrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pacman.h"

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
	import_imgs_1(win, sprites, size, size);
	import_imgs_2(win, sprites, size, size);
	sprites->black.original = load_img(win, "assets/black_x.xpm", blk_x, blk_y);
	sprites->black.white = load_img(win, "assets/black_y.xpm", blk_y, blk_x);
	return (sprites);
}

void	import_imgs_1(t_window win, t_sprites *sprites, int x, int y)
{
	sprites->sp0_0.original = load_img(win, "assets/map0_0.xpm", x, y);
	sprites->sp0_1.original = load_img(win, "assets/map0_1.xpm", x, y);
	sprites->sp1_0.original = load_img(win, "assets/map1_0.xpm", x, y);
	sprites->sp2_0.original = load_img(win, "assets/map2_0.xpm", x, y);
	sprites->sp2_2.original = load_img(win, "assets/map2_2.xpm", x, y);
	sprites->sp3_0.original = load_img(win, "assets/map3_0.xpm", x, y);
	sprites->sp3_2.original = load_img(win, "assets/map3_2.xpm", x, y);
	sprites->sp4_0.original = load_img(win, "assets/map4_0.xpm", x, y);
	sprites->sp4_1.original = load_img(win, "assets/map4_1.xpm", x, y);
	sprites->sp4_2.original = load_img(win, "assets/map4_2.xpm", x, y);
	sprites->sp5_0.original = load_img(win, "assets/map5_0.xpm", x, y);
	sprites->sp5_2.original = load_img(win, "assets/map5_2.xpm", x, y);
	sprites->sp6_0.original = load_img(win, "assets/map6_0.xpm", x, y);
	sprites->sp6_1.original = load_img(win, "assets/map6_1.xpm", x, y);
	sprites->sp7_0.original = load_img(win, "assets/map7_0.xpm", x, y);
	sprites->sp7_1.original = load_img(win, "assets/map7_1.xpm", x, y);
	sprites->sp8_0.original = load_img(win, "assets/map8_0.xpm", x, y);
	sprites->sp8_1.original = load_img(win, "assets/map8_1.xpm", x, y);
	sprites->sp9_0.original = load_img(win, "assets/map9_0.xpm", x, y);
	sprites->sp9_1.original = load_img(win, "assets/map9_1.xpm", x, y);
	sprites->sp9_2.original = load_img(win, "assets/map9_2.xpm", x, y);
	sprites->sp10_0.original = load_img(win, "assets/map10_0.xpm", x, y);
	sprites->sp10_1.original = load_img(win, "assets/map10_1.xpm", x, y);
	sprites->sp10_2.original = load_img(win, "assets/map10_2.xpm", x, y);
	sprites->sp11_2.original = load_img(win, "assets/map11_2.xpm", x, y);
}

void	import_imgs_2(t_window win, t_sprites *sprites, int x, int y)
{
	sprites->sp12_2.original = load_img(win, "assets/map12_2.xpm", x, y);
	sprites->sp12_3.original = load_img(win, "assets/map12_3.xpm", x, y);
	sprites->sp13_0.original = load_img(win, "assets/map13_0.xpm", x, y);
	sprites->sp13_2.original = load_img(win, "assets/map13_2.xpm", x, y);
	sprites->sp13_3.original = load_img(win, "assets/map13_3.xpm", x, y);
	sprites->sp14_0.original = load_img(win, "assets/map14_0.xpm", x, y);
	sprites->sp15_2.original = load_img(win, "assets/map15_2.xpm", x, y);
	sprites->spxxx.original = load_img(win, "assets/no_valid.xpm", x, y);
}

void	*load_img(t_window win, char *name, int x, int y)
{
	void	*mlx_img;

	mlx_img = mlx_xpm_file_to_image(win.mlx, name, &x, &y);
	return (mlx_img);
}
