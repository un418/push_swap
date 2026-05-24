/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaferna <adaferna@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 19:03:20 by adaferna          #+#    #+#             */
/*   Updated: 2026/05/24 18:16:59 by adaferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int main(int argc, const char **argv)
{
	int	mode;

	if (argc < 2)
		return(0);
	mode = arg_validate(argv);
	if (mode == 0)
		return (-1);
	printf("Mode = %d\n", mode); // Debug to remove later

	return (0);
}
