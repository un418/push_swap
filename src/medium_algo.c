/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_algo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pficcare <pficcare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 14:49:38 by pficcare          #+#    #+#             */
/*   Updated: 2026/06/09 19:07:22 by pficcare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	push_chunk(t_node **a, t_node **b, int min, int max, t_ctx *ctx)
{
	int	size;
	int	pushed;
	int	i;

	size = stack_size(*a);
	pushed = 0;
	i = 0;
	while (pushed < max - min + 1 && i < size)
	{
		if ((*a)->index >= min && (*a)->index <= max)
		{
			push_b(a, b, ctx);
			pushed++;
		}
		else
		{
			rotate_a(a, ctx);
			i++;
		}
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

static void	bring_top_b(t_node **b, int pos, int size, t_ctx *ctx)
{
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
	int	size;

	while (*b)
	{
		size = stack_size(*b);
		pos = find_max_b(*b);
		bring_top_b(b, pos, size, ctx);
		push_a(a, b, ctx);
	}
}

void	sort_medium(t_node **stack_a, t_node **stack_b, t_ctx *ctx)
{
	int	size;
	int	chunks;
	int	chunk;
	int	chunk_size;

	size = stack_size(*stack_a);
	chunks = ft_sqrt(size);
	chunk_size = size / chunks;
	chunk = 0;
	while (chunk < chunks)
	{
		push_chunk(stack_a, stack_b,
			chunk * chunk_size,
			(chunk + 1) * chunk_size - 1 + (chunk == chunks - 1
				? size % chunks : 0),
			ctx);
		chunk++;
	}
	push_all_b(stack_a, stack_b, ctx);
}
















// static void	checker(t_node **stack_a, t_node **stack_b, t_ctx *ctx)
// {
// 	if (ctx->parsed_size == 2 && (*stack_a)->index > (*stack_a)->next->index)
// 		return (swap_a(stack_a, ctx));
// 	if (ctx->parsed_size == 3)
// 		return (sort_3(stack_a, ctx));
// 	if (ctx->parsed_size <= 5)
// 		return (sort_5(stack_a, stack_b, ctx));
// }

// // static int	ft_sqrt(int n)
// // {
// // 	int	i;

// // 	i = 1;
// // 	while (i * i <= n)
// // 		i++;
// // 	return (i - 1);
// // }

// static int	find_max_pos(t_node *head, int min, int max)
// {
// 	t_node	*cur;
// 	int		best_idx;
// 	int		best_pos;
// 	int		pos;

// 	cur = head;
// 	best_idx = -1;
// 	best_pos = 0;
// 	pos = 0;
// 	while (1)
// 	{
// 		if (cur->index >= min && cur->index <= max && cur->index > best_idx)
// 		{
// 			best_idx = cur->index;
// 			best_pos = pos;
// 		}
// 		cur = cur->next;
// 		pos++;
// 		if (cur == head)
// 			break ;
// 	}
// 	return (best_pos);
// }

// static void	bring_to_top(t_node **stack_a, int pos, int size, t_ctx *ctx)
// {
// 	if (pos <= size / 2)
// 	{
// 		while (pos > 0)
// 		{
// 			rotate_a(stack_a, ctx);
// 			pos--;
// 		}
// 	}
// 	else
// 	{
// 		pos = size - pos;
// 		while (pos > 0)
// 		{
// 			reverse_a(stack_a, ctx);
// 			pos--;
// 		}
// 	}
// }

// static void	work_on_stack_b(t_node **stack_a, t_node **stack_b, t_ctx *ctx)
// {
// 	int	pos;
// 	int	size;

// 	size = 0;
// 	while (*stack_b)
// 	{
// 		pos = find_max_pos(*stack_b, 0, size - 1);
// 		bring_to_top(stack_b, pos, stack_size(*stack_b), ctx);
// 		push_a(stack_a, stack_b, ctx);
// 	}
// }

// void	sort_medium(t_node **stack_a, t_node **stack_b, t_ctx *ctx)
// {
// 	int	size;
// 	int	chunk;
// 	int	chunks;
// 	int	pushed;
// 	int	pos;

// 	size = stack_size(*stack_a);
// 	if (size <= 5)
// 		return (checker(stack_a, stack_b, ctx));
// 	chunks = (int)ft_sqrt(size);
// 	chunk = 0;
// 	while (chunk < size)
// 	{
// 		pushed = 0;
// 		while (pushed < chunks && stack_size(*stack_a) > 0)
// 		{
// 			pos = find_max_pos(*stack_a, chunk, chunk + chunks - 1);
// 			bring_to_top(stack_a, pos, stack_size(*stack_a), ctx);
// 			push_b(stack_a, stack_b, ctx);
// 			pushed++;
// 			chunk++;
// 		}
// 	}
// 	work_on_stack_b(stack_a, stack_b, ctx);
// }
