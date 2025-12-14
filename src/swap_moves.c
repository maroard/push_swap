/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroard <maroard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 16:01:23 by maroard           #+#    #+#             */
/*   Updated: 2025/12/11 17:47:08 by maroard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	swap_A(t_stack **A)
{
	t_node	*temp;

	if (!A || !(*A)->top || !(*A)->top->next)
		return (0);
	temp = malloc(sizeof(t_node));
	if (!temp)
	{
		free(temp);
		return (0);
	}
	temp = (*A)->top;
	(*A)->top = (*A)->top->next;
	(*A)->top->next = temp;
	ft_printf("sa\n");
	return (1);
}

int	swap_B(t_stack **B)
{
	t_node	*temp;

	if (!B || !(*B)->top || !(*B)->top->next)
		return (0);
	temp = malloc(sizeof(t_node));
	if (!temp)
	{
		free(temp);
		return (0);
	}
	temp = (*B)->top;
	(*B)->top = (*B)->top->next;
	(*B)->top->next = temp;
	ft_printf("sb\n");
	return (1);
}

int	swap_swap(t_stack **A, t_stack **B)
{
	if ((!A || !(*A)->top || !(*A)->top->next) || (!B || !(*B)->top || !(*B)->top->next))
		return (0);
	swap_A(&A);
	swap_B(&B);
	return (1);
}
