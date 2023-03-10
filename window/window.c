#include "../includes/pacman.h"

t_window	*create_window(int x, int y, char *title)
{
	t_window	*window;

	window = malloc(sizeof(t_window));
	window->mlx = mlx_init();
	if (!window->mlx)
		return (window);
	window->win = mlx_new_window(window->mlx, x, y, title);
	return (window);
}

int			ft_close(t_game *game)
{
	int	i;

	i = 0;
	mlx_loop_end(game->window->mlx);
	mlx_destroy_image(game->window->mlx, game->map->sprites->sp0_0.original);
	mlx_destroy_image(game->window->mlx, game->map->sprites->sp0_1.original);
	mlx_destroy_image(game->window->mlx, game->map->sprites->sp1_0.original);
	mlx_destroy_image(game->window->mlx, game->map->sprites->sp2_0.original);
	mlx_destroy_image(game->window->mlx, game->map->sprites->sp2_2.original);
	mlx_destroy_image(game->window->mlx, game->map->sprites->sp3_0.original);
	mlx_destroy_image(game->window->mlx, game->map->sprites->sp3_2.original);
	mlx_destroy_image(game->window->mlx, game->map->sprites->sp4_0.original);
	mlx_destroy_image(game->window->mlx, game->map->sprites->sp4_1.original);
	mlx_destroy_image(game->window->mlx, game->map->sprites->sp4_2.original);
	mlx_destroy_image(game->window->mlx, game->map->sprites->sp5_0.original);
	mlx_destroy_image(game->window->mlx, game->map->sprites->sp5_2.original);
	mlx_destroy_image(game->window->mlx, game->map->sprites->sp6_0.original);
	mlx_destroy_image(game->window->mlx, game->map->sprites->sp6_1.original);
	mlx_destroy_image(game->window->mlx, game->map->sprites->sp7_0.original);
	mlx_destroy_image(game->window->mlx, game->map->sprites->sp7_1.original);
	mlx_destroy_image(game->window->mlx, game->map->sprites->sp8_0.original);
	mlx_destroy_image(game->window->mlx, game->map->sprites->sp8_1.original);
	mlx_destroy_image(game->window->mlx, game->map->sprites->sp9_0.original);
	mlx_destroy_image(game->window->mlx, game->map->sprites->sp9_1.original);
	mlx_destroy_image(game->window->mlx, game->map->sprites->sp9_2.original);
	mlx_destroy_image(game->window->mlx, game->map->sprites->sp10_0.original);
	mlx_destroy_image(game->window->mlx, game->map->sprites->sp10_1.original);
	mlx_destroy_image(game->window->mlx, game->map->sprites->sp10_2.original);
	mlx_destroy_image(game->window->mlx, game->map->sprites->sp11_2.original);
	mlx_destroy_image(game->window->mlx, game->map->sprites->sp12_2.original);
	mlx_destroy_image(game->window->mlx, game->map->sprites->sp12_3.original);
	mlx_destroy_image(game->window->mlx, game->map->sprites->sp13_0.original);
	mlx_destroy_image(game->window->mlx, game->map->sprites->sp13_3.original);
	mlx_destroy_image(game->window->mlx, game->map->sprites->sp14_0.original);
	mlx_destroy_image(game->window->mlx, game->map->sprites->spxxx.original);
	mlx_destroy_image(game->window->mlx, game->entities->player->u_sprites.sprite);
	mlx_destroy_image(game->window->mlx, game->entities->blinky->u_sprites.gost->one.original);
	mlx_destroy_image(game->window->mlx, game->entities->blinky->u_sprites.gost->two.original);
	mlx_destroy_image(game->window->mlx, game->entities->blinky->u_sprites.gost->three.original);
	mlx_destroy_image(game->window->mlx, game->entities->inky->u_sprites.gost->one.original);
	mlx_destroy_image(game->window->mlx, game->entities->inky->u_sprites.gost->two.original);
	mlx_destroy_image(game->window->mlx, game->entities->inky->u_sprites.gost->three.original);
	mlx_destroy_image(game->window->mlx, game->entities->pinky->u_sprites.gost->one.original);
	mlx_destroy_image(game->window->mlx, game->entities->pinky->u_sprites.gost->two.original);
	mlx_destroy_image(game->window->mlx, game->entities->pinky->u_sprites.gost->three.original);
	mlx_destroy_image(game->window->mlx, game->entities->clyde->u_sprites.sprite);
	mlx_destroy_window(game->window->mlx, game->window->win);
	mlx_destroy_display(game->window->mlx);
	free(game->window->mlx);
	free(game->window);
	while (i < game->map->size.y)
	{
		free(game->map->map[i]);
		i++;
	}
	
	free(game->map->map);
	free(game->map->sprites);
	free(game->map);
	free(game->time);
	free(game->entities->player);
	free(game->entities->blinky->u_sprites.gost);
	free(game->entities->blinky);
	free(game->entities->inky->u_sprites.gost);
	free(game->entities->inky);
	free(game->entities->pinky->u_sprites.gost);
	free(game->entities->pinky);
	free(game->entities->clyde);
	free(game->entities);
	free(game);
	exit(0);
}/* code */