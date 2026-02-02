/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   benchmark.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroard <maroard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 12:49:36 by maroard           #+#    #+#             */
/*   Updated: 2026/02/02 16:12:11 by maroard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	logs_manager(t_ctx *ctx, t_op operation)
{
	char	*op_names[OP_COUNT] = {
		"sa", "sb", "ss",
		"pa", "pb",
		"ra", "rb", "rr",
		"rra", "rrb", "rrr"
	};

	if (!ctx->is_checker)
	{
		ft_printf("%s\n", op_names[operation]);
		ctx->bench.ops[operation]++;
		ctx->bench.total_ops++;
	}
}

void	print_benchmark(t_ctx ctx)
{
	char	*strat_names[4] = {
		"Simple",
		"Medium",
		"Complex",
		"Adaptive"
	};
	ft_printf_fd(2, "[BENCHMARK] Disorder: %f%%\n", ctx.disorder * 100);
	ft_printf_fd(2, "[BENCHMARK] Strategy: %s\n", strat_names[ctx.strategy]);
	ft_printf_fd(2, "[BENCHMARK] Total operations: %d\n", ctx.bench.total_ops);
	ft_printf_fd(2, "[BENCHMARK] sa: %d sb: %d ss: %d pa: %d pb: %d\n",
		ctx.bench.ops[0], ctx.bench.ops[1], ctx.bench.ops[2],
		ctx.bench.ops[3], ctx.bench.ops[4]);
	ft_printf_fd(2, "[BENCHMARK] ra: %d rb: %d rr: %d rra: %d rrb: %d rrr: %d\n",
		ctx.bench.ops[5], ctx.bench.ops[6], ctx.bench.ops[7],
		ctx.bench.ops[8], ctx.bench.ops[9], ctx.bench.ops[10]);
}
