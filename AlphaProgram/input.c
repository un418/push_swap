#include "push_swap.h"

// return mode or 0 for invalid flag
int	parse_flag(const char *flag)
{
	static int	mode;

	// this check is redudant with the caller function
	// but it improve code readability
	if (*flag == '-' && *(flag + 1) == '-')
		flag += 2;
	if (mode <= 0 && is_str_eq(flag, "adaptive"))
		mode += 1;
	else if (mode <= 0 && is_str_eq(flag, "simple"))
		mode += 2;
	else if (mode <= 0 && is_str_eq(flag, "medium"))
		mode += 3;
	else if (mode <= 0 && is_str_eq(flag, "complex"))
		mode += 4;
	else if (mode <= 4 && is_str_eq(flag, "bench"))
		mode += 10;
	else
		return (0);
	return (mode);
}

// return mode or 0 if input invalid
int	input_validate(const char **argv)
{
	int		i;
	int		mode;

	i = 1;
	mode = 1;
	while (argv[i] && is_flag_prefix(argv[i]) && i < 3)
	{
		mode = parse_flag(argv[i++]);
		if (mode == 0)
			return (write (2, "Error\n", 6), 0);
	}
	while (argv[i])
	{
		if (!is_valid_num_fmt(argv[i]) || !in_int_limits(argv[i]))
			return (write(2, "Error\n", 6), 0);
		i++;
	}
	//need to free parsed later
	return (mode);
}