#include "push_swap.h"

int	ft_atoi(const char *str) // make static after unit test
{
	int	neg;
	long	res;

	neg = 1;
	if (*str == '-')
	{
		neg *= -1;
		str++;
	}
	while(*str)
	{
		res = (res * 10) + (*str - '0');
		str++;
	}
	res = res * neg;
	return (res);
}

int	ft_check_intlimit(const char *str)
{	

	if (ft_atoi(str) < INT_MIN || ft_atoi(str) > INT_MAX)
		return (0);
	return (1);
}



/* 
#include <stdio.h>

int	main(void)
{
	int	res;
	char	*nb = "2147483647";

	res = 0;
	res = ft_atoi(nb);
	printf("Nb = %d\n", res);

	return (0);
}
 */
