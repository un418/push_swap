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
