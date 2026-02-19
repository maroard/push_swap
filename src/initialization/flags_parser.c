/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroard <maroard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 16:17:50 by maroard           #+#    #+#             */
/*   Updated: 2026/02/19 18:43:36 by maroard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int flags_parser(int argc, char *argv[], t_ctx *ctx)
{
    int	i;

    i = 1;
	ctx->nb_flags = 0;
    ctx->strategy = ADAPTIVE;
    if (argc == 1 || (argc == 2 && !is_number(argv[1])))
        return (0);
    while (i <= 2)
    {
        if (!ft_strcmp("--simple", argv[i]))
            ctx->strategy = SIMPLE;
        else if (!ft_strcmp("--medium", argv[i]))
            ctx->strategy = MEDIUM;
        else if (!ft_strcmp("--complex", argv[i]))
            ctx->strategy = COMPLEX;
        else if (!ft_strcmp("--bench", argv[i]))
            ctx->bench.is_active = TRUE;
        else if (!is_number(argv[i]) && ft_strcmp("--adaptive", argv[i]))
            return (0);
        ctx->nb_flags + 1;
        ++i;
    }
    return (1);
}
