/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_algo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pficcare <pficcare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 14:35:02 by pficcare          #+#    #+#             */
/*   Updated: 2026/06/09 15:17:26 by pficcare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_min_pos(t_node *head)
{
	t_node	*cur;
	int		min_idx;
	int		min_pos;
	int		pos;

	cur = head;
	min_idx = head->index;
	min_pos = 0;
	pos = 0;
	while (cur->next != head)
	{
		cur = cur->next;
		pos++;
		if (cur->index < min_idx)
		{
			min_idx = cur->index;
			min_pos = pos;
		}
	}
	return (min_pos);
}

static void	bring_to_top(t_node **stack_a, int pos, int size, t_ctx *ctx)
{
	if (pos <= size / 2)
		while (pos > 0)
		{	
			rotate_a(stack_a, ctx);
			pos--;
		}
	else
	{
		pos = size - pos;
		while (pos > 0)
		{
			reverse_a(stack_a, ctx);
			pos--;
		}
	}
}

void	sort_simple(t_node **stack_a, t_node **stack_b, t_ctx *ctx)
{
	int	size;
	int	pos;

	size = stack_size(*stack_a);
	while (size > 3)
	{
		pos = find_min_pos(*stack_a);
		bring_to_top(stack_a, pos, size, ctx);
		push_b(stack_a, stack_b, ctx);
		size--;
	}
	sort_3(stack_a, ctx);
	while (*stack_b)
		push_a(stack_a, stack_b, ctx);
}
