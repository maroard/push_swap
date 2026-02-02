/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroard <maroard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 11:20:32 by maroard           #+#    #+#             */
/*   Updated: 2026/02/02 18:06:52 by maroard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

static void	algo_caller(t_ctx **ctx)
{
	if ((*ctx)->strategy == ADAPTIVE)
	{
		if ((*ctx)->disorder < 0.2)
			(*ctx)->strategy = SIMPLE;
		else if ((*ctx)->disorder >= 0.2 && (*ctx)->disorder < 0.5)
			(*ctx)->strategy = MEDIUM;
		else if ((*ctx)->disorder >= 0.5)
			(*ctx)->strategy = COMPLEX;
	}
	if ((*ctx)->strategy == SIMPLE)
		return (simple_min_max_extraction(*ctx));
	if ((*ctx)->strategy == MEDIUM)
		return (range_based_sorting(*ctx));
	if ((*ctx)->strategy == COMPLEX)
		return (radix_sort_adaptation_lsd(*ctx));
}

static int	initialization(int argc, char *argv[], t_ctx **ctx)
{	
	if (!strategy_selector(argc, argv, ctx))
		return (0);
	if (!create_stack(argc, argv, ctx))
		return (0);
	if (!occurence_checker((*ctx)->a))
		return (0);
	(*ctx)->disorder = compute_disorder((*ctx)->a);
	return (1);
}

int	main(int argc, char *argv[])
{
	t_ctx	*ctx;

	ctx = malloc(sizeof(t_ctx));
	if (!ctx || !initialization(argc, argv, &ctx))
	{
		ft_putstr_fd("Error\n", 0);
		return (-1);
	}
	ft_putstr_fd("OK\n\n", 1);
	if (!ctx->disorder)
		return (0);
	algo_caller(&ctx);
	// print_stack(ctx->a.top, 'A');
	// print_stack(ctx->b.top, 'B');
	clear_stack(&ctx->a.top);
	clear_stack(&ctx->b.top);
	if (ctx->bench.is_active)
		print_benchmark(*ctx);
	free(ctx);
	return (0);
}
