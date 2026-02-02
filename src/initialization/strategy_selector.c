/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strategy_selector.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroard <maroard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 16:17:50 by maroard           #+#    #+#             */
/*   Updated: 2026/02/02 18:55:16 by maroard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	strategy_selector(int argc, char *argv[], t_ctx **ctx)
{
	if (argc == 1 || (argc == 2 && !is_number(argv[1])))
		return (0);
	if (argc >= 3 && !ft_strcmp("--simple", argv[1]))
		(*ctx)->strategy = SIMPLE;
	else if (argc >= 3 && !ft_strcmp("--medium", argv[1]))
		(*ctx)->strategy = MEDIUM;
	else if (argc >= 3 && !ft_strcmp("--complex", argv[1]))
		(*ctx)->strategy = COMPLEX;
	else if (argc >= 3 && !ft_strcmp("--bench", argv[1]))
	{
		(*ctx)->bench.is_active = TRUE;
		(*ctx)->strategy = ADAPTIVE;
	}
	else if (argc >= 3 && !is_number(argv[1])
		&& ft_strncmp("--adaptive", argv[1], 10))
		return (0);
	else
		(*ctx)->strategy = ADAPTIVE;
	return (1);
}
