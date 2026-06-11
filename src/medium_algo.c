/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_algo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pficcare <pficcare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 14:49:38 by pficcare          #+#    #+#             */
/*   Updated: 2026/06/10 16:49:12 by pficcare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_chunk(t_node **a, t_node **b, int bounds[2], t_ctx *ctx)
{
	int	size;
	int	pushed;
	int	target;

	size = stack_size(*a);
	target = bounds[1] - bounds[0] + 1;
	pushed = 0;
	while (pushed < target && size > 0)
	{
		if ((*a)->index >= bounds[0] && (*a)->index <= bounds[1])
		{
			push_b(a, b, ctx);
			pushed++;
		}
		else
			rotate_a(a, ctx);
		size--;
	}
}

static int	find_max_b(t_node *head)
{
	t_node	*cur;
	int		max_idx;
	int		max_pos;
	int		pos;

	cur = head;
	max_idx = head->index;
	max_pos = 0;
	pos = 0;
	while (1)
	{
		if (cur->index > max_idx)
		{
			max_idx = cur->index;
			max_pos = pos;
		}
		cur = cur->next;
		pos++;
		if (cur == head)
			break ;
	}
	return (max_pos);
}

static void	bring_top_b(t_node **b, int pos, t_ctx *ctx)
{
	int	size;

	size = stack_size(*b);
	if (pos <= size / 2)
	{
		while (pos > 0)
		{
			rotate_b(b, ctx);
			pos--;
		}
	}
	else
	{
		pos = size - pos;
		while (pos > 0)
		{
			reverse_b(b, ctx);
			pos--;
		}
	}
}

static void	push_all_b(t_node **a, t_node **b, t_ctx *ctx)
{
	int	pos;

	while (*b)
	{
		pos = find_max_b(*b);
		bring_top_b(b, pos, ctx);
		push_a(a, b, ctx);
	}
}

void	sort_medium(t_node **stack_a, t_node **stack_b, t_ctx *ctx)
{
	int	size;
	int	chunks;
	int	chunk;
	int	bounds[2];

	size = stack_size(*stack_a);
	if (size <= 5)
		return (checker(stack_a, stack_b, ctx));
	chunks = ft_sqrt(size);
	chunk = 0;
	while (chunk < chunks)
	{
		bounds[0] = chunk * (size / chunks);
		bounds[1] = (chunk + 1) * (size / chunks) - 1;
		if (chunk == chunks - 1)
			bounds[1] = size - 1;
		push_chunk(stack_a, stack_b, bounds, ctx);
		chunk++;
	}
	push_all_b(stack_a, stack_b, ctx);
}
