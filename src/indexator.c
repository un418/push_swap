/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaferna <adaferna@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 14:10:49 by pficcare          #+#    #+#             */
/*   Updated: 2026/06/08 22:03:15 by adaferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count_smaller(t_node *head, t_node *ref)
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
		current->index = count_smaller(head, current);
		current = current->next;
		if (current == head)
			break ;
	}
}
