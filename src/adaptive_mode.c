/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptive_mode.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pficcare <pficcare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 13:46:17 by pficcare          #+#    #+#             */
/*   Updated: 2026/06/08 16:27:48 by pficcare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	adaptive_mode(t_node **stack_a, t_node **stack_b, float dis)
{
	if (dis <= 0.2)
		return (sort_simple(stack_a, stack_b));
	else if (dis <= 0.5)
		return (sort_medium(stack_a, stack_b));
	else
		return (sort_complex(stack_a, stack_b));
}
