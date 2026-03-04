/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_based_sorting.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroard <maroard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 11:31:02 by maroard           #+#    #+#             */
/*   Updated: 2026/03/04 13:59:35 by maroard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "math.h"

static t_bool	should_rotate(t_stack A_or_B, t_chunk chunk,
	t_bool extraction, t_bool injection)
{
	t_node	*current;
	int		i;
	int		j;

	current = A_or_B.top;
	i = 0;
	j = 0;
	while (current && ((extraction && !(current->index >= chunk.low
					&& current->index <= chunk.high))
			|| (injection && current->index != A_or_B.size - 1)))
	{
		current = current->next;
		++i;
	}
	current = last_node(A_or_B.top);
	while (current && ((extraction && !(current->index >= chunk.low
					&& current->index <= chunk.high))
			|| (injection && current->index != A_or_B.size - 1)))
	{
		current = current->prev;
		++j;
	}
	if (i <= j)
		return (TRUE);
	return (FALSE);
}

static void	injection(t_ctx *ctx, t_chunk chunk)
{
	while (ctx->b.top->index != ctx->b.size - 1)
	{
		if (ctx->b.size == 2 && ctx->b.top->index < ctx->b.top->next->index)
			swap_b(ctx, FALSE);
		else if (should_rotate(ctx->b, chunk, FALSE, TRUE))
			rotate_b(ctx, FALSE);
		else
			reverse_rotate_b(ctx, FALSE);
	}
	push_a(ctx);
}

static void	extraction(t_ctx *ctx, t_chunk *chunk)
{
	int	mid;

	mid = chunk->low + ((chunk->high - chunk->low) / 2);
	if (ctx->a.top->index >= chunk->low && ctx->a.top->index <= chunk->high)
	{
		push_b(ctx);
		++chunk->elements_extracted;
		if (ctx->b.top->index < mid)
			rotate_b(ctx, FALSE);
	}
	else if (should_rotate(ctx->a, *chunk, TRUE, FALSE))
		rotate_a(ctx, FALSE);
	else
		reverse_rotate_a(ctx, FALSE);
}

void	chunk_based_sorting(t_ctx *ctx)
{
	t_chunk	chunk;

	if (ctx->a.size == 100)
		chunk.size = 20;
	else if (ctx->a.size == 500)
		chunk.size = 42;
	else
		chunk.size = (int)sqrtf(ctx->a.size);
	chunk.high = chunk.size - 1;
	chunk.low = 0;
	chunk.elements_extracted = 0;
	indexation(ctx->a);
	while (ctx->a.top)
	{
		extraction(ctx, &chunk);
		if (chunk.elements_extracted == chunk.size)
		{
			chunk.high += chunk.size;
			chunk.low += chunk.size;
			chunk.elements_extracted = 0;
		}
	}
	while (ctx->b.top)
		injection(ctx, chunk);
}
