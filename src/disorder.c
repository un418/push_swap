/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pficcare <pficcare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 13:46:21 by pficcare          #+#    #+#             */
/*   Updated: 2026/06/08 13:50:28 by pficcare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

float	disorder(t_node *head)
{
	int		mistake;
	int		total;
	t_node	*i;
	t_node	*j;

	if (!head)
		return (0);
	total = stack_size(head);
	total = (total * (total - 1) / 2);
	i = head;
	j = head->next;
	mistake = 0;
	while (i->next != head)
	{
		while (j != head)
		{
			if (i->nb > j->nb)
				mistake++;
			j = j->next;
		}
		i = i->next;
		j = i->next;
	}
	return ((float)mistake / total);
}
