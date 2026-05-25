#include "push_swap.h"

// Return mode or 0 for unvalid flag
int	flags_parser(const char *arg)
{
	int static mode;

	if (*arg == '-' && *(arg + 1) == '-')
		arg += 2;
	if (mode <= 0 && is_str_eq(arg, "adaptive"))
		mode += 1;
	else if (mode <= 0 && is_str_eq(arg, "simple"))
		mode += 2;
	else if (mode <= 0 && is_str_eq(arg, "medium"))
		mode += 3;
	else if (mode <= 0 && is_str_eq(arg, "complex"))
		mode += 4;
	else if (is_str_eq(arg, "bench"))
		mode += 10;
	else
		return (0);
	return (mode);
}

// validate input
// return mode or 0 if input invalid
int	arg_validate(const char **argv)
{
	int	i;
	int	mode;

	i = 1;
	mode = 1;
	while (argv[i] && is_flag_prefix(argv[i]) && i < 3)
	{
		mode = flags_parser(argv[i++]);
		if (mode == 0)
			return (write (2, "Error\n", 6), 0);
	}
	while (argv[i])
		if (!is_valid_number(argv[i++]))
			return (write (2, "Error2\n", 7), 0);
	return (mode);
}
