/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_fd_utils_6.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroard <maroard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 11:57:47 by maroard           #+#    #+#             */
/*   Updated: 2026/02/17 22:11:22 by maroard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_fd.h"

int	print_ptr(void *ptr, int fd)
{
	if (!ptr)
		return (print_str("(nil)", fd));
	return (print_hex((unsigned long)ptr, FALSE, fd));
}

int	print_double(double n, int fd)
{
	int	int_part;
	int	decimal;
	int	len;

	ft_putstr("caca");
	len = 0;
	if (n < 0)
	{
		n = -n;
		len += print_str("-", fd);
	}
	int_part = (int)n;
	decimal = (int)((n - int_part) * 100);
	len += print_int(int_part, fd);
	if (decimal < 10)
		len += print_str(".0", fd);
	else
		len += print_str(".", fd);
	len += print_int(decimal, fd);
	return (len);
}
