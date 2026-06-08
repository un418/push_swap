
#include "push_swap.h"

int	stack_size(t_node *head)
{
	int		size;
	t_node	*current;

	if (!head)
		return (0);
	current = head;
	size = 0;
	while (1)
	{
		current = current->next;
		size++;
		if (current == head)
			break ;
	}
	return (size);
}
