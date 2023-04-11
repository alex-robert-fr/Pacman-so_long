/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alrobert <alrobert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 12:20:34 by alex              #+#    #+#             */
/*   Updated: 2023/02/09 14:18:53 by alrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"

char	*prepare_buf(char *buf)
{
	char	*tmp_buf;
	char	*free_buf;

	if (!buf)
		return (NULL);
	free_buf = buf;
	buf = ft_strchr(buf, '\n');
	tmp_buf = ft_strjoin(buf, "");
	free(free_buf);
	return (tmp_buf);
}

char	*prepare_line(char *buf)
{
	int		i;
	int		nl_find;
	char	*line;

	if (!buf)
		return (NULL);
	line = ft_strjoin("", buf);
	if (!line)
		return (NULL);
	i = 0;
	nl_find = 0;
	while (line[i])
	{
		if (nl_find)
			line[i] = '\0';
		if (line[i] == '\n')
			nl_find = 1;
		i++;
	}
	return (line);
}

char	*ft_free(char *buf, char *tmp_buf)
{
	char	*tmp;

	tmp = ft_strjoin(tmp_buf, buf);
	if (!tmp)
		return (NULL);
	free(buf);
	free(tmp_buf);
	return (tmp);
}

char	*read_line(int fd, char *buf)
{
	char	*tmp_buf;
	int		end_line;

	end_line = 0;
	if (buf)
	{
		tmp_buf = ft_strjoin("", buf);
		if (!tmp_buf)
			return (NULL);
		free(buf);
	}
	else
		tmp_buf = ft_calloc(BUFFER_SIZE + 1, 1);
	buf = ft_calloc(BUFFER_SIZE + 1, 1);
	if (!buf)
		return (NULL);
	tmp_buf = check_read(end_line, fd, buf, tmp_buf);
	if (!tmp_buf)
		return (NULL);
	return (tmp_buf);
}

char	*get_next_line(int fd)
{
	static char	*buf;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = read_line(fd, buf);
	if (!buf)
		return (NULL);
	line = prepare_line(buf);
	buf = prepare_buf(buf);
	return (line);
}
