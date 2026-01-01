/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   range_based_sorting.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroard <maroard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 11:31:02 by maroard           #+#    #+#             */
/*   Updated: 2026/01/01 17:26:30 by maroard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "math.h"

static t_bool	should_rotate(t_stack *A_or_B, int range_size, t_bool extraction, t_bool injection)
{
	t_node	*current;
	int		i;
	int		j;

	current = A_or_B->top;
	i = 0;
	j = 0;
	while (current && ((extraction && !(current->index < range_size))
		|| (injection && current->index != A_or_B->size - 1)))
	{
		current = current->next;
		i++;
	}
	current = last_node(A_or_B->top);
	while (current && ((extraction && !(current->index < range_size))
		|| (injection && current->index != A_or_B->size - 1)))
	{
		current = current->prev;
		j++;
	}
	if (i <= j)
		return (TRUE);
	return (FALSE);
}

static void	injection(t_stack **A, t_stack **B)
{
	t_bool	rotate;
	int		i;

	rotate = should_rotate((*B), 0, FALSE, TRUE);
	i = 0;
	while ((*B)->top->index != (*B)->size - 1)
	{
		if ((*B)->size == 2 && (*B)->top->index < (*B)->top->next->index)
			swap_b(B, FALSE);
		else if (rotate)
			rotate_b(B, FALSE);
		else
			reverse_rotate_b(B, FALSE);
		i++;
	}
	push_a(A, B);
	while ((*B)->size > 2 && i--)
	{
		if (rotate)
			reverse_rotate_b(B, FALSE);
		else
			rotate_b(B, FALSE);	
	}
}

static void	extraction(t_stack **A, t_stack **B, int range_size)
{
	if ((*B)->size / range_size >= 1)
		indexation(*A);
	if ((*A)->top->index < range_size)
		push_b(A, B);
	else if (should_rotate((*A), range_size, TRUE, FALSE))
		rotate_a(A, FALSE);
	else
		reverse_rotate_a(A, FALSE);
}

void	range_based_sorting(t_stack **A, t_stack **B)
{
	int	range_size;

	range_size = (int)sqrtf((*A)->size);
	indexation(*A);
	while ((*A)->top)
		extraction(A, B, range_size);
	indexation(*B);
	while ((*B)->top)
		injection(A, B);
}
