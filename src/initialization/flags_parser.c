/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroard <maroard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 16:17:50 by maroard           #+#    #+#             */
/*   Updated: 2026/03/02 16:52:11 by maroard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int flags_parser(int argc, char *argv[], t_ctx *ctx)
{
    int	i;

    i = 1;
    ctx->nb_flags = 0;
    ctx->strategy = ADAPTIVE;
    ctx->bench.is_active = FALSE;
    if (argc == 1 || (argc == 2 && !is_number(argv[1])))
        return (0);
    while (argv[i] && argv[i][0] == '-' && argv[i][1] == '-')
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
