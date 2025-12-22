/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroard <maroard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 14:14:40 by maroard           #+#    #+#             */
/*   Updated: 2025/12/22 13:25:05 by maroard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	reverse_rotate_a(t_stack **a, t_bool rrr)
{
	t_node	*temp;

	if (!(*a) || !(*a)->top || !(*a)->top->next)
		return (0);
	temp = last_node((*a)->top);
	(last_node((*a)->top)->prev)->next = NULL;
	node_add_front(&((*a)->top), temp);
	if (rrr == FALSE)
		ft_printf("rra\n");
	return (1);
}

int	reverse_rotate_b(t_stack **b, t_bool rrr)
{
	t_node	*temp;

	if (!(*b) || !(*b)->top || !(*b)->top->next)
		return (0);
	temp = last_node((*b)->top);
	(last_node((*b)->top)->prev)->next = NULL;
	node_add_front(&((*b)->top), temp);
	if (rrr == FALSE)
		ft_printf("rrb\n");
	return (1);
}

int	reverse_rotate_rotate(t_stack **a, t_stack **b)
{
	if ((!(*a) || !(*a)->top || !(*a)->top->next)
		|| (!(*b) || !(*b)->top || !(*b)->top->next))
		return (0);
	reverse_rotate_a(a, TRUE);
	reverse_rotate_b(b, TRUE);
	ft_printf("rrr\n");
	return (1);
}
