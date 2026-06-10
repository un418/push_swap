/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_size_input.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pficcare <pficcare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 17:17:47 by pficcare          #+#    #+#             */
/*   Updated: 2026/06/10 17:17:51 by pficcare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	checker(t_node **stack_a, t_node **stack_b, t_ctx *ctx)
{
	if (ctx->parsed_size == 2 && (*stack_a)->index > (*stack_a)->next->index)
		return (swap_a(stack_a, ctx));
	if (ctx->parsed_size == 3)
		return (sort_3(stack_a, ctx));
	if (ctx->parsed_size <= 5)
		return (sort_5(stack_a, stack_b, ctx));
}
