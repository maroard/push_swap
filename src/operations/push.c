/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroard <maroard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 16:01:21 by maroard           #+#    #+#             */
/*   Updated: 2026/01/01 15:55:05 by maroard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_a(t_stack **A, t_stack **B)
{
	t_node	*temp;

	if (!(*B)->top)
		return ;
	temp = (*B)->top;
	(*B)->top = (*B)->top->next;
	if ((*B)->top)
		(*B)->top->prev = NULL;
	temp->next = NULL;
	temp->prev = NULL;
	node_add_front(&((*A)->top), temp);
	(*A)->size++;
	(*B)->size--;
	ft_printf("pa\n");
}

void	push_b(t_stack **A, t_stack **B)
{
	t_node	*temp;

	if (!(*A)->top)
		return ;
	temp = (*A)->top;
	(*A)->top = (*A)->top->next;
	if ((*A)->top)
		(*A)->top->prev = NULL;
	temp->next = NULL;
	temp->prev = NULL;
	node_add_front(&((*B)->top), temp);
	(*B)->size++;
	(*A)->size--;
	ft_printf("pb\n");
}
