
typedef	struct	s_node
{
	int	value;

	struct s_node *next;
	struct s_node *prev;
} t_node;

int	check_duplicate(t_node *head)
{
	t_node	*first;
	t_node	*second;

	if (!head)
		return (1);
	first = head;
	second = head->next;

	while (1)
	{
		while (1)
		{
			if (first->value == second->value)
				return (0);
			if (second == first)
				break;
			second = second->next;
		}
		first = first->next;
		second = first->next;
		if (first == head)
			break;
	}
	return (1);
}

