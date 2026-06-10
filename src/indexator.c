/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pficcare <pficcare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 14:10:49 by pficcare          #+#    #+#             */
/*   Updated: 2026/06/10 11:32:58 by pficcare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	add_index(t_node *head, t_node *ref)
{
	t_node	*current;
	int		count;

	current = head;
	count = 0;
	while (1)
	{
		if (current != ref && current->nb < ref->nb)
			count++;
		current = current->next;
		if (current == head)
			break ;
	}
	return (count);
}

void	indexator(t_node *head)
{
	t_node	*current;

	if (!head)
		return ;
	current = head;
	while (1)
	{
		current->index = add_index(head, current);
		current = current->next;
		if (current == head)
			break ;
	}
}
