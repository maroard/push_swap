/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort_adaptation_LSD.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroard <maroard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 16:45:39 by maroard           #+#    #+#             */
/*   Updated: 2026/01/26 13:06:03 by maroard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_nb_bits_max_index(t_stack A)
{
	int	index_max;
	int	count;

	index_max = A.size - 1;
	count = 0;
	while (index_max != 0)
	{
		index_max = index_max >> 1;
		++count;
	}
	return (count);
}

void	radix_sort_adaptation_lsd(t_ctx *ctx)
{
	int	i;
	int	k;
	int	nb_rounds;
	int	nb_elements;

	k = 0;
	nb_rounds = find_nb_bits_max_index(ctx->a);
	nb_elements = ctx->a.size;
	indexation(ctx->a);
	while (nb_rounds--)
	{
		i = 0;
		while (i++ < nb_elements)
		{
			if (((ctx->a.top->index >> k) & 1) == 1)
				rotate_a(ctx, FALSE);
			else
				push_b(ctx);
		}
		while (ctx->b.top)
			push_a(ctx);
		k++;
	}
}
