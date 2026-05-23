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
		neg *= -1;
	while(*str)
	{
		res = (res * 10) + (*str - '0');
		str++;
	}
	if (!ft_check_intlimit(res))
		return (0);
	return ((int)res * neg);
}


int	main(int ac, char **av)
{

	if (ac < 2) // A changer, en ==. < pour test
		return(0);	

	return (0);
}

