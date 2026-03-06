/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_fd.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroard <maroard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 11:36:09 by maroard           #+#    #+#             */
/*   Updated: 2026/03/06 16:04:06 by maroard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_FD_H
# define FT_PRINTF_FD_H

# include "../../libft.h"
# include <stdarg.h>

typedef struct s_flags
{
	t_bool	minus;
	t_bool	zero;
	t_bool	dot;
	t_bool	hash;
	t_bool	space;
	t_bool	plus;
	int		precision;
	int		width;
	int		padding;
	int		skip;
}			t_flags;

typedef union u_arg
{
	char			c;
	char			*s;
	void			*p;
	int				i;
	unsigned int	u;
	double			f;
}					t_arg;

typedef struct s_len
{
	int	sign;
	int	prefix;
	int	precision_zeros;
	int	digits;
	int	padding;
}		t_len;

typedef struct s_ctx
{
	int		fd;
	t_flags	format;
	t_arg	arg;
	t_len	len;
}			t_ctx;

void	init_ctx(t_ctx *ctx, int fd);

t_bool	is_flag(const char c);
void	update_flags(t_flags *fmt, const char type);
char	parse_format(t_flags *fmt, const char *s);
void	flags_priorities(t_flags *fmt, const char type);
void	read_argument(const char type, t_arg *arg, va_list *arg_p);
void	compute_lengths(t_flags fmt, t_arg arg, const char type, t_len *len);

int		string_len_with_precision(t_bool dot_active, int precision, char *str);
int		int_len(int n);
int		unsigned_int_len(unsigned int n);
int		hex_len(unsigned long n);
int		ptr_len(void *ptr);

int		print_padding_fd(int padding_len, const char padding_char, int fd);
int		print_sign_fd(const char sign, int fd);
int		print_prefix_fd(const char type, int fd);
int		print_precision_fd(int precision_zeros, int fd);

int		print_str_fd(char *str, int fd);
int		print_str_n_fd(char *str, int n, int fd);
int		print_int_fd(int n, int fd);
int		print_unsigned_int_fd(unsigned int n, int fd);
int		print_hex_fd(unsigned long n, t_bool uppercase, int fd);
int		print_ptr_fd(void *ptr, int fd);
int		print_double_fd(double n, int fd);

int		ft_printf_fd(int fd, const char *s, ...);

#endif
