/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alrobert <alrobert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 13:19:22 by alex              #+#    #+#             */
/*   Updated: 2023/02/13 09:26:42 by alrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"

char	*check_read(int end_line, int fd, char *buf, char *tmp_buf)
{
	int		bytes_read;
	int		i_check_buf;

	while (!end_line)
	{
		bytes_read = read(fd, buf, BUFFER_SIZE);
		if (bytes_read <= 0)
			break ;
		i_check_buf = 0;
		while (buf[i_check_buf])
			if (buf[i_check_buf++] == '\n')
				end_line = 1;
		tmp_buf = ft_free(buf, tmp_buf);
		buf = ft_calloc(BUFFER_SIZE + 1, 1);
		if (!tmp_buf || !buf)
			return (NULL);
	}
	if (!bytes_read || buf)
		free(buf);
	if (!tmp_buf[0])
	{
		free(tmp_buf);
		tmp_buf = NULL;
	}
	return (tmp_buf);
}
