/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroard <maroard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 11:20:32 by maroard           #+#    #+#             */
/*   Updated: 2026/01/01 17:43:51 by maroard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>

static void	algo_caller(t_stack **a, t_stack **b, int strategy)
{
	float	disorder;

	disorder = compute_disorder(*a);
	if (strategy == ADAPTIVE)
	{
		if (disorder < 0.2)
			strategy = SIMPLE;
		else if (disorder >= 0.2 && disorder < 0.5)
			strategy = MEDIUM;
		else if (disorder >= 0.5)
			strategy = COMPLEX;
	}
	if (strategy == SIMPLE)
		return (simple_min_max_extraction(a, b));
	if (strategy == MEDIUM)
		return (range_based_sorting(a, b));
	if (strategy == COMPLEX)
		return (radix_sort_adaptation_lsd(a, b));
}

static int	init(int argc, char *argv[], t_stack **a, t_stack **b)
{
	*a = create_stack_a(argc, argv);
	if (!(*a) || !occurence_checker(*a))
		return (0);
	*b = malloc(sizeof(a));
	if (!(*b))
		return (0);
	return (1);
}

int	main(int argc, char *argv[])
{
	t_strat	strategy;
	t_stack	*a;
	t_stack *b;

	if (!strategy_selector(argc, argv, &strategy) || !init(argc, argv, &a, &b))
	{
		ft_printf("Strategy: %d\n", strategy);
		ft_putstr_fd("Error\n", 0);
		return (-1);
	}
	// ft_printf("Strategy: %d\n", strategy);
	// printf("Disorder: %f\n", compute_disorder(a));
	// ft_putstr_fd("OK\n\n", 1);
	if (compute_disorder(a) == 0)
		return (0);
	algo_caller(&a, &b, strategy);
	print_stack(a->top, 'A');
	print_stack(b->top, 'B');
	clear_stack(&a->top, a);
	clear_stack(&b->top, b);
	return (0);
}
