/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaferna <adaferna@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 18:59:57 by adaferna          #+#    #+#             */
/*   Updated: 2026/06/03 16:54:46 by adaferna         ###   ########.fr       */
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
	int		mode;
	int		bench;
	int 	*parsed;
	size_t	parsed_size;
	// t_stats *stats;
}	t_ctx;


/*----Function Prototype----*/

// utils

int			is_valid_num_fmt(const char *str);
int			is_digit(const char c);
int			is_str_eq(const char *s1, const char *s2);
int			is_flag_prefix(const char *str);
long		ft_atol(const char *str);

// input

int			parse_flag(const char *arg, t_ctx *ctx);
int			input_validate(const char **argv, t_ctx *ctx);
int			in_int_limits(const char *str);
int			parse_number(const char **argv, t_ctx *ctx);

// ctx

void		init_ctx(t_ctx *ctx);

#endif
