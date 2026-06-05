#include "push_swap.h"

// success: return 1
// error: return 0
int	parse_flag(const char *flag, t_ctx *ctx)
{

	// this check is redudant with the caller function
	// but it improve code readability
	if (*flag == '-' && *(flag + 1) == '-')
		flag += 2;
	if (!ctx->mode && is_str_eq(flag, "adaptive"))
		ctx->mode = 1;
	else if (!ctx->mode  && is_str_eq(flag, "simple"))
		ctx->mode = 2;
	else if (!ctx->mode  && is_str_eq(flag, "medium"))
		ctx->mode = 3;
	else if (!ctx->mode  && is_str_eq(flag, "complex"))
		ctx->mode = 4;
	else if (!ctx->bench  && is_str_eq(flag, "bench"))
	{
		ctx->bench = 1;
		if (!ctx->mode )
			ctx->mode = 1;
	}
	else
		return (ctx->mode = 0, 0);
	return (1);
}

void init_ctx(t_ctx *ctx)
{
	ctx->mode = 0;
	ctx->bench = 0;
	ctx->parsed = NULL;
	ctx->parsed_size = 0;
}

// success: return 1
// error: return 0
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
			return (write (2, "Error\n", 6), 0);
	}
	ret = parse_number(&argv[i], ctx);
	if (!ret)
		return (write (2, "Error\n", 6), 0);
	//need to free ctx->parsed later
	return (1);
}
