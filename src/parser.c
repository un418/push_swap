#include "push_swap.h"

int	is_digit(const char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	is_valid_number(const char *str)
{
	if (*str == '+' || *str == '-')
		str++;
	while (*str)
		if (!is_digit(*str++))
			return (0);
	return (1);
}

int	is_str_eq(const char *s1, const char *s2)
{
	while (*s1 && *s2 && *s1++ == *s2++)
		;
	if (*s1 == '\0' && *s2 == '\0')
		return (1);
	else
		return (0);
}

// Return mode or 0 for unvalid flag
int	flags_parser(const char *arg)
{

	if (*arg == '-' && *(arg + 1) == '-')
	arg += 2;
	if (is_str_eq(arg, "adaptive"))
		return (1);
	else if (is_str_eq(arg, "simple"))
		return (2);
	else if (is_str_eq(arg, "medium"))
		return (3);
	else if (is_str_eq(arg, "complex"))
		return (4);
	else if (is_str_eq(arg, "bench"))
		return (-1);
	else
		return (0);
}

// validate input
// return mode or 0 if input invalid
int	arg_validate(const char **argv)
{
	int	i;
	int	mode;

	i = 1;
	mode = 1;
	while ( argv[i] && i < 3 )
		mode *= flags_parser(argv[i++]);
	if (mode == 0 || -4 < mode || mode > 4)
		return (write (2, "Error\n", 6), 0);
	while (argv[i])
		if (!is_valid_number(argv[i++]))
			return (write (2, "Error2\n", 7), 0);
	return (mode);
}
