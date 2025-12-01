/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroard <maroard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 11:20:32 by maroard           #+#    #+#             */
/*   Updated: 2025/12/01 19:03:26 by maroard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

// void	push_swap(int **stack_A)
// {
	
// }

int main(int argc, char *argv[])
{
	t_stack	*stack_A;

	if (argc == 1)
		return (0);
	create_stack_A(argc, argv, &stack_A);
	if (!stack_A)
	{
		ft_putstr_fd("Error\n", 0);
		free(stack_A);
		return (0);
	}
	ft_putstr_fd("OK\n", 1);
	// push_swap(&stack_A);
	free(stack_A);
	return (0);
}
