/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaferna <adaferna@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 19:03:20 by adaferna          #+#    #+#             */
/*   Updated: 2026/06/05 01:53:40 by adaferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, const char **argv)
{
	t_ctx	ctx;
	int		ret;

	init_ctx(&ctx);
	if (argc == 1)
		return (0);
	ret = input_validate(argv, &ctx);
	if (!ret || !ctx.mode)
		return (1);
	printf("Mode = %d\n", ctx.mode); // Debug to remove later
	return (0);
}
