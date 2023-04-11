/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_struct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 13:57:03 by alrobert          #+#    #+#             */
/*   Updated: 2022/11/17 09:23:18 by alrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_info_cur_arg	create_info_arg_struct(void)
{
	t_info_cur_arg	info_arg;

	info_arg._int = 0x0;
	info_arg._u_int = 0x0;
	info_arg._char = 0x0;
	info_arg.len = 0;
	info_arg.justify_left = 0;
	info_arg.margin = 0;
	info_arg.c_margin = 0;
	info_arg.type = _NULL;
	return (info_arg);
}

const t_convert	*create_convert_struct(void)
{
	static const t_convert	c[MAX_CONVERT] = {
	{'c', c_convert},
	{'s', s_convert},
	{'p', p_convert},
	{'d', d_convert},
	{'i', d_convert},
	{'u', d_convert},
	{'x', x_convert},
	{'X', xx_convert},
	{'%', c_convert},
	};

	return (c);
}
