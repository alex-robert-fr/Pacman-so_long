#include "./pacman.h"
#include <stdio.h>
#include <unistd.h>

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
	game.window = create_window(24 * 24, 32 * 24, "Pacman");
	mlx_hook(game.window->win, 17, 0, ft_close, &game);
	if (mlx_loop(game.window->mlx))
		return (1);
	return(0);
}
