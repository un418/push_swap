#include "push_swap.h"

void	rotate_me(t_node **stack)
{
	if (!stack || !*stack)
		return ;
	(*stack) = (*stack)->next;
}

void	rotate_a(t_node **stack)
{
	rotate_me(stack);
}

void	rotate_b(t_node **stack)
{
	rotate_me(stack);
}

void	rotate_all(t_node **stack_a, t_node **stack_b)
{
	rotate_me(stack_a);
	rotate_me(stack_b);
}
