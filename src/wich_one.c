/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wich_one.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pficcare <pficcare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 13:48:10 by pficcare          #+#    #+#             */
/*   Updated: 2026/06/10 13:17:45 by pficcare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_sorted(t_node *head)
{
	t_node	*check;

	if (!head)
		return (1);
	check = head;
	while (1)
	{
		if (check->index > check->next->index)
			return (0);
		check = check->next;
		if (check->next == head)
			break ;
	}
	return (1);
}

void	wich_one(t_node **stack_a, t_node **stack_b, t_ctx *ctx)
{
	float	dis;
	
	if (ctx->parsed_size <= 1 || is_sorted(*stack_a))
	{
		// if (ctx->bench)
		// 	print_bench(ctx);
		return ;
	}
	dis = disorder(*stack_a);
	if (ctx->bench)
		ctx->disorder = dis;
	if (ctx->mode == 1)
		return (sort_adaptive(stack_a, stack_b, dis, ctx));
	if (ctx->mode == 2)
		return (sort_simple(stack_a, stack_b, ctx));
	if (ctx->mode == 3)
		return (sort_medium(stack_a, stack_b, ctx));
	if (ctx->mode == 4)
		return (sort_complex(stack_a, stack_b, ctx));
}
