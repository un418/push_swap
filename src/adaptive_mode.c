/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptive_mode.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pficcare <pficcare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 13:46:17 by pficcare          #+#    #+#             */
/*   Updated: 2026/06/09 19:10:03 by pficcare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_adaptive(t_node **stack_a, t_node **stack_b, float dis, t_ctx *ctx)
{
	if (ctx->parsed_size == 2 && (*stack_a)->index > (*stack_a)->next->index)
		return (swap_a(stack_a, ctx));
	if (ctx->parsed_size == 3)
		return (sort_3(stack_a, ctx));
	if (ctx->parsed_size <= 5)
		return (sort_5(stack_a, stack_b, ctx));
	if (dis < 0.2)
		return (sort_simple(stack_a, stack_b, ctx));
	else if (dis <= 0.5)
		return (sort_medium(stack_a, stack_b, ctx));
	else
		return (sort_complex(stack_a, stack_b, ctx));
}
