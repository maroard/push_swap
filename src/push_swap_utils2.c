/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroard <maroard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 16:07:01 by maroard           #+#    #+#             */
/*   Updated: 2025/12/22 18:53:10 by maroard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_node *top, char A_or_B)
{
	ft_printf("Stack %c:\n", A_or_B);
	while (top)
	{
		ft_printf("[ %d ]\n", top->content);
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

int	top_is_extremum(t_stack *A_or_B, t_bool min, t_bool max)
{
	t_node	*check;

	if (!(A_or_B->top->next))
		return (1);
	check = A_or_B->top->next;
	while (check)
	{
		if ((min == TRUE && A_or_B->top->content > check->content)
			|| (max == TRUE && A_or_B->top->content < check->content))
			return (0);
		check = check->next;
	}
	return (1);
}

int	stack_a_is_sorted(t_stack *A, t_stack *B)
{
	t_node	*check;

	if (!A->top || !A->top->next || B->top)
		return (0);
	check = (A)->top;
	while (check->next)
	{
		if (check->content > check->next->content)
			return (0);
		check = check->next;
	}
	return (1);
}
