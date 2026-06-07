#include "push_swap.h"

void	reverse_me(t_node **stack)
{
	if (!stack || !*stack)
		return ;
	(*stack) = (*stack)->prev;
}

void	reverse_a(t_node **stack)
{
	reverse_me(stack);
	write(1, "rra\n", 4);
}

void	reverse_b(t_node **stack)
{
	reverse_me(stack);
	write(1, "rrb\n", 4);
}

void	reverse_all(t_node **stack_a, t_node **stack_b)
{
	reverse_me(stack_a);
	reverse_me(stack_b);
	write(1, "rrr\n", 4);
}
