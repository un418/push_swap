#include "push_swap.h"

void	free_nodes(t_node **head)
{
	t_node	*next_free;
	t_node	*last;

	if (!*head)
		return ;
	last = (*head)->prev;
	last->next = NULL;
	while (*head != NULL)
	{
		next_free = (*head)->next;
		free(*head);
		*head = next_free;

	}
	*head = NULL;
}