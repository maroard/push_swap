/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroard <maroard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 11:20:32 by maroard           #+#    #+#             */
/*   Updated: 2025/12/11 11:27:18 by maroard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <stdlib.h>

// void	push_swap(int **stack_A)
// {

// }

int	push_swap_init(int argc, char *argv[])
{
	t_stack	*stack_A;
	
	stack_A = create_stack_A(argc, argv);
	if (!stack_A)
		return (0);
	print_stack(stack_A->top);
	clear_stack(&(stack_A->top), stack_A);
	return (1);
}

int main(int argc, char *argv[])
{
	if (argc == 1 || push_swap_init(argc, argv) == 0)
	{
		ft_putstr_fd("Error\n", 0);
		return (0);
	}
	ft_putstr_fd("OK\n", 1);
	return (0);
}
