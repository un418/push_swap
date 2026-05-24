//#include "push_swap.h"
#include <unistd.h>
#include <stdio.h>

int	is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	is_valid_number(char *str)
{
	if (*str == '+' || *str == '-')
		str++;
	while (*str)
		if (!ft_isdigit(*str++))
			return (0);
	return (1);
}

int	is_str_eq(char *s1, char *s2)
{
	while (*s1 && *s2 && *s1++ == *s2++)
		;
	if (*s1 == '\0' && *s2 == '\0')
		return (1);
	else
		return (0);
}

// Return mode or 0 for unvalid flag
int	flags_parser(char *arg)
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

int	flags_check(int ac, char **av)
{
	int	i;
	int	mode;

	if (ac < 2) // A changer, en ==. < pour test
		return(0);
	i = 1;
	mode = ft_check_flags(av[i]);
	if (mode == 0)
		return (write (2, "Error\n", 6));
	// if (mode == 6) A voir ce qu on fait.
	printf("Mode = %d\n", mode);
	i = 2;
	while (av[i])
		if (!ft_isvalid_number(av[i++]))
			return (write (2, "Error2\n", 7));
	return (0);
}
