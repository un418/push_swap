/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pficcare <pficcare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 18:59:57 by adaferna          #+#    #+#             */
/*   Updated: 2026/05/22 16:09:05 by pficcare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

/*---- Structure----*/

typedef struct s_node
{
	int				nb;
	int				index;

	struct s_node	*next;
	struct s_node	*prev;

}					t_node;

/*----Function Prototype----*/

int					ft_isvalid_number(char *str);
int					ft_isdigit(char c);
int					ft_strcmp(char *s1, char *s2);
int					ft_selector(char *str);

/*----XXX----*/

#endif