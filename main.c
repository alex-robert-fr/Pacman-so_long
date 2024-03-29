/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alrobert <alrobert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 22:30:53 by alrobert          #+#    #+#             */
/*   Updated: 2023/03/27 23:21:30 by alrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	t_vector	size;

	game = init_game();
	if (!check_file(map_file, game))
		return (1);
	size = game->map->size;
	game->window = create_window(size.x * 24, (size.y + 2) * 24, "Pacman");
	usleep(10000);
	generate_map(game->map, *game->window);
	if (!spawn_entities(game))
		return (1);
	mlx_hook(game->window->win, 17, 0, ft_close, game);
	mlx_loop_hook(game->window->mlx, loop_time, game);
	mlx_key_hook(game->window->win, keyboard, game->entities->player);
	if (mlx_loop(game->window->mlx))
		return (1);
	return (0);
}

int	spawn_entities(t_game *game)
{
	if (!set_spawn_entity(*game->window, game->entities->player, PLAYER))
		return (0);
	if (!set_spawn_entity(*game->window, game->entities->blinky, BLINKY))
		return (0);
	if (!set_spawn_entity(*game->window, game->entities->inky, INKY))
		return (0);
	if (!set_spawn_entity(*game->window, game->entities->pinky, PINKY))
		return (0);
	if (!set_spawn_entity(*game->window, game->entities->clyde, CLYDE))
		return (0);
	return (1);
}

t_game	*init_game(void)
{
	t_game	*game;

	game = ft_calloc(sizeof(t_game), 1);
	game->super_gomme = 0;
	game->combo = 0;
	game->time = ft_calloc(sizeof(t_time), 1);
	game->time->previous_time = clock();
	game->time->lag = 0;
	game->time->loop_anim = 0;
	game->entities = ft_calloc(sizeof(t_entities), 1);
	game->entities->player = init_entity(1);
	game->entities->blinky = init_entity(0);
	game->entities->inky = init_entity(0);
	game->entities->pinky = init_entity(0);
	game->entities->clyde = init_entity(0);
	return (game);
}

void	*init_entity(int is_player)
{
	t_entity	*entity;

	entity = ft_calloc(sizeof(t_entity), 1);
	entity->life = 1;
	entity->index_anim = 0;
	if (is_player)
		entity->u_sprites.player = ft_calloc(sizeof(t_player_anim), 1);
	else
		entity->u_sprites.gost = ft_calloc(sizeof(t_gost_anim), 1);
	return (entity);
}
