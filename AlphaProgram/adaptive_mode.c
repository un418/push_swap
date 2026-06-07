#include "push_swap.h"

void  adaptive_mode(t_node **stack_a, t_node **stack_b, float dis)
{
    if (dis <= 0.2)
        return (sort_simple(stack_a, stack_b));
    else if (dis <= 0.5)
        return (sort_medium(stack_a, stack_b));
    else
        return (sort_complex(stack_a, stack_b));
}