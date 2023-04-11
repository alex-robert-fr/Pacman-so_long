/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_proto_struct.h                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 14:14:55 by alrobert          #+#    #+#             */
/*   Updated: 2022/11/17 09:15:54 by alrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_PROTO_STRUCT_H
# define FT_PRINTF_PROTO_STRUCT_H

typedef struct s_info_printf
{
	int		total_len;
}	t_info_printf;

typedef enum a_type
{
	INT,
	U_INT,
	CHAR,
	PTR,
	PRC,
	_NULL,
}	t_arg_type;

typedef struct s_info_current_arg
{
	long			_int;
	unsigned long	_u_int;
	char			*_char;
	int				len;
	int				justify_left;
	int				margin;
	char			c_margin;
	t_arg_type		type;
}	t_info_cur_arg;

typedef struct s_type
{
	const char	flag;
	t_arg_type	type;
}	t_type;

typedef struct s_convert
{
	const char	convert;
	void		(*cb)(t_info_cur_arg *);
}	t_convert;

#endif
