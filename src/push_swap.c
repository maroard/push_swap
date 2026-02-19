/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroard <maroard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 11:20:32 by maroard           #+#    #+#             */
/*   Updated: 2026/02/19 18:35:19 by maroard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

static void	algo_caller(t_ctx *ctx)
{
	if (ctx->a.size == 3)
		return (ctx->bench.complexity = 0, sort_3_elements(ctx));
	if (ctx->a.size == 5)
		return (ctx->bench.complexity = 0, sort_5_elements(ctx));
	if (ctx->strategy == SIMPLE
		|| (ctx->strategy == ADAPTIVE && ctx->disorder < 0.2))
		return (ctx->bench.complexity = 1, simple_min_max_extraction(ctx));
	if (ctx->strategy == MEDIUM
		|| (ctx->strategy == ADAPTIVE && ctx->disorder >= 0.2 && (ctx)->disorder < 0.5))
		return (ctx->bench.complexity = 2, range_based_sorting(ctx));
	if (ctx->strategy == COMPLEX 
		|| (ctx->strategy == ADAPTIVE && ctx->disorder >= 0.5))
		return (ctx->bench.complexity = 3, radix_sort_adaptation_lsd(ctx));
}

static int	initialization(int argc, char *argv[], t_ctx *ctx)
{	
	if (!flags_parser(argc, argv, ctx))
		return (0);
	if (!create_stack_a(argc, argv, ctx))
		return (0);
	if (!occurence_checker(ctx->a))
		return (0);
	ctx->disorder = compute_disorder(ctx->a);
	return (1);
}

int	main(int argc, char *argv[])
{
	t_ctx	*ctx;

	ctx = malloc(sizeof(t_ctx));
	if (!ctx || !initialization(argc, argv, ctx))
	{
		ft_putstr_fd("Error\n", 0);
		free(ctx);
		return (-1);
	}
	ft_putstr_fd("OK\n\n", 1);
	if (!ctx->disorder)
		return (0);
	algo_caller(ctx);
	ft_printf("strategy: %d\n", ctx->strategy);
	print_stack(ctx->a.top, 'A');
	clear_stack(&ctx->a.top);
	clear_stack(&ctx->b.top);
	if (ctx->bench.is_active)
		print_benchmark(*ctx);
	free(ctx);
	return (0);
}
