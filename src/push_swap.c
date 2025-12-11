/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroard <maroard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 11:20:32 by maroard           #+#    #+#             */
/*   Updated: 2025/12/11 15:23:48 by maroard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <stdlib.h>
#include <stdio.h>

float	compute_disorder(t_stack *A)
{
	t_node	*current;
	t_node	*next;
	float	mistakes;
	float	total_pairs;

	if (!A || !A->top || !A->top->next)
		return (0);
	current = A->top;
	next = current->next;
	mistakes = 0;
	total_pairs = 0;
	while (current)
	{
		next = current->next;
		while (next)
		{
			total_pairs++;
			if (current->content > next->content)
				mistakes++;
			next = next->next;
		}
		current = current->next;
	}
	return (mistakes / total_pairs);
}

int	push_swap_init(int argc, char *argv[], t_stack **A)
{
	t_node	*current;
	t_node	*next;
	
	*A = create_stack_A(argc, argv);
	if (!A)
		return (0);
	current = (*A)->top;
	while (current)
	{
		next = current->next;
		while (next)
		{
			if (current->content == next->content)
				return (0);
			next = next->next;
		}
		current = current->next;
	}
	print_stack((*A)->top);
	return (1);
}

int main(int argc, char *argv[])
{
	t_stack	*A;

	if (argc == 1 || !push_swap_init(argc, argv, &A))
	{
		ft_putstr_fd("Error\n", 0);
		clear_stack(&(A->top), A);
		return (0);
	}
	printf("\nDisorder: %f\n", compute_disorder(A));
	ft_putstr_fd("OK\n", 1);
	clear_stack(&(A->top), A);
	return (0);
}
