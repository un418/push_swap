/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_algo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pficcare <pficcare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 14:49:38 by pficcare          #+#    #+#             */
/*   Updated: 2026/06/08 14:49:41 by pficcare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_sqrt(int n)
{
	int	i;

	i = 1;
	while (i * i <= n)
		i++;
	return (i - 1);
}

static int	find_max_pos(t_node *head, int min, int max)
{
	t_node	*cur;
	int		best_idx;
	int		best_pos;
	int		pos;

	cur = head;
	best_idx = -1;
	best_pos = 0;
	pos = 0;
	while (1)
	{
		if (cur->index >= min && cur->index <= max && cur->index > best_idx)
		{
			best_idx = cur->index;
			best_pos = pos;
		}
		cur = cur->next;
		pos++;
		if (cur == head)
			break ;
	}
	return (best_pos);
}

static void	bring_to_top(t_node **stack_a, int pos, int size, t_ctx *ctx)
{
	if (pos <= size / 2)
		while (pos-- > 0)
			rotate_a(stack_a, ctx);
	else
	{
		pos = size - pos;
		while (pos-- > 0)
			reverse_a(stack_a, ctx);
	}
}

void	sort_medium(t_node **stack_a, t_node **stack_b, t_ctx *ctx)
{
	int	size;
	int	chunk;
	int	chunks;
	int	pushed;
	int	pos;

	size = stack_size(*stack_a);
	chunks = (int)ft_sqrt(size);
	chunk = 0;
	while (chunk < size)
	{
		pushed = 0;
		while (pushed < chunks && stack_size(*stack_a) > 0)
		{
			pos = find_max_pos(*stack_a, chunk, chunk + chunks - 1);
			bring_to_top(stack_a, pos, stack_size(*stack_a), ctx);
			push_b(stack_a, stack_b, ctx);
			pushed++;
			chunk++;
		}
	}
	while (*stack_b)
	{
		pos = find_max_pos(*stack_b, 0, size - 1);
		bring_to_top(stack_b, pos, stack_size(*stack_b), ctx);
		push_a(stack_a, stack_b, ctx);
	}
}
