#include <stdlib.h>


typedef	struct	s_node
{
	int	nb;

	struct s_node *next;
	struct s_node *prev;

} t_node;

int	stack_size(t_node *head)
{	
	int	size;
	t_node	*loop;

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

t_node	*new_node(int nb)
{
	t_node	*new;

	new = malloc(sizeof(t_node));
	if (!new)
		return (NULL);
	new->nb = nb;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

t_node	*last_node(t_node *head)
{
	t_node	*last;
	
	if(!head)
		return (NULL);
	last = head->prev;
	return (last);
}
