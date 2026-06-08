/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pficcare <pficcare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 18:59:57 by adaferna          #+#    #+#             */
/*   Updated: 2026/06/08 17:17:33 by pficcare         ###   ########.fr       */
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

// printf()
# include <stdio.h> // debug to remove later

/*----Structures Definition----*/

// structure that hold the context
typedef struct s_ctx
{
	int				mode;
	int				bench;
	int				*parsed;
	size_t			parsed_size;
	// float		disorder;
	// t_stats *	stats;
}					t_ctx;


typedef struct s_node
{
	int				nb;
	int				index;
	struct s_node	*next;
	struct s_node	*prev;
}					t_node;



/*----Function Prototype----*/

//parser

// // utils

int			is_valid_num_fmt(const char *str);
int			is_digit(const char c);
int			is_str_eq(const char *s1, const char *s2);
int			is_flag_prefix(const char *str);
long		ft_atol(const char *str);

// // input

int			parse_flag(const char *arg, t_ctx *ctx);
int			input_validate(const char **argv, t_ctx *ctx);
int			in_int_limits(const char *str);
int			parse_number(const char **argv, t_ctx *ctx);

// // ctx

void		init_ctx(t_ctx *ctx);

// linked list

t_node				*new_node(int nb);
t_node				*get_last(t_node *head);
int					stack_size(t_node *head);
t_node				*add_first(t_node **head, t_node *new);
t_node				*add_last(t_node **head, t_node *new);
void				free_nodes(t_node **head);
t_node				*fill_stack(int *parsed, int size);
void				indexator(t_node *head);

// // debug
void				print_list_nb(t_node *head);
void				print_list_index(t_node *head);



#endif
