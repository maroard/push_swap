/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroard <maroard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 16:42:39 by maroard           #+#    #+#             */
/*   Updated: 2026/03/02 19:11:24 by maroard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_ctx *ctx, t_bool rr)
{
	t_node	*temp;

	if (!ctx->a.top || !ctx->a.top->next)
		return ;
	temp = ctx->a.top;
	ctx->a.top = ctx->a.top->next;
	ctx->a.top->prev = NULL;
	temp->next = NULL;
	temp->prev = NULL;
	node_add_back(&ctx->a.top, temp);
	if (rr == FALSE)
		logs_manager(ctx, RA);
}

void	rotate_b(t_ctx *ctx, t_bool rr)
{
	t_node	*temp;

	if (!ctx->b.top || !ctx->b.top->next)
		return ;
	temp = ctx->b.top;
	ctx->b.top = ctx->b.top->next;
	ctx->b.top->prev = NULL;
	temp->next = NULL;
	temp->prev = NULL;
	node_add_back(&ctx->b.top, temp);
	if (rr == FALSE)
		logs_manager(ctx, RB);
}

void	rotate_rotate(t_ctx *ctx)
{
	rotate_a(ctx, TRUE);
	rotate_b(ctx, TRUE);
	logs_manager(ctx, RR);
}
