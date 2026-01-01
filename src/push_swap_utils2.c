/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroard <maroard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 16:07:01 by maroard           #+#    #+#             */
/*   Updated: 2026/01/01 15:31:07 by maroard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_node *top, char A_or_B)
{
	ft_printf("Stack %c:\n", A_or_B);
	while (top)
	{
		ft_printf("[ %d ] (%d)\n", top->content, top->index);
		top = top->next;
	}
}

int	is_number(char *arg)
{
	size_t	i;

	i = 0;
	while ((arg[i] >= 9 && arg[i] <= 13) || arg[i] == ' ')
		i++;
	if (!arg[i])
		return (0);
	if (arg[i] == '-' || arg[i] == '+')
		i++;
	if (!arg[i])
		return (0);
	while (arg[i])
	{
		if (ft_isdigit(arg[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

int	is_extremum(t_node *to_check ,t_stack *A_or_B, t_bool min, t_bool max)
{
	t_node	*checker;

	if (!(A_or_B)->top)
		return (1);
	checker = A_or_B->top;
	while (checker)
	{
		if ((min == TRUE && to_check->content > checker->content)
			|| (max == TRUE && to_check->content < checker->content))
			return (0);
		checker = checker->next;
	}
	return (1);
}

void	indexation(t_stack *A_or_B)
{
	t_node	*current;
	t_node	*checker;

	current = A_or_B->top;
	while (current)
	{
		current->index = 0;
		current = current->next;
	}
	current = A_or_B->top;
	while (current)
	{
		checker = A_or_B->top;
		while (checker)
		{
			if (checker->content < current->content)
				current->index++;
			checker = checker->next;
		}
		current = current->next;
	}
}
 