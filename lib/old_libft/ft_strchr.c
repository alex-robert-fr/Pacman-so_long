/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alrobert <alrobert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 09:19:55 by alrobert          #+#    #+#             */
/*   Updated: 2023/02/13 20:20:23 by alrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;
	int	is_found;

	i = 0;
	is_found = 0;
	while (s[i] && !is_found)
	{
		if (s[i] == (unsigned char)c)
		{
			is_found = 1;
			break ;
		}
		i++;
	}
	if (is_found || (s[i] == '\0' && (unsigned char)c == '\0'))
		return ((char *)s + i + 1);
	return (NULL);
}
