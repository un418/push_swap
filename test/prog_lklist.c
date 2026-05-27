#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

typedef struct s_node
{
	int nb;
	int index;

	struct s_node *next;
	struct s_node *prev;
} t_node;

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

int	main(void)
{
	t_node	*stack_a;
	//int	nb = 1;
	int 	i;

	stack_a = NULL;
	//stack_a = new_node(nb);
	//print_list(stack_a);
	i = 0;
	// while (i < 8)
	// {
	// 	add_last(&stack_a, new_node(i));
	// 	i++;
	// }

	while (i < 8)
	{
		add_first(&stack_a, new_node(i));
		i++;
	}
	print_list_cir(stack_a);


	free_nodes(&stack_a);
	printf("Head = %p", stack_a);

	return (0);

}

// idee pour gagner du temps, une fois indexer, faire une median, si nb > a l median on call add first, sinon add last, pour deja faire un pre tri qui va reduire le disorder.
