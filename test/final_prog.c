#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <limits.h>

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

int	is_digit(const char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	is_valid_number(const char *str)
{
	if (*str == '+' || *str == '-')
		str++;
	while (*str)
		if (!is_digit(*str++))
			return (0);
	return (1);
}

int	is_str_eq(const char *s1, const char *s2)
{
	while (*s1 && *s2 && *s1++ == *s2++)
		;
	if (*s1 == '\0' && *s2 == '\0')
		return (1);
	else
		return (0);
}

int	is_flag_prefix(const char *str)
{
	if (*str == '-' && *(str + 1) == '-')
		return (1);
	else
		return (0);
}

int	ft_strlen(const char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (*str)
	{
		i++;
		str++;
	}
	return (i);
}


long	ft_atoi(const char *str)
{
	int		neg;
	long		res;

	neg = 1;
	res = 0;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			neg *= -1;
		str++;
	}
	while (*str)
	{
		res = (res * 10) + (*str - '0');
		str++;
	}
	res = res * neg;
	return (res);
}

int	in_int_limits(const char *str)
{
	if (ft_strlen(str) > 13 || ft_strlen(str) <= 0)
		return (0);
	if (ft_atoi(str) < INT_MIN || ft_atoi(str) > INT_MAX)
		return (0);
	return (1);
}


int	flags_parser(const char *flag)
{
	static	int	mode;

	// this check is redudant with the caller function
	// but it improve code readability
	if (*flag == '-' && *(flag + 1) == '-')
		flag += 2;
	if (mode <= 0 && is_str_eq(flag, "adaptive"))
		mode += 1;
	else if (mode <= 0 && is_str_eq(flag, "simple"))
		mode += 2;
	else if (mode <= 0 && is_str_eq(flag, "medium"))
		mode += 3;
	else if (mode <= 0 && is_str_eq(flag, "complex"))
		mode += 4;
	else if (mode <= 4 && is_str_eq(flag, "bench"))
		mode += 10;
	else
		return (0);
	return (mode);
}

// validate input
// return mode or 0 if input invalid
int	arg_validate(const char **argv)
{
	int	i;
	int	mode;

	i = 1;
	mode = 1;
	while (argv[i] && is_flag_prefix(argv[i]) && i < 3)
	{
		mode = flags_parser(argv[i++]);
		if (mode == 0)
			return (write (2, "ErrorFlag\n", 10), 0);
	}
	while (argv[i])
	{
		if (!is_valid_number(argv[i]) || !in_int_limits(argv[i]))
			return (write (2, "ErrorNb\n", 8), 0);
		i++;
	}
	return (mode);
}


int main(int argc, const char **argv)
{
    int	mode;
    int	i;
    int nb;
    int	stack;
    t_node *stack_a;

    if (argc < 2)
        return (0);
    mode = arg_validate(argv);
    if (mode == 0)
        return (1);
    else
	    printf("Mode = %d\n", mode);
    i = 2;
    if (mode == 1)
	    i = 1;
    nb = 0;
    stack_a = NULL;
    while(argv[i])
    {
	    nb = ft_atoi(argv[i]);
	    printf("Nb atoi = %d\n", nb);
	    add_first(&stack_a, new_node(nb));
	    printf("Nb = %d\n", nb);
	    i++;
    }
    print_list_cir(stack_a);
    ft_indexator(stack_a);
    print_list_index(stack_a);
    stack = 0;
    stack = stack_size(stack_a);
    printf("Stack size is = %d\n", stack);
    free_nodes(&stack_a);
    printf("Head = %p", stack_a);

    return (0);
}
//
// int	main(void)
// {
// 	t_node	*stack_a;
// 	//int	nb = 1;
// 	int 	i;
//
// 	stack_a = NULL;
// 	//stack_a = new_node(nb);
// 	//print_list(stack_a);
// 	i = 0;
// 	// while (i < 8)
// 	// {
// 	// 	add_last(&stack_a, new_node(i));
// 	// 	i++;
// 	// }
//
// 	while (i < 8)
// 	{
// 		add_first(&stack_a, new_node(i));
// 		i++;
// 	}
// 	print_list_cir(stack_a);
//
//
// 	free_nodes(&stack_a);
// 	printf("Head = %p", stack_a);
//
// 	return (0);
//
// }

// idee pour gagner du temps, une fois indexer, faire une median, si nb > a l median on call add first, sinon add last, pour deja faire un pre tri qui va reduire le disorder.
