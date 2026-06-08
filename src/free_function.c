/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_function.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pficcare <pficcare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 13:46:30 by pficcare          #+#    #+#             */
/*   Updated: 2026/06/08 13:50:51 by pficcare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
