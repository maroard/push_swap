/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroard <maroard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 11:20:35 by maroard           #+#    #+#             */
/*   Updated: 2026/02/19 17:16:38 by maroard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"

typedef enum strategies
{
	SIMPLE,
	MEDIUM,
	COMPLEX,
	ADAPTIVE
}	t_strat;

typedef enum operations
{
	SA,
	SB,
	SS,
	PA,
	PB,
	RA,
	RB,
	RR,
	RRA,
	RRB,
	RRR,
	OP_COUNT
}	t_op;

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

typedef struct s_bench
{
	t_bool	is_active;
	int		ops[OP_COUNT];
	int		total_ops;
	int		complexity;
}			t_bench;

typedef struct s_ctx
{
	t_bool	is_checker;
	t_stack	a;
	t_stack	b;
	t_bench	bench;
	t_strat	strategy;
	double	disorder;
}			t_ctx;

t_node	*create_node(int content);
t_node	*last_node(t_node *top);
void	node_add_back(t_node **top, t_node *new);
void	node_add_front(t_node **top, t_node *new);
int		clear_stack(t_node **top);
void	print_stack(t_node *top, char A_or_B);
t_bool	is_number(char *arg);
t_bool	is_extremum(t_node *to_check, t_stack A_or_B, t_bool min, t_bool max);
void	indexation(t_stack A_or_B);

int		flags_parser(int argc, char *argv[], t_ctx *ctx);
int		create_stack_a(int argc, char *argv[], t_ctx *ctx);
int		occurence_checker(t_stack A);
double	compute_disorder(t_stack A);

void	push_a(t_ctx *ctx);
void	push_b(t_ctx *ctx);
void	swap_a(t_ctx *ctx, t_bool ss);
void	swap_b(t_ctx *ctx, t_bool ss);
void	swap_swap(t_ctx *ctx);
void	rotate_a(t_ctx *ctx, t_bool rr);
void	rotate_b(t_ctx *ctx, t_bool rr);
void	rotate_rotate(t_ctx *ctx);
void	reverse_rotate_a(t_ctx *ctx, t_bool rrr);
void	reverse_rotate_b(t_ctx *ctx, t_bool rrr);
void	reverse_rotate_rotate(t_ctx *ctx);

void	simple_min_max_extraction(t_ctx *ctx);
void	range_based_sorting(t_ctx *ctx);
void	radix_sort_adaptation_lsd(t_ctx *ctx);

void    sort_3_elements(t_ctx *ctx);
void    sort_5_elements(t_ctx *ctx);

void	logs_manager(t_ctx *ctx, t_op operation);
void	print_benchmark(t_ctx ctx);

#endif