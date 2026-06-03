#include "push_swap.h"

void	swap_me(t_node **stack)
{
	t_node	*first;
	t_node	*second;
	t_node	*last;

	if ((!*stack) || (*stack == (*stack)->next))
		return ;
	first = (*stack);
	second = (*stack)->next;
	last = (*stack)->prev;

	second->next->prev = first;
	last->next = second;
	first->prev = second;
	first->next = second->next;
	second->next = first;
	second->prev = last;

	(*stack) = second;
	
}

void	swap_a(t_node **stack)
{
	
	swap_me(stack);
	write(1, "sa\n", 3);
}

void	swap_b(t_node **stack)
{
	
	swap_me(stack);
}

void	swap_all(t_node **stack_a, t_node **stack_b)
{
	
	swap_me(stack_a);
	swap_me(stack_b);
}
