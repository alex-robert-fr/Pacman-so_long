/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alrobert <alrobert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 15:59:05 by alrobert          #+#    #+#             */
/*   Updated: 2023/03/20 09:07:24 by alrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "libft.h"
#include "ft_printf.h"
#include "get_next_line.h"
#include "pacman.h"

void	*check_file(char *map_file, t_game *game)
{
	if (check_path(map_file))
		return (NULL);
	game->map = check_map(map_file);
	if (!game->map)
		return (NULL);
	game->map->map = set_map_in_array(*game->map, map_file);
	if (!game->map)
		return (NULL);
	if (!set_entities_map(game->map->map, game->entities))
		return (NULL);
	return ((void*)1);
}

int	check_path(char *map_file)
{
	int	fd;

	fd = open(map_file, O_RDONLY);
	if (fd < 0)
		return (1);
	if (read(fd, 0, 0))
		return (1);
	close(fd);
	return (0);
}

//Pas de troue dans le mur
//Pas impossible a realiser
//Il y a 1 sorti et 1 player
//Il y a au moins 1 item
t_map	*check_map(char *map_file)
{
	t_check_map	checks;
	char		*str;
	char		*next_str;
	t_map		*map;
	t_vector	size;

	checks.have_player = 0;
	checks.fd = open(map_file, O_RDONLY);
	map = malloc(sizeof(t_map));
	str = gnl_trim(checks.fd, "\n");
	if (!str || !map)
		return (0);
	checks.error = 0;
	checks.last_line = 0;
	size = v_zero();
	size.x = ft_strlen(str);
	while (str)
	{
		ft_printf("=> %s\n", str);
		next_str = gnl_trim(checks.fd, "\n");
		if (size.x != (int)ft_strlen(str))
			checks.error = 1;
		if (!next_str)
		{
			if (check_wall_and_entity(str, size.x, DOWN, &checks))
				checks.error = 1;
			checks.last_line = 1;
		}
		if (!size.y && !checks.last_line)
		{
			if (check_wall_and_entity(str, size.x, UP, &checks))
				checks.error = 1;
		}
		else if (!checks.last_line && size.y && check_wall_and_entity(str, size.x, CENTER, &checks))
			checks.error = 1;
		size.y++;
		if (str)
			free(str);
		str = next_str;
	}
	close(checks.fd);
	if (checks.error || !checks.have_player || checks.have_player > 1)
	{
		free(map);
		return (NULL);
	}
	map->size = size;
	return (map);
}

int	check_wall_and_entity(char *str, int len, t_walls wall, t_check_map *checks)
{
	int	i;

	i = 0;
	if (wall == UP || wall == DOWN)
	{
		while (i < len)
		{
			if (str[i] != WALL)
				return (1);
			i++;
		}
	}
	else if (wall == CENTER)
	{
		while (i < len)
		{
			if (str[i] == PLAYER)
				checks->have_player++;
			if (str[0] != WALL || str[len - 1] != WALL)
				return (1);
			else if ((i > 0 && i < len - 1) && str[i] != EMPTY && str[i] != WALL && str[i] != PLAYER) //! REFACTOR
					return (1);
			i++;
		}
	}
	return (0);
}


char	**set_map_in_array(t_map info_map, char *map_file)
{
	int		fd;
	int		line;
	char	**map;
	char	*str;

	fd = open(map_file, O_RDONLY);
	if (fd < 0)
		return (0);
	map = ft_calloc(info_map.size.y + 1, sizeof(char*));
	if (!map)
		return (0);
	ft_printf("%f ----------------------------\n", info_map.size.y);
	line = 0;
	str = gnl_trim(fd, "\n");
	while (str)
	{
		map[line] = ft_strdup(str);
		if (str)
			free(str);
		ft_printf("%i => %s\n", line, map[line]);
		str = gnl_trim(fd, "\n");
		line++;
	}
	map[line] = NULL;
	close(fd);
	return (map);
}

void	*set_entities_map(char	**map, t_entities *entities)
{
	int	y;
	int	x;
	
	y = 0;
	entities->player->position = v_zero();
	entities->blinky->position = v_zero();
	entities->inky->position = v_zero();
	entities->pinky->position = v_zero();
	entities->clyde->position = v_zero();
	while(map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'P')
			{
				entities->player->position = v_init(x, y);
				map[y][x] = '0';
			}
			if (map[y][x] == 'B')
			{
				entities->blinky->position = v_init(x, y);
				map[y][x] = '0';
			}
			if (map[y][x] == 'I')
			{
				entities->inky->position = v_init(x, y);
				map[y][x] = '0';
			}
			if (map[y][x] == 'p')
			{
				entities->pinky->position = v_init(x, y);
				map[y][x] = '0';
			}
			if (map[y][x] == 'C')
			{
				entities->clyde->position = v_init(x, y);
				map[y][x] = '0';
			}
			x++;	
		}
		y++;
	}
	return ((void*)1);
}

char	*gnl_trim(int fd, char const *set)
{
	char	*str;
	char	*tmp_str;

	tmp_str = get_next_line(fd);
	if (!tmp_str)
		return (0);
	str = ft_strtrim(tmp_str, set);
	if (!str)
		return (0);
	if (tmp_str)
			free(tmp_str);
	return (str);
}
