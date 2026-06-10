/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_creation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pficcare <pficcare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 13:47:11 by pficcare          #+#    #+#             */
/*   Updated: 2026/06/08 13:53:19 by pficcare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

t_node	*new_node(int nb)
{
	t_node	*new;

	new = malloc(sizeof(t_node));
	if (!new)
		return (NULL);
	new->nb = nb;
	new->index = 0;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

t_node	*get_last(t_node *head)
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
	t_node	*last;

	if (!*head)
	{
		(*head) = new;
		new->next = new;
		new->prev = new;
		return (*head);
	}
	last = (*head)->prev;
	new->prev = last;
	new->next = *head;
	(*head)->prev = new;
	last->next = new;
	return (*head = new);
}

t_node	*fill_stack(int *parsed, int size)
{
	t_node	*stack_a;
	int		i;

	stack_a = NULL;
	i = 0;
	while (i < size)
	{
		if (!add_last(&stack_a, new_node(parsed[i])))
			return (free_nodes(&stack_a), NULL);
		i++;
	}
	return (stack_a);
}
