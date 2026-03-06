/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_fd_utils_6.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroard <maroard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 11:57:47 by maroard           #+#    #+#             */
/*   Updated: 2026/03/06 16:08:32 by maroard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_fd.h"

int	print_ptr_fd(void *ptr, int fd)
{
	if (!ptr)
		return (print_str_fd("(nil)", fd));
	return (print_hex_fd((unsigned long)ptr, FALSE, fd));
}

int	print_double_fd(double n, int fd)
{
	int	int_part;
	int	decimal;
	int	len;

	len = 0;
	if (n < 0)
	{
		n = -n;
		len += print_str_fd("-", fd);
	}
	int_part = (int)n;
	decimal = (int)((n - int_part) * 100);
	len += print_int_fd(int_part, fd);
	if (decimal < 10)
		len += print_str_fd(".0", fd);
	else
		len += print_str_fd(".", fd);
	len += print_int_fd(decimal, fd);
	return (len);
}
