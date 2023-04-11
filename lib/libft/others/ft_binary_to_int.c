/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_binary_to_int.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alrobert <alrobert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 14:39:46 by alrobert          #+#    #+#             */
/*   Updated: 2023/03/31 14:40:38 by alrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_binary_to_int(char *binary, int bits_number)
{
	int	i;
	int	num;

	i = 0;
	num = 0;
	while (binary[i])
	{
		if (binary[i] == '1')
			num |= 1 << ((bits_number - 1) - i);
		i++;
	}
	return (num);
}
