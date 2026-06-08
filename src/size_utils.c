#include "push_swap.h"

int	stack_size(t_node *head)
{
	int		size;
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
			break ;
	}
	return (size);
}