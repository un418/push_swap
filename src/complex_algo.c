/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_algo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pficcare <pficcare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 00:00:00 by adaferna          #+#    #+#             */
/*   Updated: 2026/06/10 12:10:51 by pficcare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	checker(t_node **stack_a, t_node **stack_b, t_ctx *ctx)
{
	if (ctx->parsed_size == 2 && (*stack_a)->index > (*stack_a)->next->index)
		return (swap_a(stack_a, ctx));
	if (ctx->parsed_size == 3)
		return (sort_3(stack_a, ctx));
	if (ctx->parsed_size <= 5)
		return (sort_5(stack_a, stack_b, ctx));
}

static size_t	get_max_bits(size_t size)
{
	int	bits;
	int	max;

	max = size - 1;
	bits = 0;
	while ((1 << bits) <= max)
		bits++;
	return (bits);
}

void	sort_complex(t_node **stack_a, t_node **stack_b, t_ctx *ctx)
{
	int	bits;
	int	max_bits;
	int	i;

	max_bits = get_max_bits(ctx->parsed_size);
	bits = 0;
	if (ctx->parsed_size <= 5)
		return (checker(stack_a, stack_b, ctx));
	while (bits < max_bits)
	{
		i = stack_size(*stack_a);
		while (i > 0)
		{
			if (((*stack_a)->index >> bits) & 1)
				rotate_a(stack_a, ctx);
			else
				push_b(stack_a, stack_b, ctx);
			i--;
		}
		while (*stack_b)
			push_a(stack_a, stack_b, ctx);
		bits++;
	}
}
