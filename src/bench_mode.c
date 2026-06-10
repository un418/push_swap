/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench_mode.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaferna <adaferna@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 18:35:04 by adaferna          #+#    #+#             */
/*   Updated: 2026/06/10 09:08:52 by adaferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// To do:
// Implement Submode to print the adaptive selection.
// Use ft_printf for stderr
// Manage float rounding and printing via int

static char *strategy_name(int mode)
{
	char *s1 = "Adaptive";
	char *s2 = "Simple";
	char *s3 = "Medium";
	char *s4 = "Complex";

	if (mode == 1)
		return (s1);
	else if (mode == 2)
		return (s2);
	else if (mode == 3)
		return (s3);
	else if (mode == 4)
		return (s4);
	else
		return (NULL);
}

void	print_bench(t_ctx *ctx)
{
	printf("[bench] disorder:   %f\n", ctx->disorder);
	printf("[bench] strategy:   %s\n", strategy_name(ctx->mode));
	printf("[bench] total_ops:   %d\n", ctx->stats.total);
	printf("[bench] sa:   %d   ", ctx->stats.sa);
	printf("sb:   %d   ss:   %d   ", ctx->stats.sb, ctx->stats.ss);
	printf("pa:   %d   pb:   %d\n", ctx->stats.pa, ctx->stats.pb);
	printf("[bench] ra:   %d   ", ctx->stats.ra);
	printf("rb:   %d   rr:   %d   ", ctx->stats.rb, ctx->stats.rr);
	printf("rra:   %d   rrb:   %d", ctx->stats.rra, ctx->stats.rrb);
	printf("rrr:   %d\n", ctx->stats.rrr);
}
