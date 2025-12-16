/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroard <maroard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 11:20:30 by maroard           #+#    #+#             */
/*   Updated: 2025/12/16 14:36:16 by maroard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <stdlib.h>

t_node	*create_node(int content)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->content = content;
	node->next = NULL;
	return (node);
}

t_node	*prev_last_node(t_node *top)
{
	while (top->next->next != NULL)
		top = top->next;
	return (top);
}

t_node	*last_node(t_node *top)
{
	while (top != NULL && top->next != NULL)
		top = top->next;
	return (top);
}

void	node_add_back(t_node **top, t_node *new)
{
	if (!top || !new)
		return ;
	if (!*top)
	{
		*top = new;
		return ;
	}
	last_node(*top)->next = new;
}

void	node_add_front(t_node **top, t_node *new)
{
	if (!new)
		return ;
	new->next = *top;
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

void	print_stack(t_node *top, char A_or_B)
{
	ft_printf("Stack %c:\n", A_or_B);
	while (top)
	{
		ft_printf("[ %d ]\n", top->content);
		top = top->next;
	}
}
