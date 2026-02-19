/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_fd_utils_4.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroard <maroard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 21:37:03 by maroard           #+#    #+#             */
/*   Updated: 2026/02/18 14:36:06 by maroard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_fd.h"

int	print_padding(int padding_len, const char padding_char, int fd)
{
	int	len;

	len = padding_len;
	while (padding_len > 0)
	{
		ft_putchar_fd(padding_char, fd);
		--padding_len;
	}
	return (len);
}

int	print_sign(const char sign, int fd)
{
	ft_putchar_fd(sign, fd);
	return (1);
}

int	print_prefix(const char type, int fd)
{
	if (type == 'X')
		ft_putstr_fd("0X", fd);
	else
		ft_putstr_fd("0x", fd);
	return (2);
}

int	print_precision(int precision_zeros, int fd)
{
	int	len;

	len = precision_zeros;
	while (precision_zeros > 0)
	{
		ft_putchar_fd('0', fd);
		--precision_zeros;
	}
	return (len);
}
