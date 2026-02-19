/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   special_cases.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroard <maroard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 15:40:03 by maroard           #+#    #+#             */
/*   Updated: 2026/02/18 15:43:24 by maroard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    sort_3_elements(t_ctx *ctx)
{
	if (is_extremum(ctx->a.top, ctx->a, FALSE, TRUE))
	{
		if (is_extremum(ctx->a.top->next, ctx->a, TRUE, FALSE))
			return (rotate_a(ctx, FALSE));
		return (rotate_a(ctx, FALSE), swap_a(ctx, FALSE));
	}
	if (is_extremum(ctx->a.top, ctx->a, TRUE, FALSE))
		return (swap_a(ctx, FALSE), rotate_a(ctx, FALSE));
	if (is_extremum(ctx->a.top->next, ctx->a, TRUE, FALSE))
		return (swap_a(ctx, FALSE));
	return (reverse_rotate_a(ctx, FALSE));
}

static t_bool	should_rotate(t_stack A)
{
	t_node	*current;
	int		i;
	int		j;

	current = A.top;
	i = 0;
	j = 0;
	while (current->index != 0 && current->index != 1)
	{
		current = current->next;
		++i;
	}
	current = last_node(A.top);
	while (current->index != 0 && current->index != 1)
	{
		current = current->prev;
		++j;
	}
	if (j < i)
		return (FALSE);
	return (TRUE);
}

void    sort_5_elements(t_ctx *ctx)
{
	indexation(ctx->a);
	while (ctx->a.size > 3)
	{
		if (compute_disorder(ctx->a) == 0 && !ctx->b.top)
			return ;
		if (compute_disorder(ctx->a) == 0 && ctx->b.size == 1)
			return (push_a(ctx));
		if (ctx->a.top->index == 0 || ctx->a.top->index == 1)
			push_b(ctx);
		else if (should_rotate(ctx->a))
			rotate_a(ctx, FALSE);
		else
			reverse_rotate_a(ctx, FALSE);
	}
	if (compute_disorder(ctx->a) != 0)
		sort_3_elements(ctx);
	if (ctx->b.top->index < ctx->b.top->next->index)
		swap_b(ctx, FALSE);
	push_a(ctx);
	push_a(ctx);
}
