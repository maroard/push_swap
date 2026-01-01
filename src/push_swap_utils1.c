/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroard <maroard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 11:20:30 by maroard           #+#    #+#             */
/*   Updated: 2026/01/01 16:07:39 by maroard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

t_node	*create_node(int content)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->content = content;
	node->index = 0;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

t_node	*last_node(t_node *top)
{
	while (top != NULL && top->next != NULL)
		top = top->next;
	return (top);
}

void	node_add_back(t_node **top, t_node *new)
{
	t_node	*last;

	if (!top || !new)
		return ;
	if (!*top)
	{
		new->prev = NULL;
		new->next = NULL;
		*top = new;
		return ;
	}
	last = last_node(*top);
	last->next = new;
	new->prev = last;
	new->next = NULL;
}

void	node_add_front(t_node **top, t_node *new)
{
	if (!top || !new)
		return ;
	new->prev = NULL;
	new->next = *top;
	if (*top)
		(*top)->prev = new;
	*top = new;
}

void	*clear_stack(t_node **top, t_stack *A_or_B)
{
	t_node	*temp;

	while (*top)
	{
		temp = (*top)->next;
		free(*top);
		*top = temp;
	}
	free(A_or_B);
	return (NULL);
}
