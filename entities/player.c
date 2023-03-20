#include "../includes/pacman.h"

void	*get_point(t_map *map, t_entity *player)
{
	int	x_pos;
	int	y_pos;

	x_pos = player->position.x / 24;
	y_pos = player->position.y / 24;
	if (map->map[y_pos][x_pos] == '0')
	{
		map->map[y_pos][x_pos] = 'x';
		player->score += 10;
	}
	if (map->map[y_pos][x_pos] == SUPER)
	{
		map->map[y_pos][x_pos] = 'x';
		player->score += 50;
	}
}
void	*check_life_player(t_entities *entities)
{
	// printf("player: %f, gost: %f\n", ceilf(entities->player->position.x / 24), entities->blinky->position.x / 24);
	if ((ceilf(entities->player->position.x / 24) == (entities->blinky->position.x / 24) || ceilf(entities->player->position.x / 24) == (entities->blinky->position.x / 24) + 1) && (ceilf(entities->player->position.y / 24) == (entities->blinky->position.y / 24) || ceilf(entities->player->position.y / 24) == (entities->blinky->position.y / 24) + 1))
		return(NULL);
	if ((ceilf(entities->player->position.x / 24) == (entities->inky->position.x / 24) || ceilf(entities->player->position.x / 24) == (entities->inky->position.x / 24) + 1) && (ceilf(entities->player->position.y / 24) == (entities->inky->position.y / 24) || ceilf(entities->player->position.y / 24) == (entities->inky->position.y / 24) + 1))
		return(NULL);
	if ((ceilf(entities->player->position.x / 24) == (entities->pinky->position.x / 24) || ceilf(entities->player->position.x / 24) == (entities->pinky->position.x / 24) + 1) && (ceilf(entities->player->position.y / 24) == (entities->pinky->position.y / 24) || ceilf(entities->player->position.y / 24) == (entities->pinky->position.y / 24) + 1))
		return(NULL);
	if ((ceilf(entities->player->position.x / 24) == (entities->clyde->position.x / 24) || ceilf(entities->player->position.x / 24) == (entities->clyde->position.x / 24) + 1) && (ceilf(entities->player->position.y / 24) == (entities->clyde->position.y / 24) || ceilf(entities->player->position.y / 24) == (entities->clyde->position.y / 24) + 1))
		return(NULL);
	return ((void*)1);
}
