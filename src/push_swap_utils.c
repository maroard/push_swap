/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroard <maroard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 11:20:30 by maroard           #+#    #+#             */
/*   Updated: 2025/12/11 12:05:46 by maroard          ###   ########.fr       */
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

t_node	*last_node(t_node *list)
{
	while (list != NULL && list->next != NULL)
		list = list->next;
	return (list);
}

void	node_add_back(t_node **list, t_node *new)
{
	if (!list || !new)
		return ;
	if (!*list)
	{
		*list = new;
		return ;
	}
	last_node(*list)->next = new;
}

t_stack	*clear_stack(t_node **top, t_stack *stack)
{
	t_node	*temp;

	while (*top != NULL)
	{
		temp = (*top)->next;
		free(*top);
		*top = temp;
	}
	free(stack);
	return (NULL);
}

void	print_stack(t_node *list)
{
	ft_printf("Stack A:\n");
	while (list != NULL)
	{
		ft_printf("[ %d ]\n", list->content);
		list = list->next;
	}
}
