/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroard <maroard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 11:20:35 by maroard           #+#    #+#             */
/*   Updated: 2025/12/01 19:45:22 by maroard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"

typedef struct s_node
{
    int				value;
    struct s_node	*next;
}					t_node;

typedef struct s_stack
{
    t_node	*top;
    int		size;
}			t_stack;

t_stack create_stack_A(int argc, char *argv[], t_stack *stack_A);

int	ft_printf(const char *s, ...);

#endif
