/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroard <maroard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 14:31:04 by maroard           #+#    #+#             */
/*   Updated: 2026/02/03 12:27:29 by maroard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

static int	dispatcher(char *op, t_ctx **ctx)
{
	if (!ft_strcmp(op, "sa"))
		swap_a(*ctx, FALSE);
	else if (!ft_strcmp(op, "sb"))
		swap_b(*ctx, FALSE);
	else if (!ft_strcmp(op, "ss"))
		swap_swap(*ctx);
	else if (!ft_strcmp(op, "pa"))
		push_a(*ctx);
	else if (!ft_strcmp(op, "pb"))
		push_b(*ctx);
	else if (!ft_strcmp(op, "ra"))
		rotate_a(*ctx, FALSE);
	else if (!ft_strcmp(op, "rb"))
		rotate_b(*ctx, FALSE);
	else if (!ft_strcmp(op, "rr"))
		rotate_rotate(*ctx);
	else if (!ft_strcmp(op, "rra"))
		reverse_rotate_a(*ctx, FALSE);
	else if (!ft_strcmp(op, "rrb"))
		reverse_rotate_b(*ctx, FALSE);
	else if (!ft_strcmp(op, "rrr"))
		reverse_rotate_rotate(*ctx);
	else
		return (0);
	return (1);
}

static int	reader(t_ctx **ctx)
{
	char	*op;

	while (1)
	{
		op = get_next_line(1);
		if (!op)
			break ;
		if (!dispatcher(op, ctx))
			return (free(op), 0);
		free(op);
	}
	free(op);
	return (1);
}

static int	initialization(int argc, char *argv[], t_ctx **ctx)
{
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
	ctx->is_checker = TRUE;
	if (!ctx || !initialization(argc, argv, &ctx) || !reader(&ctx))
	{
		ft_putstr_fd("Error", 2);
		free(ctx);
		return (-1);
	}
	if (compute_disorder(ctx->a) > 0 || ctx->b.size > 0)
	{
		ft_putstr("KO");
		free(ctx);
		return (0);
	}
	ft_putstr("OK");
	clear_stack(&ctx->a.top);
	free(ctx);
	return (0);
}
