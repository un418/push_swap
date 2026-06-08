/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pficcare <pficcare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 13:47:14 by pficcare          #+#    #+#             */
/*   Updated: 2026/06/08 17:42:36 by pficcare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* 
Function used to debug when develloping the program.

- To remove before sending the project for evaluation- 
*/

void	print_list_nb(t_node *head)
{
	t_node	*to_print;

	if (!head)
		return ;
	to_print = head;
	while (1)
	{
		printf("Value in node = %d\n", to_print->nb);
		to_print = to_print->next;
		if (to_print == head)
			break ;
	}
}

void	print_list_index(t_node *head)
{
	t_node	*to_print;

	if (!head)
		return ;
	to_print = head;
	while (1)
	{
		printf("Value in index = %d\n", to_print->index);
		to_print = to_print->next;
		if (to_print == head)
			break ;
	}
}
