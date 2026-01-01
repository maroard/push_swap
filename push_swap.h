/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroard <maroard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 11:20:35 by maroard           #+#    #+#             */
/*   Updated: 2026/01/01 12:35:39 by maroard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"

typedef struct s_node
{
    int				content;
	int				index;
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
int		is_extremum(t_node *to_check, t_stack *A_or_B, t_bool min, t_bool max);
void	indexation(t_stack *A_or_B);


int		strategy_selector(int argc, char *argv[], t_strat *strategy);
t_stack	*create_stack_a(int argc, char *argv[]);
int		occurence_checker(t_stack *A);
float	compute_disorder(t_stack *A);


void	push_a(t_stack **A, t_stack **B);
void	push_b(t_stack **A, t_stack **B);

void	swap_a(t_stack **A, t_bool ss);
void	swap_b(t_stack **B, t_bool ss);
void	swap_swap(t_stack **A, t_stack **B);

void	rotate_a(t_stack **A, t_bool rr);
void	rotate_b(t_stack **B, t_bool rr);
void	rotate_rotate(t_stack **A, t_stack **B);

void	reverse_rotate_a(t_stack **A, t_bool rrr);
void	reverse_rotate_b(t_stack **B, t_bool rrr);
void	reverse_rotate_rotate(t_stack **A, t_stack **B);


void	simple_min_max_extraction(t_stack **A, t_stack **B);
void	range_based_sorting(t_stack **A, t_stack **B);
void	radix_sort_adaptation_lsd(t_stack **A, t_stack **B);

#endif
