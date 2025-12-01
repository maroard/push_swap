/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroard <maroard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 11:51:32 by maroard           #+#    #+#             */
/*   Updated: 2025/12/01 19:54:43 by maroard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>
#include <limits.h>

static int	is_number(char *arg)
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

static int	check_arg(char *arg)
{
	if (is_number(arg) == 1 && ((ft_atoll(arg) >= INT_MIN && ft_atoll(arg) <= INT_MAX)))
		return (1);
	return (0);
}

static int	*int_split(char *arg, t_stack *stack_A)
{
	size_t	i;
	char	**tab;
	int		*stack_A;
	i = 0;
	tab = ft_split(arg, ' ');
	while (tab[i])
		i++;
	stack_A = malloc(i * sizeof(int));
	if (!stack_A)
		return (NULL);
	i = 0;
	while (tab[i])
	{
		if (check_arg(tab[i]) == 0)
			return (NULL);
		stack_A[i] = ft_atoll(tab[i]);
		ft_printf("%d\n", stack_A[i]);
		i++;
	}
	while (i--)
		free(tab[i]);
	free(tab);
	return (stack_A);
}

t_stack	create_stack_A(int argc, char *argv[], t_stack *stack_A)
{
	int	i;

	i = 1;
	if (argc == 2)
	{
		int_split(argv[1], &stack_A);
		return (*stack_A);
	}
	stack_A = malloc ((argc - 1) * sizeof(t_stack));
	if (!stack_A)
		return ;
	if (check_arg(argv[i]) == 0)
		return ;
	stack_A->top = ft_atoi(argv[i++]);
	stack_A->size++;
	while (i < argc - 1)
	{
		if (check_arg(argv[i]) == 0)
			return ;
		stack_A = ft_atoi(argv[i++]);
		ft_printf("%d\n", stack_A[i]);
	}
	return (*stack_A);
}
