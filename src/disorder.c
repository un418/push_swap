typedef struct s_node
{
	int	nb;
	struct s_node	*next;
	struct s_node	*prev;

} t_node;


float	disorder(t_node *head)
{
	int mistake;
	int total;
	int l_size;
	t_node	*i;
	t_node	*j;

	if (!head)
		return (0); 

	//l_size = stack_size(head);
	i = head;
	j = head->next;
	mistake = 0;
	total = 0;

	while (1)
	{
		while (1)
		{
			if (i->nb > j->nb)
				mistake++;
			total++;
			j = j->next;
			if (j == i)
				break;
		}
		i = i->next;
		j = i->next;
		if (i == head)
			break;
	}
	return ((float)mistake / total);

}
