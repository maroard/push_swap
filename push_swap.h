/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroard <maroard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 11:20:35 by maroard           #+#    #+#             */
/*   Updated: 2025/12/09 18:53:39 by maroard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"

typedef struct s_node
{
    int				content;
    struct s_node	*next;
}					t_node;

typedef struct s_stack
{
    t_node	*top;
    int		size;
}			t_stack;


t_node	*create_node(int content);
t_node	*last_node(t_node *node);
void	node_add_back(t_node **list, t_node *new);
t_stack *clear_stack(t_node **top, t_stack *stack);
void	print_stack(t_node *list);

t_stack *create_stack_A(int argc, char *argv[]);

int     ft_printf(const char *s, ...);

#endif
