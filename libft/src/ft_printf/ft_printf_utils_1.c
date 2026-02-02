/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroard <maroard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 16:55:41 by maroard           #+#    #+#             */
/*   Updated: 2026/02/01 19:28:50 by maroard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>
#include <stdarg.h>

static void	update_widths(t_flags *fmt, t_bool precision_started, char digit)
{
	if (!precision_started)
	{
		if (fmt->width <= INT_MAX / 10)
			fmt->width = fmt->width * 10 + digit - '0';
		else
			fmt->width = INT_MAX;
	}
	else
	{
		if (fmt->precision <= INT_MAX / 10)
			fmt->precision = fmt->precision * 10 + digit - '0';
		else
			fmt->precision = INT_MAX;
	}
}

char	parse_format(t_flags *fmt, const char *s)
{
	t_bool	width_started;
	t_bool	precision_started;

	width_started = FALSE;
	precision_started = FALSE;
	while (1)
	{
		if ((is_flag(s[fmt->skip]) && s[fmt->skip] != '0')
			|| (s[fmt->skip] == '0' && !width_started))
		{
			update_flags(fmt, s[fmt->skip]);
			if (fmt->dot)
				precision_started = TRUE;
		}
		else if ((ft_isdigit(s[fmt->skip]) && s[fmt->skip] != '0')
			|| (s[fmt->skip] == '0' && width_started))
		{
			width_started = TRUE;
			update_widths(fmt, precision_started, s[fmt->skip]);
		}
		else
			break ;
		++fmt->skip;
	}
	return (s[fmt->skip]);
}

void	read_argument(char type, t_arg *arg, va_list *arg_p)
{
	if (type == 'c')
		arg->c = va_arg(*arg_p, int);
	else if (type == 's')
		arg->s = va_arg(*arg_p, char *);
	else if (type == 'p')
		arg->p = va_arg(*arg_p, void *);
	else if (type == 'd' || type == 'i')
		arg->i = va_arg(*arg_p, int);
	else if (type == 'u' || type == 'x' || type == 'X')
		arg->u = va_arg(*arg_p, unsigned int);
	else if (type == 'f')
		arg->f = va_arg(*arg_p, double);
}

static void	digits_len(t_flags fmt, t_arg arg, const char type, t_len *len)
{
	if (type == 'c' || type == '%')
		len->digits = 1;
	else if (type == 's')
		len->digits = string_len_with_precision(fmt.dot, fmt.precision,
				arg.s);
	else if (type == 'p')
		len->digits = ptr_len(arg.p);
	else if (type == 'd' || type == 'i')
		len->digits = int_len(arg.i);
	else if (type == 'u')
		len->digits = unsigned_int_len(arg.u);
	else if (type == 'x' || type == 'X')
		len->digits = hex_len(arg.u);
	if (fmt.dot && fmt.precision == 0
		&& (((type == 'd' || type == 'i') && (!arg.i || arg.i == 0))
			|| ((type == 'u' || type == 'x' || type == 'X') && !arg.u)
			|| (type == 's')))
		len->digits = 0;
}

void	compute_lengths(t_flags fmt, t_arg arg, const char type, t_len *len)
{
	ft_memset(len, 0, sizeof(*len));
	digits_len(fmt, arg, type, len);
	if ((type == 'd' || type == 'i')
		&& (arg.i < 0 || (fmt.plus || fmt.space)))
		len->sign = 1;
	if ((type == 'p' && arg.p != NULL)
		|| ((type == 'x' || type == 'X') && (fmt.hash && arg.u != 0)))
		len->prefix = 2;
	else
		len->prefix = 0;
	if (type == 'c' || type == 's' || type == 'p' || type == '%')
		len->precision_zeros = 0;
	else if (fmt.precision > len->digits)
		len->precision_zeros = fmt.precision - len->digits;
	else
		len->precision_zeros = 0;
	len->padding = fmt.width - (len->sign + len->prefix
			+ len->precision_zeros + len->digits);
	if (len->padding < 0)
		len->padding = 0;
}
