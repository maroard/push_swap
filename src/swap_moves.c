/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroard <maroard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 16:01:23 by maroard           #+#    #+#             */
/*   Updated: 2025/12/16 14:12:02 by maroard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <stdlib.h>

int	swap_A(t_stack **A, int ss)
{
	t_node	*temp;

	if (!(*A) || !(*A)->top || !(*A)->top->next)
		return (0);
	temp = (*A)->top;
	(*A)->top = (*A)->top->next;
	(*A)->top->next = temp;
	if (ss == 0)
		ft_printf("sa\n");
	return (1);
}

int	swap_B(t_stack **B, int ss)
{
	t_node	*temp;

	if (!(*B) || !(*B)->top || !(*B)->top->next)
		return (0);
	temp = (*B)->top;
	(*B)->top = (*B)->top->next;
	(*B)->top->next = temp;
	if (ss == 0)
		ft_printf("sb\n");
	return (1);
}

int	swap_swap(t_stack **A, t_stack **B)
{
	if ((!(*A) || !(*A)->top || !(*A)->top->next) || (!(*B) || !(*B)->top || !(*B)->top->next))
		return (0);
	swap_A(&(*A), 1);
	swap_B(&(*B), 1);
	ft_printf("ss\n");
	return (1);
}
