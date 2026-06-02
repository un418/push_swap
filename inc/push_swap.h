/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaferna <adaferna@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 18:59:57 by adaferna          #+#    #+#             */
/*   Updated: 2026/06/03 00:33:21 by adaferna         ###   ########.fr       */
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

/*----Function Prototype----*/

// utils

int			is_valid_num_fmt(const char *str);
int			is_digit(const char c);
int			is_str_eq(const char *s1, const char *s2);
int			is_flag_prefix(const char *str);
long		ft_atol(const char *str);

// input

int			parse_flag(const char *arg);
int			input_validate(const char **argv);
int			in_int_limits(const char *str);
int*		parse_number(const char **argv);

// int_parse.c internals (static)
// static size_t	tablen(char **tab);
// static int	check_duplicate(const char *str, int *tab, int i_max)

#endif
