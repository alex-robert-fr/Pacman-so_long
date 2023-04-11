/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_convert_manager.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 13:42:18 by alrobert          #+#    #+#             */
/*   Updated: 2022/11/17 09:22:55 by alrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

void	c_convert(t_info_cur_arg *info)
{
	ft_putchar_fd(info->_int, 1);
}

void	s_convert(t_info_cur_arg *info)
{
	if (!info->_char)
		ft_putstr_fd("(null)", 1);
	ft_putstr_fd(info->_char, 1);
}

void	p_convert(t_info_cur_arg *info)
{
	if (!info->_u_int)
		ft_putstr_fd("(nil)", 1);
	else
	{
		ft_putstr_fd("0x", 1);
		info->len += 2;
		ft_puthexa(info->_u_int, 'a');
	}
}
