/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_fd_utils_2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroard <maroard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 18:15:25 by maroard           #+#    #+#             */
/*   Updated: 2026/02/01 19:06:57 by maroard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_fd.h"

void	init_flags(t_flags *fmt)
{
	fmt->minus = FALSE;
	fmt->zero = FALSE;
	fmt->dot = FALSE;
	fmt->hash = FALSE;
	fmt->space = FALSE;
	fmt->plus = FALSE;
	fmt->precision = 0;
	fmt->width = 0;
	fmt->padding = 0;
	fmt->skip = 0;
}

void	update_flags(t_flags *fmt, const char type)
{
	if (type == '-')
		fmt->minus = TRUE;
	else if (type == '0')
		fmt->zero = TRUE;
	else if (type == '.')
		fmt->dot = TRUE;
	else if (type == '#')
		fmt->hash = TRUE;
	else if (type == ' ')
		fmt->space = TRUE;
	else if (type == '+')
		fmt->plus = TRUE;
}

void	flags_priorities(t_flags *fmt, const char type)
{
	if (type != 'd' && type != 'i')
	{
		fmt->plus = FALSE;
		fmt->space = FALSE;
	}
	if (type != 'x' && type != 'X')
		fmt->hash = FALSE;
	if (type != 'd' && type != 'i' && type != 'u'
		&& type != 'x' && type != 'X' && type != 's')
		fmt->dot = FALSE;
	if (fmt->minus || fmt->dot
		|| (type != 'd' && type != 'i'
			&& type != 'u' && type != 'x' && type != 'X'))
		fmt->zero = FALSE;
	if (fmt->plus)
		fmt->space = FALSE;
}

t_bool	is_flag(const char c)
{
	if (c == '-' || c == '0' || c == '.' || c == '#' || c == ' ' || c == '+')
		return (TRUE);
	return (FALSE);
}
