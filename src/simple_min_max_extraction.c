/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_min_max_extraction.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroard <maroard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 15:48:49 by maroard           #+#    #+#             */
/*   Updated: 2025/12/16 17:27:30 by maroard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	find_min(t_stack **A)
{
	t_node	*current;
	t_node	*check;
	int		i;

	current = (*A)->top;
	i = 0;
	while (current)
	{
		check = (*A)->top;
		while (check)
		{
			if (current->content > check->content)
				break;
			if (!check->next && (current->content < check->content))
				return (i);
			check = check->next;
			i++;
		}
		current = current->next;
	}
	return (0);
}

static int	find_max(t_stack **A)
{
	t_node	*current;
	t_node	*check;
	int		i;

	current = (*A)->top;
	i = 0;
	while (current)
	{
		check = (*A)->top;
		while (check)
		{
			if (current->content < check->content)
				break;
			if (!check->next && (current->content > check->content))
				return (i);
			check = check->next;
			i++;
		}
		current = current->next;
	}
	return (0);
}

static int	chose_min_or_max(t_stack **A)
{
	int		min_position;
	int		max_position;

	min_position = find_min(&(*A));
	max_position = find_max(&(*A));
	if (((*A)->size / 2) - min_position >= ((*A)->size / 2) - max_position)
		return (min_position);
	return (max_position);
}

void	reinjection(t_stack **A, t_stack **B)
{
	
}

void	extraction(t_stack **A, t_stack **B)
{
	int	i_to_extract;
	int	i;

	i_to_extract = chose_min_or_max(&(*A));
	if (i_to_extract <= (*A)->size / 2)
		i = 0;
	else
		i = (*A)->size / 2;
	while (i < i_to_extract)
	{
		if (i_to_extract <= (*A)->size / 2)
			rotate_A(&(*A), 0);
		else
			reverse_rotate_A(&(*A), 0);
		i++;
	}
	push_B(&(*A), &(*B));
}
