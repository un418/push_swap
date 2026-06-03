void	print_list(t_node *head)
{
	t_node	*to_print;

	to_print = head;
	while (to_print)
	{
		printf("Value in node = %d\n", to_print->nb);
		to_print = to_print->next;
	//	if (to_print == head)
	//		break;
	}
}

void	print_list_cir(t_node *head)
{
	t_node	*to_print;

	to_print = head;
	while (1)
	{
		printf("Value in node = %d\n", to_print->nb);
		to_print = to_print->next;
		if (to_print == head)
			break;
	}
}

void	print_list_index(t_node *head)
{
	t_node	*to_print;

	to_print = head;
	while (1)
	{
		printf("Value in index = %d\n", to_print->index);
		to_print = to_print->next;
		if (to_print == head)
			break;
	}
}
