/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack_A.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroard <maroard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 11:51:32 by maroard           #+#    #+#             */
/*   Updated: 2026/03/06 15:15:40 by maroard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>
#include <stdlib.h>

static int	add_back(int i, char **args, t_stack *A)
{
	if (!is_number(args[i])
		|| !(ft_atoll(args[i]) >= INT_MIN && ft_atoll(args[i]) <= INT_MAX))
		return (0);
	node_add_back(&A->top, create_node(ft_atoi(args[i])));
	++A->size;
	return (1);
}

static int	free_tab(char **tab)
{
	size_t	i;

	if (!tab)
		return (0);
	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
	return (0);
}

static int	args_split(char *arg, t_stack *A)
{
	char	**tab;
	size_t	i;

	tab = ft_split(arg, ' ');
	if (!tab || !tab[0])
		return (free_tab(tab));
	i = 0;
	while (tab[i])
	{
		if (!add_back(i++, tab, A))
			return (clear_stack(&A->top));
	}
	free_tab(tab);
	return (1);
}

int	create_stack_a(int argc, char *argv[], t_ctx *ctx)
{
	int	i;

	if (ctx->nb_flags == 0 && ft_strchr(argv[1], ' '))
		return (args_split(argv[1], &ctx->a));
	if (!ctx->is_checker && ft_strchr(argv[ctx->nb_flags + 1], ' '))
		return (args_split(argv[ctx->nb_flags + 1], &ctx->a));
	i = ctx->nb_flags + 1;
	while (i < argc)
	{
		if (!add_back(i++, argv, &ctx->a))
			return (clear_stack(&ctx->a.top));
	}
	return (1);
}
