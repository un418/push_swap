/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaferna <adaferna@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 19:03:20 by adaferna          #+#    #+#             */
/*   Updated: 2026/05/25 00:55:55 by adaferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, const char **argv)
{
	int	mode;

	if (argc == 1)
		return (0);
	mode = input_validate(argv);
	if (mode == 0)
		return (1);
	printf("Mode = %d\n", mode); // Debug to remove later
	return (0);
}
