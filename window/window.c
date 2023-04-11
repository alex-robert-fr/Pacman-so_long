#include <stdlib.h>
#include <mlx.h>
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
	mlx_destroy_image(game->window->mlx, game->map->sprites->spxxx.original);
	mlx_destroy_image(game->window->mlx, game->entities->player->u_sprites.player->original);
	mlx_destroy_image(game->window->mlx, game->entities->player->u_sprites.player->right[0]);
	mlx_destroy_image(game->window->mlx, game->entities->player->u_sprites.player->right[1]);
	mlx_destroy_image(game->window->mlx, game->entities->player->u_sprites.player->right[2]);
	mlx_destroy_image(game->window->mlx, game->entities->player->u_sprites.player->left[0]);
	mlx_destroy_image(game->window->mlx, game->entities->player->u_sprites.player->left[1]);
	mlx_destroy_image(game->window->mlx, game->entities->player->u_sprites.player->left[2]);
	mlx_destroy_image(game->window->mlx, game->entities->player->u_sprites.player->top[0]);
	mlx_destroy_image(game->window->mlx, game->entities->player->u_sprites.player->top[1]);
	mlx_destroy_image(game->window->mlx, game->entities->player->u_sprites.player->top[2]);
	mlx_destroy_image(game->window->mlx, game->entities->player->u_sprites.player->bottom[0]);
	mlx_destroy_image(game->window->mlx, game->entities->player->u_sprites.player->bottom[1]);
	mlx_destroy_image(game->window->mlx, game->entities->player->u_sprites.player->bottom[2]);
	mlx_destroy_image(game->window->mlx, game->entities->blinky->u_sprites.gost);
	mlx_destroy_image(game->window->mlx, game->entities->inky->u_sprites.gost);
	mlx_destroy_image(game->window->mlx, game->entities->pinky->u_sprites.gost);
	mlx_destroy_image(game->window->mlx, game->entities->clyde->u_sprites.gost);
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
	free(game->entities->player->u_sprites.player);
	free(game->entities->player);
	free(game->entities->blinky->u_sprites.gost);
	free(game->entities->blinky);
	free(game->entities->inky->u_sprites.gost);
	free(game->entities->inky);
	free(game->entities->pinky->u_sprites.gost);
	free(game->entities->pinky);
	free(game->entities->clyde->u_sprites.gost);
	free(game->entities->clyde);
	free(game->entities);
	free(game);
	exit(0);
}/* code */
