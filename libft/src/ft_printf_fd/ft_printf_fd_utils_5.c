/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_fd_utils_5.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroard <maroard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 12:04:53 by maroard           #+#    #+#             */
/*   Updated: 2026/02/01 18:36:55 by maroard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_fd.h"

int	print_str(char *str, int fd)
{
	int	len;

	len = 0;
	if (!str)
	{
		ft_putstr_fd("(null)", fd);
		return (6);
	}
	while (*str)
	{
		ft_putchar_fd(*str++, fd);
		++len;
	}
	return (len);
}

int	print_str_n(char *str, int n, int fd)
{
	int		len;

	len = 0;
	if (!str)
	{
		if (n < (int)ft_strlen("(null)"))
			return (0);
		return (print_str("(null)", fd));
	}
	while (*str && n > 0)
	{
		ft_putchar_fd(*str++, fd);
		--n;
		++len;
	}
	return (len);
}

int	print_int(int n, int fd)
{
	long long	nb;
	int			len;

	nb = n;
	len = 0;
	if (nb < 0)
		nb = -nb;
	if (nb >= 10)
	{
		len += print_int((int)(nb / 10), fd);
		nb = nb % 10;
	}
	ft_putchar_fd(nb + '0', fd);
	return (len + 1);
}

int	print_unsigned_int(unsigned int n, int fd)
{
	int	len;

	len = 0;
	if (n >= 10)
	{
		len = print_unsigned_int(n / 10, fd);
		n = n % 10;
	}
	ft_putchar_fd(n + '0', fd);
	return (len + 1);
}

int	print_hex(unsigned long n, t_bool uppercase, int fd)
{
	int	len;

	len = 0;
	if (n >= 16)
	{
		len = print_hex(n / 16, uppercase, fd);
		n = n % 16;
	}
	if (n <= 9)
		ft_putchar_fd(n + '0', fd);
	else if (n >= 10 && n <= 15 && uppercase)
		ft_putchar_fd(n + 'A' - 10, fd);
	else if (n >= 10 && n <= 15 && !uppercase)
		ft_putchar_fd(n + 'a' - 10, fd);
	return (len + 1);
}
