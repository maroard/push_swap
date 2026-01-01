/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_min_max_extraction.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroard <maroard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 15:48:49 by maroard           #+#    #+#             */
/*   Updated: 2026/01/01 14:21:19 by maroard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_b(t_stack **A, t_stack **B)
{
	t_node	*current;
	int		i;
	int		j;

	if (is_extremum((*A)->top, *B, FALSE, TRUE))
		return (push_b(A, B));
	if (is_extremum((*A)->top, *B, TRUE, FALSE))
		return (push_b(A, B), rotate_b(B, FALSE));
	current = (*B)->top;
	i = 0;
	while (current && (*A)->top->content < current->content)
	{
		current = current->next;
		i++;
	}
	j = i;
	while (i--)
		rotate_b(B, FALSE);
	push_b(A, B);
	while (j--)
		reverse_rotate_b(B, FALSE);
}

static int	find_extremum(t_stack *A, t_bool min, t_bool max)
{
	t_node	*current;
	int		extremum;
	int		position;
	int		i;

	current = (A)->top;
	extremum = current->content;
	position = 0;
	i = 0;
	while (current)
	{
		if ((min && current->content < extremum)
			|| (max && current->content > extremum))
		{
			extremum = current->content;
			position = i;
		}
		current = current->next;
		i++;
	}
	return (position);
}
static int	chose_min_or_max(t_stack *A)
{
	int	pos_min;
	int	pos_max;
	int	cost_min;
	int	cost_max;

	pos_min = find_extremum(A, TRUE, FALSE);
	pos_max = find_extremum(A, FALSE, TRUE);
	if (pos_min <= A->size - pos_min)
		cost_min = pos_min;
	else
		cost_min = A->size - pos_min;
	if (pos_max <= A->size - pos_max)
		cost_max = pos_max;
	else
		cost_max = A->size - pos_max;
	if (cost_min <= cost_max)
		return (pos_min);
	return (pos_max);
}

static void	extract_a(t_stack **A, t_stack **B)
{
	int	i_to_extract;
	int	cost;
	int	i;

	i_to_extract = chose_min_or_max(*A);
	if (i_to_extract <= (*A)->size - i_to_extract)
		cost = i_to_extract;
	else
		cost = (*A)->size - i_to_extract;
	i = 0;
	while (i++ < cost)
	{
		if (i_to_extract <= (*A)->size - i_to_extract)
			rotate_a(A, FALSE);
		else
			reverse_rotate_a(A, FALSE);
	}
	return (sort_b(A, B));
}

void	simple_min_max_extraction(t_stack **A, t_stack **B)
{
	while ((*A)->top)
		extract_a(A, B);
	while ((*B)->top)
		push_a(A, B);
}
