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
int	in_int_limits(const char *str)
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
