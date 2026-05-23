//#include "push_swap.h"
#include <unistd.h>
#include <limits.h>


int	ft_check_intlimit(long nb)
{	
	if (nb < INT_MIN || nb > INT_MAX)
		return (0);
	return (1);
}

int	ft_atoi(char *str)
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
	if (!ft_check_intlimit(res))
		return (-1);
	return (res);
}

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

