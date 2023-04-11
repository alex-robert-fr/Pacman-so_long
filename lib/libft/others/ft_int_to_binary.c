/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_to_binary.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alrobert <alrobert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 14:40:45 by alrobert          #+#    #+#             */
/*   Updated: 2023/03/31 14:41:19 by alrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	*ft_int_to_binary(int dec, int bit_number)
{
	int	i;
	int	*binary;

	i = bit_number - 1;
	binary = ft_calloc(bit_number + 1, sizeof(int));
	while (dec > 0)
	{
		binary[i] = dec % 2;
		dec /= 2;
		i--;
	}
	return (binary);
}
