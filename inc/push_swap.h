/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pficcare <pficcare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 18:59:57 by adaferna          #+#    #+#             */
/*   Updated: 2026/05/22 13:42:11 by pficcare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H


typedef struct s_node
{
    int nb;
    int index;
    
    struct s_node *next;
    struct s_node *prev;

} t_node;

# endif