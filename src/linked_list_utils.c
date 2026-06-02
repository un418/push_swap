#include <stdlib.h>

typedef struct s_node
{
	int				nb;

	struct s_node	*next;
	struct s_node	*prev;

}					t_node;

int	stack_size(t_node *head)
{
	int		size;
	t_node	*loop;

	loop = head;
	size = 0;
	while (1)
	{
		loop = loop->next;
		size++;
		if (loop == head)
			break ;
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

	if (!head)
		return (NULL);
	last = head->prev;
	return (last);
}

t_node	*add_last(t_node **head, t_node *new)
{
	t_node	*last;

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

t_node	*add_first(t_node **head, t_node *new)
{
	t_node	*first;

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

void	free_nodes(t_node **head)
{
	t_node *next_free;
	t_node *last;

	if (*head == NULL)
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