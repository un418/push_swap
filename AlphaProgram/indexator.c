#include "push_swap.h"

void	ft_indexator(t_node *head)
{
	t_node	*a_value;
	t_node	*n_value;
	int	index;
	
	if (!head)
		return;
	index = 0;
	a_value = head;
	n_value = head->next;

	while (1)
	{
		while (1)
		{
			if (a_value->nb > n_value->nb)
				index++;
			n_value = n_value->next;
			if (n_value == a_value)
				break;
		}
		a_value->index = index;
		a_value = a_value->next;
		n_value = a_value->next;
		index = 0;
		if (a_value == head)
			break;
	}

}