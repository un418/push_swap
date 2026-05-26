/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selector.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pficcare <pficcare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 16:07:33 by pficcare          #+#    #+#             */
/*   Updated: 2026/05/22 19:10:07 by pficcare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 == *s2 && *s1)
	{
		s1++;
		s2++;
	}
	if (*s2 == '\n')
		return (1);
	else
		return (0);
}

int	ft_selector(char *str)
{
	char *spl = "simple";
	char *med = "medium";
	char *comp = "complex";
	char *adap = "adaptive";
	char *bench = "bench";
	
	while (*str == '-')
		str++;
	if (*str == 's')
		return (ft_strcmp(str, spl));
	if (*str == 'm')
		return (ft_strcmp(str, med));
	if (*str == 'c')
		return (ft_strcmp(str, comp));
	if (*str == 'a')
		return (ft_strcmp(str, adap));
	if (*str == 'b')
		return (ft_strcmp(str, bench));
	else
		return (0);
}