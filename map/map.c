#include "map.h"

t_map	check_file(char *map_file)
{
	t_map	map;

	map.error_code = 1;
	if (check_path(map_file))
		return (map);
	map = read_and_check_map(map_file);
	if (map.error_code)
		return (map);
	map = set_map(map_file);
	map.error_code = 0;
	if (map.error_code)
		return (map);
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

t_map	read_and_check_map(char *map_file)
{
	t_map	map;
	int	fd;
	char	*str;
	char	*next_str;
	t_vector	size;

	map.error_code = 1;
	size = v_zero();
	fd = open(map_file, O_RDONLY);
	if (fd < 0)
		return (map);
	str = ft_strtrim(get_next_line(fd), "\n");
	size.x = ft_strlen(str);
	while (str)
	{
		printf("%i => %s\n", size.y, str);
		next_str = ft_strtrim(get_next_line(fd), "\n");
		if (size.x != ft_strlen(str))
			return (map);
		if (!next_str)
		{
			if (check_wall(str, size.x, DOWN))
				return (map);
			break ;
		}
		if (!size.y)
		{
			if (check_wall(str, size.x, UP))
				return (map);
		}
		else if (size.y && check_wall(str, size.x, CENTER))
		{
			return (map);
		}
		size.y++;
		str = next_str;
	}
	close(fd);
	map.size = size;
	map.error_code = 0;
	return (map);
}

t_map 	set_map(char *map_file)
{
	t_map	map;
	int	fd;
	int	y;
	char	*str;

	map.error_code = 1;
	fd = open(map_file, O_RDONLY);
	if (fd < 0)
		return (map);
	str = "";
	y = 0;
	map.map = ft_calloc(map.size.y, sizeof(char*));
	while (str)
	{
		str = ft_strtrim(get_next_line(fd), "\n");
		printf("%i ==> %s\n", y, str);
		map.map[y] = str;
		y++;
	}
	close(fd);
	map.error_code = 0;
	return (map);
}