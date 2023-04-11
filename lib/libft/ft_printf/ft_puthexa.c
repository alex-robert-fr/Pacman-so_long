/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alrobert <alrobert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 19:09:07 by alrobert          #+#    #+#             */
/*   Updated: 2022/11/11 17:47:18 by alrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

void	ft_puthexa(unsigned long nbr, int is_maj_or_min)
{
	int	out;

	if (nbr >= 16)
		ft_puthexa(nbr / 16, is_maj_or_min);
	out = nbr % 16;
	if (out < 10)
		ft_putnbr_fd(out, 1);
	else
		ft_putchar_fd(out + (is_maj_or_min - 10), 1);
}
