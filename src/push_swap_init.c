/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroard <maroard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 11:51:32 by maroard           #+#    #+#             */
/*   Updated: 2025/12/11 11:28:00 by maroard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
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

static int	link_nodes(size_t i, char **arg, t_stack **stack_A)
{
	if (!is_number(arg[i]) || !(ft_atoll(arg[i]) >= INT_MIN && ft_atoll(arg[i]) <= INT_MAX))
		return (0);
	node_add_back(&((*stack_A)->top), create_node(ft_atoi(arg[i++])));
	(*stack_A)->size++;
	return (1);
}

static void	*free_tab(char **tab)
{
    size_t i;

    if (!tab)
        return (NULL);
    i = 0;
    while (tab[i])
    {
        free(tab[i]);
        i++;
    }
    free(tab);
	return (NULL);
}

static t_stack	*args_split(char *arg)
{
	size_t	i;
	char	**tab;
	t_stack	*stack_A;

	i = 0;
	tab = ft_split(arg, ' ');
	if (!tab || !tab[0])
		return (free_tab(tab));
	stack_A = malloc(sizeof(t_stack));
	if (!stack_A || !is_number(tab[0]) || !(ft_atoll(tab[0]) >= INT_MIN && ft_atoll(tab[0]) <= INT_MAX))
		return (clear_stack(&(stack_A->top), stack_A));
	stack_A->top = create_node(ft_atoi(tab[i++]));
	if (!stack_A->top)
		return (clear_stack(&(stack_A->top), stack_A));
	stack_A->size = 1;
	while (tab[i])
	{
		if (!link_nodes(i++, tab, &stack_A))
			return (clear_stack(&(stack_A->top), stack_A));
	}
	free_tab(tab);
	return (stack_A);
}

t_stack	*create_stack_A(int argc, char *argv[])
{
	size_t	i;
	t_stack	*stack_A;

	if (argc == 2 && ft_strchr(argv[1], ' '))
		return (args_split(argv[1]));
	i = 1;
	stack_A = malloc(sizeof(t_stack));
	if (!stack_A || !is_number(argv[1]) || !(ft_atoll(argv[1]) >= INT_MIN && ft_atoll(argv[1]) <= INT_MAX))
		return (clear_stack(&(stack_A->top), stack_A));
	stack_A->top = create_node(ft_atoi(argv[i++]));
	if (!stack_A->top)
		return (clear_stack(&(stack_A->top), stack_A));
	stack_A->size = 1;
	while (i < (size_t)(argc))
	{
		if (!link_nodes(i++, argv, &stack_A))
			return (clear_stack(&(stack_A->top), stack_A));
	}
	return (stack_A);
}
