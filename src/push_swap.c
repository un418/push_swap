/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pficcare <pficcare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 19:03:20 by adaferna          #+#    #+#             */
/*   Updated: 2026/06/10 14:28:07 by pficcare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, const char **argv)
{
	t_ctx	ctx;
	t_node	*stack_a;
	t_node	*stack_b;
	int		ret;

	init_ctx(&ctx);
	if (argc < 2)
		return (0);
	ret = input_validate((const char **)argv, &ctx);
	if (!ret || !ctx.mode)
		return (1);
	stack_a = fill_stack(ctx.parsed, ctx.parsed_size);
	free(ctx.parsed);
	stack_b = NULL;
	indexator(stack_a);
	wich_one(&stack_a, &stack_b, &ctx);
	// if (ctx.bench)
	// 	print_bench(ctx);
	printf("Total amout of %d\n", ctx.stats.total);
	printf("Algo used is = %s\n", ctx.str);
	free_nodes(&stack_a);
	free_nodes(&stack_b);
	return (0);
}
