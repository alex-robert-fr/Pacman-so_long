/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   margin_management.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alrobert <alrobert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 10:16:52 by alrobert          #+#    #+#             */
/*   Updated: 2022/11/16 15:15:00 by alrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

int	get_margin(const char *str, t_info_cur_arg *info)
{
	int		len;
	char	*m_str;

	len = 0;
	while (ft_isdigit(str[len]))
		len++;
	if (!len)
		return (0);
	m_str = ft_substr(str, 0, len);
	info->margin = atoi(m_str);
	free(m_str);
	return (len);
}

void	ft_putmargin(t_info_cur_arg *info)
{
	int	i;

	i = -1;
	while (++i < (info->margin - info->len))
		ft_putchar_fd(info->c_margin, 1);
}
