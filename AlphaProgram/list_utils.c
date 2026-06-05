#include "push_swap.h"

void	print_list(t_node *head)
{
	t_node	*to_print;

	to_print = head;
	while (to_print)
	{
		printf("Value in node = %d\n", to_print->nb);
		to_print = to_print->next;
		if (to_print == head)
			break;
	}
}

void	print_list_cir(t_node *head)
{
	t_node	*to_print;

	to_print = head;
	while (1)
	{
		printf("Value in node = %d\n", to_print->nb);
		to_print = to_print->next;
		if (to_print == head)
			break;
	}
}

void	print_list_index(t_node *head)
{
	t_node	*to_print;

	to_print = head;
	while (1)
	{
		printf("Value in index = %d\n", to_print->index);
		to_print = to_print->next;
		if (to_print == head)
			break;
	}
}

int	stack_size(t_node *head)
{	
	int	size;
	t_node	*loop;
	
	if (!head)
		return (0);
	loop = head;
	size = 0;
	while (1)
	{
		loop = loop->next;
		size++;
		if (loop == head)
			break;
	}
	return (size);
}