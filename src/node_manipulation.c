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

t_node	*last_node(t_node *head)
{
	t_node	*last;
	
	if(!head)
		return (NULL);
	last = head->prev;
	return (last);
}