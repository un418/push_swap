/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pficcare <pficcare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 00:47:30 by adaferna          #+#    #+#             */
/*   Updated: 2026/05/26 18:45:04 by pficcare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_digit(const char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	is_valid_number(const char *str)
{
	if (*str == '+' || *str == '-')
		str++;
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
