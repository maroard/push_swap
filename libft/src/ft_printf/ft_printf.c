/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroard <maroard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 11:35:42 by maroard           #+#    #+#             */
/*   Updated: 2026/02/01 19:26:05 by maroard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>

static int	dispatcher(const char type, t_ctx ctx)
{
	if (type == 'c')
		return (ft_putchar(ctx.arg.c), 1);
	if (type == 's' && !ctx.format.dot)
		return (print_str(ctx.arg.s));
	if (type == 's')
		return (print_str_n(ctx.arg.s, ctx.format.precision));
	if (type == 'p')
		return (print_ptr(ctx.arg.p));
	if (type == 'd' || type == 'i')
		return (print_int(ctx.arg.i));
	if (type == 'u')
		return (print_unsigned_int(ctx.arg.u));
	if (type == 'x')
		return (print_hex(ctx.arg.u, FALSE));
	if (type == 'X')
		return (print_hex(ctx.arg.u, TRUE));
	if (type == '%')
		return (ft_putchar('%'), 1);
	if (type == 'f')
		return (print_double(ctx.arg.f));
	return (0);
}

static int	print_formatted(t_ctx ctx, const char type)
{
	int	total_len;

	total_len = 0;
	if (!ctx.format.minus && !ctx.format.zero)
		total_len += print_padding(ctx.len.padding, ' ');
	if ((type == 'd' || type == 'i') && ctx.arg.i < 0)
		total_len += print_sign('-');
	else if ((type == 'd' || type == 'i') && ctx.format.plus)
		total_len += print_sign('+');
	else if ((type == 'd' || type == 'i') && ctx.format.space)
		total_len += print_sign(' ');
	if ((type == 'p' && ctx.arg.p != NULL)
		|| ((type == 'x' || type == 'X') && ctx.format.hash && ctx.arg.u != 0))
		total_len += print_prefix(type);
	if (!ctx.format.minus && !ctx.format.dot && ctx.format.zero)
		total_len += print_padding(ctx.len.padding, '0');
	else if (ctx.format.dot && ctx.len.precision_zeros != 0)
		total_len += print_precision(ctx.len.precision_zeros);
	if (ctx.len.digits > 0)
		total_len += dispatcher(type, ctx);
	if (ctx.format.minus)
		total_len += print_padding(ctx.len.padding, ' ');
	return (total_len);
}

static int	format_manager(t_ctx *ctx, const char *s, va_list *arg_p)
{
	char	type;
	int		len;

	init_flags(&ctx->format);
	type = parse_format(&ctx->format, s);
	flags_priorities(&ctx->format, type);
	read_argument(type, &ctx->arg, arg_p);
	compute_lengths(ctx->format, ctx->arg, type, &ctx->len);
	len = print_formatted(*ctx, type);
	return (len);
}

int	ft_printf(const char *s, ...)
{
	va_list	arg_p;
	int		i;
	int		s_len;
	t_ctx	ctx;

	va_start(arg_p, s);
	i = 0;
	s_len = 0;
	while (s[i])
	{
		if (s[i] == '%')
		{
			s_len += format_manager(&ctx, s + ++i, &arg_p);
			i += ctx.format.skip + 1;
		}
		else
		{
			ft_putchar(s[i++]);
			++s_len;
		}
	}
	va_end(arg_p);
	return (s_len);
}
