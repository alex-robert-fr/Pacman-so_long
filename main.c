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

	game = init_game();
	if (!check_file(map_file, game))
		return (1);
	game->window = create_window(game->map->size.x * 24, (game->map->size.y + 2) * 24, "Pacman");
	usleep(10000);
	// printf("\nPLAYER: [%f, %f]\n", game->entities->player->position.x, game->entities->player->position.y);
	// printf("\nPINKY: [%i, %i]\n", game->entities->pinky->position.x, game->entities->pinky->position.y);
	generate_map(game->map, *game->window);
	if (!set_spawn_entity(*game->window, game->entities->player, PLAYER))
		return (1);
	if (!set_spawn_entity(*game->window, game->entities->blinky, BLINKY))
		return (1);
	if (!set_spawn_entity(*game->window, game->entities->inky, INKY))
		return (1);
	if (!set_spawn_entity(*game->window, game->entities->pinky, PINKY))
		return (1);
	if (!set_spawn_entity(*game->window, game->entities->clyde, CLYDE))
		return (1);
	display_ui(game);
	mlx_hook(game->window->win, 17, 0, ft_close, game);
	mlx_loop_hook(game->window->mlx, render_next_frame, game);
	mlx_key_hook(game->window->win, keyboard, game->entities->player);
	if (mlx_loop(game->window->mlx))
		return (1);
	return(0);
}

int	render_next_frame(t_game *game)
{
	loop_time(game);
}

t_game	*init_game()
{
	t_game	*game;

	game = ft_calloc(sizeof(t_game), 1);
	game->time = ft_calloc(sizeof(t_time), 1);
	game->time->previous_time = clock();
	game->time->lag = 0;
	game->time->loop_anim = 0;
	game->entities = ft_calloc(sizeof(t_entities), 1);

	game->entities->player = ft_calloc(sizeof(t_entity), 1);
	game->entities->player->index_anim = 0;
	game->entities->player->u_sprites.player = ft_calloc(sizeof(t_player_anim), 1);

	game->entities->blinky = ft_calloc(sizeof(t_entity), 1);
	game->entities->blinky->index_anim = 0;
	game->entities->blinky->u_sprites.gost = ft_calloc(sizeof(t_gost_anim), 1);

	game->entities->inky = ft_calloc(sizeof(t_entity), 1);
	game->entities->inky->index_anim = 0;
	game->entities->inky->u_sprites.gost = ft_calloc(sizeof(t_gost_anim), 1);

	game->entities->pinky = ft_calloc(sizeof(t_entity), 1);
	game->entities->pinky->index_anim = 0;
	game->entities->pinky->u_sprites.gost = ft_calloc(sizeof(t_gost_anim), 1);

	game->entities->clyde = ft_calloc(sizeof(t_entity), 1);
	game->entities->clyde->index_anim = 0;
	game->entities->clyde->u_sprites.gost = ft_calloc(sizeof(t_gost_anim), 1);
	return (game);
}