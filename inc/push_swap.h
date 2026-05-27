/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaferna <adaferna@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 18:59:57 by adaferna          #+#    #+#             */
/*   Updated: 2026/05/27 18:56:17 by adaferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

// for write()
# include <unistd.h>

// for int min/max
# include <limits.h>

// printf()
# include <stdio.h> // debug to remove later

/*----Function Prototype----*/

// utils

int			is_valid_number(const char *str);
int			is_digit(const char c);
int			is_str_eq(const char *s1, const char *s2);
int			is_flag_prefix(const char *str);
long		ft_atol(const char *str);

// parser

int			flags_parser(const char *arg);
int			arg_validate(const char **argv);
int			in_int_limits(const char *str);

#endif
