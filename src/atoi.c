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

/*  overflow protection is handled here, not in ft_atol */
int	in_int_limits(const char *str)
{
	const char	*digits;
	int			len;

	digits = str;
	if (*digits == '-' || *digits == '+')
		digits++;
	len = 0;
	while (digits[len])
		len++;
	if (len > 10)
		return (0);
	if (ft_atol(str) < INT_MIN || ft_atol(str) > INT_MAX)
		return (0);
	return (1);
}
