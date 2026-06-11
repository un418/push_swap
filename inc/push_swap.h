/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pficcare <pficcare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 18:59:57 by adaferna          #+#    #+#             */
/*   Updated: 2026/06/10 18:00:28 by pficcare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

// for write()
# include <unistd.h>

// for int min/max
# include <limits.h>

// malloc/free
# include <stdlib.h>

// ft_printf / ft_dprintf
# include "ft_printf.h"

/*----Structures Definition----*/

typedef struct s_stats
{
	int				sa;
	int				sb;
	int				ss;
	int				ra;
	int				rb;
	int				rr;
	int				rra;
	int				rrb;
	int				rrr;
	int				pa;
	int				pb;
	int				total;
}					t_stats;

// structure that hold the context
typedef struct s_ctx
{
	int				mode;
	int				bench;
	int				*parsed;
	size_t			parsed_size;
	float			disorder;
	t_stats			stats;
}					t_ctx;

typedef struct s_node
{
	int				nb;
	int				index;
	struct s_node	*next;
	struct s_node	*prev;
}					t_node;

/*----Function Prototype----*/

// parser

// // utils

int					is_valid_num_fmt(const char *str);
int					is_digit(const char c);
int					is_str_eq(const char *s1, const char *s2);
int					is_flag_prefix(const char *str);
long				ft_atol(const char *str);
int					ft_sqrt(int n);
void				checker(t_node **stack_a, t_node **stack_b, t_ctx *ctx);

// // bench

void				print_bench(t_ctx *ctx);

// // input`

int					parse_flag(const char *arg, t_ctx *ctx);
int					input_validate(const char **argv, t_ctx *ctx);
int					in_int_limits(const char *str);
int					parse_number(const char **argv, t_ctx *ctx);

// // ctx

void				init_ctx(t_ctx *ctx);

// linked list

t_node				*new_node(int nb);
t_node				*get_last(t_node *head);
int					stack_size(t_node *head);
t_node				*add_first(t_node **head, t_node *new);
t_node				*add_last(t_node **head, t_node *new);
void				free_nodes(t_node **head);
t_node				*fill_stack(int *parsed, int size);
void				indexator(t_node *head);

// operations

void				swap_me(t_node **stack);
void				swap_a(t_node **stack, t_ctx *ctx);
void				swap_b(t_node **stack, t_ctx *ctx);
void				swap_all(t_node **stack_a, t_node **stack_b, t_ctx *ctx);
void				push_me(t_node **stack_src, t_node **stack_dest);
void				push_a(t_node **stack_a, t_node **stack_b, t_ctx *ctx);
void				push_b(t_node **stack_a, t_node **stack_b, t_ctx *ctx);
void				rotate_me(t_node **stack);
void				rotate_a(t_node **stack, t_ctx *ctx);
void				rotate_b(t_node **stack, t_ctx *ctx);
void				rotate_all(t_node **stack_a, t_node **stack_b, t_ctx *ctx);
void				reverse_me(t_node **stack);
void				reverse_a(t_node **stack, t_ctx *ctx);
void				reverse_b(t_node **stack, t_ctx *ctx);
void				reverse_all(t_node **stack_a, t_node **stack_b, t_ctx *ctx);
float				disorder(t_node *head);

// sorting strategies

void				wich_one(t_node **stack_a, t_node **stack_b, t_ctx *ctx);
void				sort_adaptive(t_node **stack_a, t_node **stack_b, float dis,
						t_ctx *ctx);
void				sort_simple(t_node **stack_a, t_node **stack_b, t_ctx *ctx);
void				sort_medium(t_node **stack_a, t_node **stack_b, t_ctx *ctx);
void				sort_complex(t_node **stack_a, t_node **stack_b,
						t_ctx *ctx);
void				sort_3(t_node **stack_a, t_ctx *ctx);
void				sort_5(t_node **stack_a, t_node **stack_b, t_ctx *ctx);

#endif
