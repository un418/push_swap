#include "push_swap.h"

long	ft_atol(const char *str)
{
	int		neg;
	long	res;

	neg = 1;
	res = 0;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			neg *= -1;
		str++;
	}
	while (*str)
	{
		res = (res * 10) + (*str - '0');
		str++;
	}
	res = res * neg;
	return (res);
}

// valid:   "42", "+42", "-42", "2147483647", "-2147483648"
// invalid: "2147483648" (> INT_MAX), "-2147483649" (< INT_MIN), 10 digits (guards ft_atol from long overflow)
int		in_int_limits(const char *str)
{
	const char	*digits;
	int			len;
	long		n;

	digits = str;
	if (*digits == '-' || *digits == '+')
		digits++;
	len = 0;
	while (digits[len])
		len++;
	if (len > 10)
		return (0);
	n = ft_atol(str);
	if (n < INT_MIN || n > INT_MAX)
		return (0);
	return (1);
}

static size_t	tablen(char **tab)
{
	size_t i;

	while (tab[i])
		i++;
	return(i);
}

// error: return 0 if duplicate -> nedd to free
// sucess: return 1 & add number in the tab of parsed number
static int		check_duplicate (const char *str , int *tab)
{
	int num;

	num = ft_atol(str);
	while (tab)
	{
		if (num == tab)
			return (0);
		tab++;
	}
	return(*tab = num, 1);
}

int*	parse_number(const char **argv)
{
	int i;
	int* ret;
	size_t tabsize;

	i = 0;
	tabsize = tabslen(argv);
	// todo protect malloc from heap buffer overflow
	ret = malloc((tabsize * sizeof(int)) + 1);
	if (ret == NULL)
		return(NULL);
	while (argv[i])
	{
		if (!is_digit(argv[i]) 
		|| !is_valid_num_fmt(argv[i])
		|| !in_int_limits(argv[i])
		|| !check_duplicate(argv[i], ret))
			return (free(ret), NULL);
	}
	return (ret);
}
