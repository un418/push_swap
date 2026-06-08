/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pficcare <pficcare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 14:10:49 by pficcare          #+#    #+#             */
/*   Updated: 2026/06/08 14:13:42 by pficcare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count_smaller(t_node *head, t_node *a_value)
{
	t_node	*n_value;
	int		index;

	n_value = head;
	index = 0;
	while (1)
	{
		if (n_value != a_value && n_value->nb < a_value->nb)
			index++;
		n_value = n_value->next;
		if (n_value == head)
			break ;
	}
	return (index);
}

void	ft_indexator(t_node *head)
{
	t_node	*a_value;

	if (!head)
		return ;
	a_value = head;
	while (1)
	{
		a_value->index = count_smaller(head, a_value);
		a_value = a_value->next;
		if (a_value == head)
			break ;
	}
}

// void	ft_indexator(t_node *head)
// {
// 	t_node	*a_value;
// 	t_node	*n_value;
// 	int		index;

// 	if (!head)
// 		return ;
// 	index = 0;
// 	a_value = head;
// 	n_value = head->next;
// 	while (1)
// 	{
// 		while (1)
// 		{
// 			if (a_value->nb > n_value->nb)
// 				index++;
// 			n_value = n_value->next;
// 			if (n_value == a_value)
// 				break ;
// 		}
// 		a_value->index = index;
// 		a_value = a_value->next;
// 		n_value = a_value->next;
// 		index = 0;
// 		if (a_value == head)
// 			break ;
// 	}
// }
