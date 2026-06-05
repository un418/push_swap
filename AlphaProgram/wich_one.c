#include "push_swap.h"

void	wich_one(t_node **stack_a, t_node **stack_b, int size, t_ctx *ctx)
{

    if (size <= 1)
        return ;
    if (size == 2)
        return (swap_a(stack_a));
    if (size == 3)
        return (sort_3(stack_a));
    if (size <= 5)
        return (sort_5(stack_a, stack_b));
     if (ctx->mode == 6)
        return ;
    //      sort_adaptive(stack_a, stack_b, size);
    // else if (ctx->mode == 2)
    //     sort_simple(stack_a, stack_b, size);
    // else if (ctx->mode == 3)
    //     sort_medium(stack_a, stack_b, size);
    // else if (ctx->mode == 4)
    //     sort_complex(stack_a, stack_b, size);
}