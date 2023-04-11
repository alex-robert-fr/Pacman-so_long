/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alrobert <alrobert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 14:13:32 by alrobert          #+#    #+#             */
/*   Updated: 2022/10/26 10:07:11 by alrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t n)
{
	size_t	i;
	size_t	dst_len;

	if (n == 0)
		return (ft_strlen(src));
	dst_len = ft_strlen(dest);
	if (n < dst_len)
		return (ft_strlen(src) + n);
	i = 0;
	while (src[i] && (i + dst_len) < (n - 1))
	{
		dest[i + dst_len] = src[i];
		i++;
	}
	dest[i + dst_len] = '\0';
	return (ft_strlen(src) + dst_len);
}
