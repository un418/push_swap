#include "push_swap.h"

void	wich_one(t_node **stack_a, t_node **stack_b, int size, t_ctx *ctx)
{
    float    dis;

    if (size <= 1)
        return ;
    if (size == 2 && (*stack_a)->index > (*stack_a)->next->index)
        return (swap_a(stack_a, ctx));
    if (size == 3)
        return (sort_3(stack_a, ctx));
    if (size <= 5)
        return (sort_5(stack_a, stack_b, ctx));
    dis = disorder(*stack_a);
    if (ctx->bench)
		ctx->disorder = dis;
	// if (ctx->mode == 1)
	// 	return (sort_adaptive(stack_a, stack_b, dis));
	// if (ctx->mode == 2)
	// 	return (sort_simple(stack_a, stack_b));
	// if (ctx->mode == 3)
	// 	return (sort_medium(stack_a, stack_b));
	// if (ctx->mode == 4)
	// 	return (sort_complex(stack_a, stack_b));
}