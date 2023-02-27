#include "map.h"

t_map	*check_file(char *map_file)
{
	t_map	*map;

	// map = malloc(sizeof(t_map));
	// if (!map)
	// 	return (NULL);
	if (check_path(map_file))
		return (NULL);
	map = read_and_check_map(map_file);
	if (!map)
		return (NULL);
	// map = set_map(map_file);
	// map->error_code = 0;
	// if (map->error_code)
	// 	return (map);
	return (map);	
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

int		check_wall(char *str, int len, t_walls wall)
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
			if (str[0] != WALL && len - 1 != WALL)
				return (1);
			else if ((i > 0 && i < len - 1) && (str[i] != EMPTY && str[i] != WALL))
				return (1);
			i++;
		}
		
	}
	return (0);	
}

t_map	*read_and_check_map(char *map_file)
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
		return (NULL);
	map = malloc(sizeof(t_map));
	str = gnl_trim(fd, "\n");
	if (!str || !map)
		return (NULL);
	error = 0;
	last_line = 0;
	size = v_zero();
	size.x = ft_strlen(str);
	// printf("=> %s\n", str);
	while (str)
	{
		printf("=> %s\n", str);
		next_str = gnl_trim(fd, "\n");
		if (size.x != (int)ft_strlen(str))
			error = 1;
		if (!next_str)
		{
			if (check_wall(str, size.x, DOWN))
				error = 1;
			last_line = 1;
		}
		if (!size.y && !last_line)
		{
			if (check_wall(str, size.x, UP))
				error = 1;
		}
		else if (!last_line && size.y && check_wall(str, size.x, CENTER))
		{
			error = 1;
		}
		size.y++;
		if (str)
			free(str);
		str = next_str;
	}
	close(fd);
	if (error)
	{
		free(map);
		return (NULL);
	}
	map->size = size;
	return (map);
}

// t_map 	set_map(char *map_file)
// {
// 	t_map	map;
// 	int	fd;
// 	int	y;
// 	char	*str;

// 	map.error_code = 1;
// 	fd = open(map_file, O_RDONLY);
// 	if (fd < 0)
// 		return (map);
// 	y = 0;
// 	str = "";
// 	map.map = ft_calloc(map.size.y, sizeof(char*));
// 	printf("----------------------------\n");
// 	while (str)
// 	{
// 		str = ft_strtrim(get_next_line(fd), "\n");
// 		printf("%i => %s\n", y, str);
// 		map.map[y] = str;
// 		if (str)
// 			free(str);
// 		y++;
// 	}
// 	close(fd);
// 	map.error_code = 0;
// 	return (map);
// }

char	*gnl_trim(int fd, char const *set)
{
	char	*str;
	char	*tmp_str;

	tmp_str = get_next_line(fd);
	if (!tmp_str)
		return (NULL);
	str = ft_strtrim(tmp_str, set);
	if (tmp_str)
			free(tmp_str);
	return (str);
}