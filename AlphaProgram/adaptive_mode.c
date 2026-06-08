/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptive_mode.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pficcare <pficcare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 13:46:17 by pficcare          #+#    #+#             */
/*   Updated: 2026/06/08 18:36:58 by pficcare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	adaptive_mode(t_node **stack_a, t_node **stack_b, float dis, t_ctx *ctx)
{
	if (dis <= 0.2)
		return (sort_simple(stack_a, stack_b, ctx));
	else if (dis <= 0.5)
		return (sort_medium(stack_a, stack_b, ctx));
	else
		return (sort_complex(stack_a, stack_b, ctx));
}
