#include "push_swap.h"

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

t_node	*add_last(t_node **head, t_node *new)
{
	t_node *last;

	if (!*head)
	{
		*head = new;
		new->next = new;
		new->prev = new;
		return (*head);
	}
	last = (*head)->prev;
	new->prev = last;
	new->next = *head;
	(*head)->prev = new;
	last->next = new;	
	return (*head);
}

t_node *add_first(t_node **head, t_node *new)
{
	t_node *first;

	if (!*head)
	{
		(*head) = new;
		new->next = new;
		new->prev = new;
		return (*head);
	}
	first = (*head)->prev;
	new->prev = first;
	new->next = *head;
	(*head)->prev = new;
	first->next = new;		
	return (*head = new);
}