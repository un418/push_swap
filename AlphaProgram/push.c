#include "push_swap.h"

void	push_me(t_node **stack_src, t_node **stack_dest)
{
	t_node	*src;

	if (!stack_src || !*stack_src)
		return ;
	src = (*stack_src);
	if (src->next == src)
		(*stack_src) = NULL;
	else
	{
		(*stack_src) = src->next;
		src->prev->next = src->next;
		src->next->prev = src->prev;
	}
	if ((*stack_dest) == NULL)
	{
		src->next = src;
		src->prev = src;
	}
	else
	{
		src->next = (*stack_dest);
		src->prev = (*stack_dest)->prev;
		src->prev->next = src;
		(*stack_dest)->prev = src;
	}
	(*stack_dest) = src;
}

void	push_a(t_node **stack_a, t_node **stack_b)
{
	push_me(stack_b, stack_a);
	write(1, "pa\n", 3);
}

void	push_b(t_node **stack_a, t_node **stack_b)
{
	push_me(stack_a, stack_b);
	write(1, "pb\n", 3);
}
