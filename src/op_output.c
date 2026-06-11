/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_output.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaferna <adaferna@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 00:00:00 by adaferna          #+#    #+#             */
/*   Updated: 2026/06/11 00:00:00 by adaferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	write_op(const char *op, t_ctx *ctx)
{
	size_t	len;

	(void)ctx;
	len = 0;
	while (op[len])
		len++;
	write(1, op, len);
}
