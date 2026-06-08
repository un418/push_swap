/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pficcare <pficcare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 13:47:39 by pficcare          #+#    #+#             */
/*   Updated: 2026/06/08 13:47:40 by pficcare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_me(t_node **stack)
{
	if (!stack || !*stack)
		return ;
	(*stack) = (*stack)->prev;
}

void	reverse_a(t_node **stack, t_ctx *ctx)
{
	reverse_me(stack);
	ctx->stats.rra++;
	ctx->stats.total++;
	write(1, "rra\n", 4);
}

void	reverse_b(t_node **stack, t_ctx *ctx)
{
	reverse_me(stack);
	ctx->stats.rrb++;
	ctx->stats.total++;
	write(1, "rrb\n", 4);
}

void	reverse_all(t_node **stack_a, t_node **stack_b, t_ctx *ctx)
{
	reverse_me(stack_a);
	reverse_me(stack_b);
	ctx->stats.rrr++;
	ctx->stats.total++;
	write(1, "rrr\n", 4);
}
