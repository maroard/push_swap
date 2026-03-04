/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_min_extraction.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroard <maroard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 15:48:49 by maroard           #+#    #+#             */
/*   Updated: 2026/03/02 19:55:51 by maroard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_bool	should_rotate(t_stack A)
{
	t_node	*current;
	int		i;
	int		j;

	current = A.top;
	i = 0;
	j = 0;
	while (current->index != 0)
	{
		current = current->next;
		++i;
	}
	current = last_node(A.top);
	while (current->index != 0)
	{
		current = current->prev;
		++j;
	}
	if (j < i)
		return (FALSE);
	return (TRUE);
}

static void	extract_a(t_ctx *ctx)
{
	t_node	*to_extract;

	indexation(ctx->a);
	to_extract = ctx->a.top;
	while (to_extract->index != 0)
		to_extract = to_extract->next;
	while (ctx->a.top->index != to_extract->index)
	{
		if (should_rotate(ctx->a))
			rotate_a(ctx, FALSE);
		else
			reverse_rotate_a(ctx, FALSE);
	}
	push_b(ctx);
}

void	simple_min_extraction(t_ctx *ctx)
{
	while (ctx->a.top)
		extract_a(ctx);
	while (ctx->b.top)
		push_a(ctx);
}
