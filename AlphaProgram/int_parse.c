/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pficcare <pficcare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 13:46:42 by pficcare          #+#    #+#             */
/*   Updated: 2026/06/08 13:52:55 by pficcare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atol(const char *str)
{
	int		neg;
	long	res;

	neg = 1;
	res = 0;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			neg *= -1;
		str++;
	}
	while (*str)
	{
		res = (res * 10) + (*str - '0');
		str++;
	}
	res = res * neg;
	return (res);
}

int	in_int_limits(const char *str)
{
	const char	*digits;
	int			len;
	long		n;

	digits = str;
	if (*digits == '-' || *digits == '+')
		digits++;
	len = 0;
	while (digits[len])
		len++;
	if (len > 10)
		return (0);
	n = ft_atol(str);
	if (n < INT_MIN || n > INT_MAX)
		return (0);
	return (1);
}

static size_t	tablen(const char **tab)
{
	size_t	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

static int	check_duplicate(const char *str, int *tab, int i_max)
{
	int	num;
	int	i;

	i = 0;
	num = ft_atol(str);
	while (i < i_max)
	{
		if (num == tab[i])
			return (0);
		i++;
	}
	return (tab[i] = num, 1);
}

int	*parse_number(const char **argv, t_ctx *ctx)
{
	int		i;
	int		*m_array;
	size_t	tabsize;

	i = 0;
	tabsize = tablen(argv);
	if (tabsize <= 1)
		return (NULL);
	m_array = malloc((tabsize * sizeof(int)));
	if (m_array == NULL)
		return (NULL);
	while (argv[i])
	{
		if (!check_duplicate(argv[i], m_array, i))
			return (free(m_array), NULL);
		i++;
	}
	ctx->parsed = m_array;
	ctx->parsed_size = tabsize;
	return (m_array);
}
