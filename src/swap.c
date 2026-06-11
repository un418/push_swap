/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pficcare <pficcare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 13:48:07 by pficcare          #+#    #+#             */
/*   Updated: 2026/06/08 13:48:08 by pficcare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// with 2 nodes the circular links already form the swapped pair both ways:
// moving the head IS the swap (general rewiring would hit last == second)
void	swap_me(t_node **stack)
{
	t_node	*first;
	t_node	*second;
	t_node	*last;

	if ((!*stack) || (*stack == (*stack)->next))
		return ;
	if ((*stack)->next->next == *stack)
	{
		*stack = (*stack)->next;
		return ;
	}
	first = (*stack);
	second = (*stack)->next;
	last = (*stack)->prev;
	second->next->prev = first;
	last->next = second;
	first->prev = second;
	first->next = second->next;
	second->next = first;
	second->prev = last;
	(*stack) = second;
}

void	swap_a(t_node **stack, t_ctx *ctx)
{
	swap_me(stack);
	ctx->stats.sa++;
	ctx->stats.total++;
	write_op("sa\n", ctx);
}

void	swap_b(t_node **stack, t_ctx *ctx)
{
	swap_me(stack);
	ctx->stats.sb++;
	ctx->stats.total++;
	write_op("sb\n", ctx);
}

void	swap_all(t_node **stack_a, t_node **stack_b, t_ctx *ctx)
{
	swap_me(stack_a);
	swap_me(stack_b);
	ctx->stats.ss++;
	ctx->stats.total++;
	write_op("ss\n", ctx);
}
