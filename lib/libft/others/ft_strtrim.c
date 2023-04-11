/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alrobert <alrobert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 13:32:30 by alrobert          #+#    #+#             */
/*   Updated: 2022/10/26 09:31:52 by alrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	trim(char const *s1, char const *set)
{
	int		i_start;
	int		find;
	int		j;

	i_start = 0;
	find = 1;
	while (s1[i_start])
	{
		if (find >= 1)
		{
			find = 0;
			j = 0;
			while (set[j])
			{
				if (s1[i_start] == set[j])
					find++;
				j++;
			}
		}
		else
			break ;
		i_start++;
	}
	return (i_start);
}

static size_t	rtrim(char const *s1, char const *set)
{
	size_t		i_start;
	int			find;
	int			j;

	i_start = ft_strlen(s1) - 1;
	find = 1;
	while (s1[i_start])
	{
		if (find >= 1)
		{
			find = 0;
			j = 0;
			while (set[j])
			{
				if (s1[i_start] == set[j])
					find++;
				j++;
			}
		}
		else
			break ;
		i_start--;
	}
	return (i_start);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t		i;
	size_t		i_start;
	char		*str;
	int			i_end;

	if (!s1)
		return (NULL);
	i = 0;
	i_start = trim(s1, set) - 1;
	i_end = rtrim(s1, set) + 2;
	if ((i_start + 1) == ft_strlen(s1))
	{
		str = ft_calloc(1, sizeof(char));
		return (str);
	}
	str = ft_calloc(i_end - i_start + 1, sizeof(char));
	if (!str)
		return (NULL);
	while (s1[i] && i < (i_end - i_start))
	{
		str[i] = s1[i_start + i];
		i++;
	}
	return (str);
}
