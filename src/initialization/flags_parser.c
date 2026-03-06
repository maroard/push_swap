/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroard <maroard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 16:17:50 by maroard           #+#    #+#             */
/*   Updated: 2026/03/06 15:13:17 by maroard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	flags_parser(int argc, char *argv[], t_ctx *ctx)
{
	int	i;

	i = 1;
	ctx->strategy = ADAPTIVE;
	if (!is_number(argv[argc - 1]) && !ft_strchr(argv[argc - 1], ' '))
		return (0);
	while (argv[i][0] == '-' && argv[i][1] == '-')
	{
		if (!ft_strcmp("--simple", argv[i]))
			ctx->strategy = SIMPLE;
		else if (!ft_strcmp("--medium", argv[i]))
			ctx->strategy = MEDIUM;
		else if (!ft_strcmp("--complex", argv[i]))
			ctx->strategy = COMPLEX;
		else if (!ft_strcmp("--bench", argv[i]))
			ctx->bench.is_active = TRUE;
		else if (ft_strcmp("--adaptive", argv[i]))
			return (0);
		++ctx->nb_flags;
		++i;
	}
	return (1);
}
