/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroard <maroard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 11:20:35 by maroard           #+#    #+#             */
/*   Updated: 2025/12/22 18:52:42 by maroard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"

typedef struct s_node
{
    int				content;
    struct s_node	*next;
	struct s_node	*prev;
}					t_node;

typedef struct s_stack
{
    t_node	*top;
    int		size;
}			t_stack;

typedef enum strategies
{
	SIMPLE,
	MEDIUM,
	COMPLEX,
	ADAPTIVE
}	t_strat;

typedef enum bool
{
	FALSE,
	TRUE
}	t_bool;

int     ft_printf(const char *s, ...);

t_node	*create_node(int content);
t_node	*last_node(t_node *top);
void	node_add_back(t_node **top, t_node *new);
void	node_add_front(t_node **top, t_node *new);
void    *clear_stack(t_node **top, t_stack *A_or_B);
void	print_stack(t_node *top, char A_or_B);
int		is_number(char *arg);
int		top_is_extremum(t_stack *A_or_B, t_bool min, t_bool max);
int		stack_a_is_sorted(t_stack *A, t_stack *B);

int		strategy_selector(int argc, char *argv[], t_strat *strategy);
t_stack	*create_stack_a(int argc, char *argv[]);
int		occurence_checker(t_stack *A);
float	compute_disorder(t_stack *A);

void	simple_min_max_extraction(t_stack **a, t_stack **b);

int		push_a(t_stack **A, t_stack **B);
int		push_b(t_stack **A, t_stack **B);

int		swap_a(t_stack **A, t_bool ss);
int		swap_b(t_stack **B, t_bool ss);
int		swap_swap(t_stack **A, t_stack **B);

int		rotate_a(t_stack **A, t_bool rr);
int		rotate_b(t_stack **B, t_bool rr);
int		rotate_rotate(t_stack **A, t_stack **B);

int		reverse_rotate_a(t_stack **A, t_bool rrr);
int		reverse_rotate_b(t_stack **B, t_bool rrr);
int		reverse_rotate_rotate(t_stack **A, t_stack **B);

#endif
