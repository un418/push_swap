/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pficcare <pficcare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 13:46:38 by pficcare          #+#    #+#             */
/*   Updated: 2026/06/08 13:52:34 by pficcare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	parse_flag(const char *flag, t_ctx *ctx)
{
	if (*flag == '-' && *(flag + 1) == '-')
		flag += 2;
	if (!ctx->mode && is_str_eq(flag, "adaptive"))
		ctx->mode = 1;
	else if (!ctx->mode && is_str_eq(flag, "simple"))
		ctx->mode = 2;
	else if (!ctx->mode && is_str_eq(flag, "medium"))
		ctx->mode = 3;
	else if (!ctx->mode && is_str_eq(flag, "complex"))
		ctx->mode = 4;
	else if (!ctx->bench && is_str_eq(flag, "bench"))
	{
		ctx->bench = 1;
		if (!ctx->mode)
			ctx->mode = 1;
	}
	else
		return (ctx->mode = 0, 0);
	return (1);
}

void	init_ctx(t_ctx *ctx)
{
	ctx->mode = 0;
	ctx->bench = 0;
	ctx->parsed = NULL;
	ctx->parsed_size = 0;
	ctx->stats = (t_bench){0};
}

int	input_validate(const char **argv, t_ctx *ctx)
{
	int	i;
	int	ret;

	i = 1;
	if (!is_flag_prefix(argv[i]))
		ctx->mode = 1;
	while (argv[i] && is_flag_prefix(argv[i]) && i < 3)
	{
		ret = parse_flag(argv[i++], ctx);
		if (!ret)
			return (write(2, "Error\n", 6), 0);
	}
	while (argv[i])
	{
		if (!is_valid_num_fmt(argv[i]) || !in_int_limits(argv[i]))
			return (write(2, "Error\n", 6), 0);
		i++;
	}
	return (1);
}
