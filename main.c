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
	// free(game.map->size);
	free(game.map);
	return(0);
}
