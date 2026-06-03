/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaferna <adaferna@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 00:47:30 by adaferna          #+#    #+#             */
/*   Updated: 2026/05/28 11:22:10 by adaferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_digit(const char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

// valid:   "42", "-42", "+42"
// invalid: "+", "-", "4a2", ""
int	is_valid_num_fmt(const char *str)
{
	if (*str == '+' || *str == '-')
		str++;
	if (*str == '\0')
		return (0);
	while (*str)
		if (!is_digit(*str++))
			return (0);
	return (1);
}

int	is_str_eq(const char *s1, const char *s2)
{
	while (*s1 && *s2 && *s1++ == *s2++)
		;
	if (*s1 == '\0' && *s2 == '\0')
		return (1);
	else
		return (0);
}

int	is_flag_prefix(const char *str)
{
	if (*str == '-' && *(str + 1) == '-')
		return (1);
	else
		return (0);
}
