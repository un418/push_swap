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

// disorder is a ratio in [0, 1].
// We show it as a percentage with 2 decimals.
// disorder * 10000 packs both into one int: / 100 is the whole part,
// % 100 is the 2 decimals (truncated, no rounding).
static void	split_pct(float disorder, int *whole, int *frac)
{
	int	pct;

	pct = (int)(disorder * 10000);
	*whole = pct / 100;
	*frac = pct % 100;
}

static char	*strategy_name(t_ctx *ctx)
{
	if (ctx->mode == 2)
		return ("Simple / O(n²)");
	if (ctx->mode == 3)
		return ("Medium / O(n√n)");
	if (ctx->mode == 4)
		return ("Complex / O(n log n)");
	if (ctx->disorder < 0.2)
		return ("Adaptive / O(n²)");
	if (ctx->disorder < 0.5)
		return ("Adaptive / O(n√n)");
	return ("Adaptive / O(n log n)");
}

void	print_bench(t_ctx *ctx)
{
	int	whole;
	int	frac;

	split_pct(ctx->disorder, &whole, &frac);
	ft_dprintf(2, "[bench] disorder: %d.", whole);
	if (frac < 10)
		ft_dprintf(2, "0");
	ft_dprintf(2, "%d%%\n", frac);
	ft_dprintf(2, "[bench] strategy: %s\n", strategy_name(ctx));
	ft_dprintf(2, "[bench] total_ops: %d\n", ctx->stats.total);
	ft_dprintf(2, "[bench] sa: %d ", ctx->stats.sa);
	ft_dprintf(2, "sb: %d ss: %d  ", ctx->stats.sb, ctx->stats.ss);
	ft_dprintf(2, "pa: %d  pb: %d\n", ctx->stats.pa, ctx->stats.pb);
	ft_dprintf(2, "[bench] ra: %d ", ctx->stats.ra);
	ft_dprintf(2, "rb: %d rr: %d ", ctx->stats.rb, ctx->stats.rr);
	ft_dprintf(2, "rra: %d  rrb: %d ", ctx->stats.rra, ctx->stats.rrb);
	ft_dprintf(2, "rrr: %d\n", ctx->stats.rrr);
}
