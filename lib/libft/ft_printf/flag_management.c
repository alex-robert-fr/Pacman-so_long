/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_management.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alrobert <alrobert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 17:19:13 by alrobert          #+#    #+#             */
/*   Updated: 2022/11/16 15:42:45 by alrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

int	check_flag(const char *flag, t_info_cur_arg *info)
{
	int	len;
	int	i;

	len = 0;
	i = 0;
	info->c_margin = ' ';
	while ((!ft_isdigit(flag[i]) || flag[i] == '0') \
		&& (!ft_isalpha(flag[i]) && flag[i] != 37))
	{
		if (flag[i] == '-')
			info->justify_left = 1;
		if (flag[i] == '0')
			info->c_margin = '0';
		if (info->justify_left || info->c_margin == '0')
			len++;
		i++;
	}
	return (len);
}
