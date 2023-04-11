/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alrobert <alrobert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 17:20:25 by alex              #+#    #+#             */
/*   Updated: 2022/10/26 10:49:31 by alrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*text;
	size_t	word;
	size_t	s_len;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start > s_len)
	{
		text = ft_calloc(1, sizeof(char));
		if (!text)
			return (NULL);
		return (text);
	}
	if (len + start > s_len)
		text = ft_calloc((ft_strlen(s) - start + 1), sizeof(char));
	else
		text = ft_calloc((len + 1), sizeof(char));
	if (!text)
		return (NULL);
	word = 0;
	while (s[start] && word < len)
		text[word++] = s[start++];
	return (text);
}
