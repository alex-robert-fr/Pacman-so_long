/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alrobert <alrobert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 22:22:40 by alrobert          #+#    #+#             */
/*   Updated: 2022/10/26 09:32:34 by alrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_set_split(char const *s, char c, char **str_array, int len)
{
	int	i;
	int	letter;
	int	row;
	int	i_letter;

	i = -1;
	letter = 0;
	row = 0;
	while (++i < len)
	{
		letter += (s[i] != c && s[i]);
		if (((s[i] != c && (s[i + 1] == c)) || (i + 1 == len)) && letter > 0)
		{
			letter -= (++i == len && s[i]);
			str_array[row] = ft_calloc(letter + 1, sizeof(char));
			if (!str_array[row])
				return (NULL);
			i_letter = -1;
			while (++i_letter < letter)
				str_array[row][i_letter] = s[i - letter + i_letter];
			row++;
			letter = 0;
		}
	}
	return (str_array);
}

static int	ft_nb_word(char const *s, char c, size_t len)
{
	size_t	i;
	int		rows;

	rows = 1;
	i = 0;
	while (s[i] == c && s[i] != '\0')
		i++;
	while (i <= (ft_strlen(s)))
	{
		rows += ((s[i] == c && (s[i - 1] != c)) || (i == len && s[i - 1] != c));
		i++;
	}
	return (rows);
}

char	**ft_split(char const *s, char c)
{
	size_t		i;
	size_t		len;
	char		**str_array;

	i = 0;
	if (s)
		while (s[i] != '\0' && s[i] == c)
			i++;
	if (!s || i == ft_strlen(s))
	{
		str_array = malloc(sizeof(char *) * 1);
		str_array[0] = NULL;
		if (!str_array)
			return (NULL);
		return (str_array);
	}
	len = ft_strlen(s);
	str_array = ft_calloc(ft_nb_word(s, c, len), sizeof(char *));
	if (!str_array)
		return (NULL);
	str_array = ft_set_split(s, c, str_array, len);
	if (!str_array)
		return (NULL);
	return (str_array);
}
