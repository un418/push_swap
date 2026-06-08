/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaferna <adaferna@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 22:02:19 by adaferna          #+#    #+#             */
/*   Updated: 2026/06/08 22:04:34 by adaferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_nodes(t_node **head)
{
	t_node	*next;
	t_node	*last;

	if (!*head)
		return ;
	last = (*head)->prev;
	last->next = NULL;
	while (*head != NULL)
	{
		next = (*head)->next;
		free(*head);
		*head = next;
	}
	*head = NULL;
}

int	stack_size(t_node *head)
{
	int		size;
	t_node	*current;

	if (!head)
		return (0);
	current = head;
	size = 0;
	while (1)
	{
		current = current->next;
		size++;
		if (current == head)
			break ;
	}
	return (size);
}
