/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_moves.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroard <maroard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 14:14:40 by maroard           #+#    #+#             */
/*   Updated: 2025/12/16 14:44:10 by maroard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	reverse_rotate_A(t_stack **A, int rrr)
{
	t_node	*temp;

	if (!(*A) || !(*A)->top || !(*A)->top->next)
		return (0);
	temp = last_node((*A)->top);
	prev_last_node((*A)->top)->next = NULL;
	node_add_front(&((*A)->top), temp);
	if (rrr == 0)
		ft_printf("rra\n");
	return (1);
}

int reverse_rotate_B(t_stack **B, int rrr)
{
	t_node	*temp;

	if (!(*B) || !(*B)->top || !(*B)->top->next)
		return (0);
	prev_last_node((*B)->top)->next = NULL;
	node_add_front(&((*B)->top), temp);
	if (rrr == 0)
		ft_printf("rrb\n");
	return (1);
}

int	reverse_rotate_rotate(t_stack **A, t_stack **B)
{
	if ((!(*A) || !(*A)->top || !(*A)->top->next) || (!(*B) || !(*B)->top || !(*B)->top->next))
		return (0);
	reverse_rotate_A(&(*A), 1);
	reverse_rotate_B(&(*B), 1);
	ft_printf("rrr\n");
	return (1);
}
