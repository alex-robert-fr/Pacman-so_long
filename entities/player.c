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
}