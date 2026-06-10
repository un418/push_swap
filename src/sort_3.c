/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pficcare <pficcare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 13:47:47 by pficcare          #+#    #+#             */
/*   Updated: 2026/06/08 13:55:10 by pficcare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	sort_3(t_node **stack_a, t_ctx *ctx)
{
	int	index_a;
	int	index_b;
	int	index_c;

	index_a = (*stack_a)->index;
	index_b = (*stack_a)->next->index;
	index_c = (*stack_a)->next->next->index;
	if (index_a > index_b && index_b < index_c && index_a < index_c)
		swap_a(stack_a, ctx);
	else if (index_a > index_b && index_b > index_c)
	{
		swap_a(stack_a, ctx);
		reverse_a(stack_a, ctx);
	}
	else if (index_a > index_b && index_b < index_c && index_a > index_c)
		rotate_a(stack_a, ctx);
	else if (index_a < index_b && index_b > index_c && index_a < index_c)
	{
		swap_a(stack_a, ctx);
		rotate_a(stack_a, ctx);
	}
	else if (index_a < index_b && index_b > index_c && index_a > index_c)
		reverse_a(stack_a, ctx);
}
