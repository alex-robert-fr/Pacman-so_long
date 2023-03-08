/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alrobert <alrobert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 15:59:05 by alrobert          #+#    #+#             */
/*   Updated: 2023/03/08 18:05:16 by alrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pacman.h"

t_game	*check_file(char *map_file)
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	game->player = malloc(sizeof(t_player));
	game->player->position = v_zero();
	if (check_path(map_file))
		return (0);
	game->map = read_and_check_map(map_file, game->player);
	if (!game->map)
		return (0);
	game->map->map = set_map_in_array(*game->map, map_file);
	if (!game->map)
		return (0);
	return (game);
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

int	check_wall(char *str, int len, t_walls wall, t_player *player)
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
			if (str[0] != WALL || str[len - 1] != WALL)
				return (1);
			else if (i > 0 && i < len - 1)
			{
				if (str[i] == PLAYER)
					player->position.x = i;
				else if (str[i] != EMPTY && str[i] != WALL)
					return (1);
			}
			i++;
		}
	}
	return (0);
}

t_map	*read_and_check_map(char *map_file, t_player *player)
{
	int			fd;
	int			error;
	int			last_line;
	char		*str;
	char		*next_str;
	t_map		*map;
	t_vector	size;

	fd = open(map_file, O_RDONLY);
	if (fd < 0)
		return (0);
	map = malloc(sizeof(t_map));
	str = gnl_trim(fd, "\n");
	if (!str || !map)
		return (0);
	error = 0;
	last_line = 0;
	size = v_zero();
	size.x = ft_strlen(str);
	while (str)
	{
		if (player->position.x)
			player->position.y = size.y;
		printf("=> %s\n", str);
		next_str = gnl_trim(fd, "\n");
		if (size.x != (int)ft_strlen(str))
			error = 1;
		if (!next_str)
		{
			if (check_wall(str, size.x, DOWN, player))
				error = 1;
			last_line = 1;
		}
		if (!size.y && !last_line)
		{
			if (check_wall(str, size.x, UP, player))
				error = 1;
		}
		else if (!last_line && size.y && check_wall(str, size.x, CENTER, player))
			error = 1;
		size.y++;
		if (str)
			free(str);
		str = next_str;
	}
	close(fd);
	if (error)
	{
		free(map);
		return (0);
	}
	map->size = size;
	return (map);
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
	map = ft_calloc(info_map.size.y, sizeof(char*));
	if (!map)
		return (0);
	printf("%i ----------------------------\n", info_map.size.y);
	line = 0;
	str = gnl_trim(fd, "\n");
	while (str)
	{
		printf("%i => %s\n", line, str);
		map[line] = ft_strdup(str);
		if (str)
			free(str);
		printf("%i => %s\n", line, map[line]);
		str = gnl_trim(fd, "\n");
		line++;
	}
	close(fd);
	return (map);
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
