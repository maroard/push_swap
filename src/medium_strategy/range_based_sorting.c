/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   range_based_sorting.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroard <maroard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 11:31:02 by maroard           #+#    #+#             */
/*   Updated: 2026/01/26 12:24:53 by maroard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "math.h"

static t_bool	should_rotate(t_stack A_or_B, int range_size, t_bool extraction, t_bool injection)
{
	t_node	*current;
	int		i;
	int		j;

	current = A_or_B.top;
	i = 0;
	j = 0;
	while (current && ((extraction && !(current->index < range_size))
		|| (injection && current->index != A_or_B.size - 1)))
	{
		current = current->next;
		++i;
	}
	current = last_node(A_or_B.top);
	while (current && ((extraction && !(current->index < range_size))
		|| (injection && current->index != A_or_B.size - 1)))
	{
		current = current->prev;
		++j;
	}
	if (i <= j)
		return (TRUE);
	return (FALSE);
}

static void	injection(t_ctx *ctx)
{
	t_bool	rotate;
	int		i;

	rotate = should_rotate(ctx->b, 0, FALSE, TRUE);
	i = 0;
	while (ctx->b.top->index != ctx->b.size - 1)
	{
		if (ctx->b.size == 2 && ctx->b.top->index < ctx->b.top->next->index)
			swap_b(ctx, FALSE);
		else if (rotate)
			rotate_b(ctx, FALSE);
		else
			reverse_rotate_b(ctx, FALSE);
		++i;
	}
	push_a(ctx);
	while (ctx->b.size > 2 && i--)
	{
		if (rotate)
			reverse_rotate_b(ctx, FALSE);
		else
			rotate_b(ctx, FALSE);	
	}
}

static void	extraction(t_ctx *ctx, int range_size)
{
	if (ctx->b.size / range_size >= 1)
		indexation(ctx->a);
	if (ctx->a.top->index < range_size)
		push_b(ctx);
	else if (should_rotate(ctx->a, range_size, TRUE, FALSE))
		rotate_a(ctx, FALSE);
	else
		reverse_rotate_a(ctx, FALSE);
}

void	range_based_sorting(t_ctx *ctx)
{
	int	range_size;

	range_size = (int)sqrtf(ctx->a.size);
	indexation(ctx->a);
	while (ctx->a.top)
		extraction(ctx, range_size);
	indexation(ctx->b);
	while (ctx->b.top)
		injection(ctx);
}
