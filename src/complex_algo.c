/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_algo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pficcare <pficcare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 00:00:00 by adaferna          #+#    #+#             */
/*   Updated: 2026/06/09 15:54:11 by pficcare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// TODO (#67): implement the O(n log n) strategy.
// Empty shell so the project builds and adaptive_mode links.
// High-disorder inputs are NOT sorted yet.
// void	sort_complex(t_node **stack_a, t_node **stack_b, t_ctx *ctx)
// {
// 	(void)stack_a;
// 	(void)stack_b;
// 	(void)ctx;
// }


static int	get_max_bits(int size)
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
	int	size;
	int	bits;
	int	max_bits;
	int	i;
    write (1,"COMP\n", 5);
	size = stack_size(*stack_a);
	max_bits = get_max_bits(size);
	bits = 0;
	while (bits < max_bits)
	{
		i = size;
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
