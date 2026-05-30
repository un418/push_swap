#include <unistd.h>

typedef struct	s_node
{
	struct s_node	*next;
	struct s_node	*prev;
} t_node;


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

void	rotate_me(t_node **stack)
{
	(*stack) = (*stack)->next;
}

void	reverse_me(t_node **stack)
{
	(*stack) = (*stack)->prev;
}

void	push_me(t_node **stack_src, t_node **stack_dest)
{
	t_node	*src;

	if (!*stack_src || !stack_src)
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

// void	swap_a(t_node **stack_a, int bench)
// k
// {
// 	swap_me(stack_a);
// 	bench = sa++;
// 	bench = count++;
// 	write (1, "sa\n", 3);
// }
