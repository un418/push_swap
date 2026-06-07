#include "push_swap.h"

void	sort_5(t_node **stack_a, t_node **stack_b, t_ctx *ctx)
{
	int	size;
	int	limit;

	size = stack_size(*stack_a);
	if (size == 4)
		limit = 1;
	else
		limit = 2;
	while (size > 3)
	{
		if ((*stack_a)->index < limit)
			push_b(stack_a, stack_b, ctx);
		else
			rotate_a(stack_a, ctx);
        size = stack_size(*stack_a);
	}
	sort_3(stack_a, ctx);
	if (*stack_b && (*stack_b)->next != *stack_b && (*stack_b)->index > (*stack_b)->next->index)
	{
		swap_b(stack_b, ctx);
	}
	if (*stack_b)
		rotate_b(stack_b, ctx);
	while (*stack_b)
		push_a(stack_a, stack_b, ctx);
}