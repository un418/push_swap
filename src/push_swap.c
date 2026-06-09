/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pficcare <pficcare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 19:03:20 by adaferna          #+#    #+#             */
/*   Updated: 2026/06/09 18:08:05 by pficcare         ###   ########.fr       */
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
	if (argc == 1)
		return (0);
	ret = input_validate(argv, &ctx);
	if (!ret || !ctx.mode)
		return (1);
	printf("Mode = %d\n", ctx.mode); // Debug to remove later
	stack_a = fill_stack(ctx.parsed, ctx.parsed_size);
	free(ctx.parsed);
	stack_b = NULL;
	print_list_nb(stack_a);
	indexator(stack_a);
	print_list_index(stack_a);
	wich_one(&stack_a, &stack_b, &ctx);
	print_list_index(stack_a);
	print_list_nb(stack_a);
	if (ctx.bench)
		print_bench(&ctx);
	
	free_nodes(&stack_a);
	return (0);
}
