/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroard <maroard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 16:01:21 by maroard           #+#    #+#             */
/*   Updated: 2026/01/26 12:25:22 by maroard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_a(t_ctx *ctx)
{
	t_node	*temp;

	if (!ctx->b.top)
		return ;
	temp = ctx->b.top;
	ctx->b.top = ctx->b.top->next;
	if (ctx->b.top)
		ctx->b.top->prev = NULL;
	temp->next = NULL;
	temp->prev = NULL;
	node_add_front(&ctx->a.top, temp);
	++ctx->a.size;
	--ctx->b.size;
	logs_manager(ctx, PA);
}

void	push_b(t_ctx *ctx)
{
	t_node	*temp;

	if (!ctx->a.top)
		return ;
	temp = ctx->a.top;
	ctx->a.top = ctx->a.top->next;
	if (ctx->a.top)
		ctx->a.top->prev = NULL;
	temp->next = NULL;
	temp->prev = NULL;
	node_add_front(&ctx->b.top, temp);
	++ctx->b.size;
	--ctx->a.size;
	logs_manager(ctx, PB);
}
