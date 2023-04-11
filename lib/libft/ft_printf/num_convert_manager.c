/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num_convert_manager.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 13:41:13 by alrobert          #+#    #+#             */
/*   Updated: 2022/11/17 09:24:04 by alrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

void	d_convert(t_info_cur_arg *info)
{
	ft_putnbr_fd(info->_int, 1);
}

void	x_convert(t_info_cur_arg *info)
{
	ft_puthexa(info->_int, 'a');
}

void	xx_convert(t_info_cur_arg *info)
{
	ft_puthexa(info->_int, 'A');
}
