#include "./includes/pacman.h"

int	main(int argc, char *argv[])
{
	int	game;

	if (argc == 2)	
	{
		printf("With map\n");
		game = start(argv[1]);
		if (game)
		{
			printf("Error\n");
			return (1);
		}
	}
	else
	{
		printf("Il manque un argument");
		return (1);
	}

	return (0);
}

int	start(char *map_file)
{
	t_game		*game;

	// game = init_game();
	game = check_file(map_file);
	if (!game->map)
		return (1);
	game->window = create_window(game->map->size.x * 24, game->map->size.y * 24, "Pacman");
	usleep(10000);
	printf("\nPLAYER: [%i, %i]\n", game->entities->player->position.x, game->entities->player->position.y);
	generate_map(game->map, *game->window);
	if (!set_spawn_entity(*game->window, game->entities->player, PLAYER))
		return (1);
	if (!set_spawn_entity(*game->window, game->entities->blinky, BLINKY))
		return (1);
	mlx_hook(game->window->win, 17, 0, ft_close, game);
	mlx_loop_hook(game->window->mlx, render_next_frame, game);
	if (mlx_loop(game->window->mlx))
		return (1);
	return(0);
}

int	render_next_frame(t_game *game)
{
	loop_time(game);
}

// t_game	*init_game()
// {

// }