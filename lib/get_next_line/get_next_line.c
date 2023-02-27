/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 12:20:34 by alex              #+#    #+#             */
/*   Updated: 2023/01/28 14:45:46 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char    *prepare_buf(char *buf)
{
    char    *tmp_buf;
    char    *free_buf;

    if (!buf)
        return (NULL);
    free_buf = buf;
    buf = ft_strchr(buf, '\n');
    tmp_buf = ft_strjoin(buf, "");
    free(free_buf);
    return (tmp_buf);
}

char    *prepare_line(char *buf)
{
    int i;
    int nl_find;
    char    *line;

    if (!buf)
        return (NULL);
    line = ft_strjoin("", buf);
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

char    *ft_free(char *buf, char *tmp_buf)
{
    char *tmp;


    tmp = ft_strjoin(tmp_buf, buf);
    free(buf);
    free(tmp_buf);
    return(tmp);
}

char    *read_line(int fd, char *buf)
{
    char    *tmp_buf;
    int end_line;
    int bytes_read;
    int i_check_buf;
    
    end_line = 0;
    if (buf)
    {
        tmp_buf = ft_strjoin("", buf);
        free(buf);
        buf = ft_calloc(BUFFER_SIZE + 1, 1);
        i_check_buf = 0;
    }
    else
    {
        buf = ft_calloc(BUFFER_SIZE + 1, 1);
        tmp_buf = ft_calloc(BUFFER_SIZE + 1, 1);
    }
    while (!end_line)
    {
        bytes_read = read(fd, buf, BUFFER_SIZE);
        if (!bytes_read)
            break;
        i_check_buf = 0;
        while (buf[i_check_buf])
        {
            if (buf[i_check_buf] == '\n')
                end_line = 1;
            i_check_buf++;
        }
        tmp_buf = ft_free(buf, tmp_buf);
        buf = ft_calloc(BUFFER_SIZE + 1, 1);
    }
    if (!bytes_read)
    {
        free(buf);
        buf = NULL;
        if (!tmp_buf[0])
        {
            free(tmp_buf);
            tmp_buf = NULL;
        }
    }
    if (buf)
        free(buf);
    return (tmp_buf);
}

char *get_next_line(int fd)
{
    char        *line;
    static char *buf;

    if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0))
        return (NULL);
    buf = read_line(fd, buf);
    line = prepare_line(buf);
    buf = prepare_buf(buf);
    return (line);
}

