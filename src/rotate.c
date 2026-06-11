/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pficcare <pficcare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 13:47:44 by pficcare          #+#    #+#             */
/*   Updated: 2026/06/08 16:28:33 by pficcare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_me(t_node **stack)
{
	if (!stack || !*stack)
		return ;
	(*stack) = (*stack)->next;
}

void	rotate_a(t_node **stack, t_ctx *ctx)
{
	rotate_me(stack);
	ctx->stats.ra++;
	ctx->stats.total++;
	write_op("ra\n", ctx);
}

void	rotate_b(t_node **stack, t_ctx *ctx)
{
	rotate_me(stack);
	ctx->stats.rb++;
	ctx->stats.total++;
	write_op("rb\n", ctx);
}

void	rotate_all(t_node **stack_a, t_node **stack_b, t_ctx *ctx)
{
	rotate_me(stack_a);
	rotate_me(stack_b);
	ctx->stats.rr++;
	ctx->stats.total++;
	write_op("rr\n", ctx);
}
