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
	t_game		game;

	game.map = check_file(map_file);
	if (!game.map)
		return (1);
	printf("Before Generate window\n");
	fflush(stdout);
	game.window = create_window(game.map->size.x * 24, game.map->size.y * 24, "Pacman");
	sleep(1);
	printf("After Generate window\n");
	fflush(stdout);
	generate_map(*game.map, *game.window);
	mlx_hook(game.window->win, 17, 0, ft_close, &game);
	if (mlx_loop(game.window->mlx))
		return (1);
	return(0);
}
