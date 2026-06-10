#include <unistd.h>
#include <limits.h>
//#include <stdio.h>

typedef	struct s_node
{
	int pos;
	int value;
	int size;
} t_id;


int	ft_strlen(const char *str)
{
	int	i;

	if (!*str)
		return (0);
	i = 0;
	while (*str)
	{
		i++;
		str++;
	}
	return (i);
}	

long	ft_atoi(const char *str)
{
	int		neg;
	long		res;

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

int	in_int_limits(const char *str)
{
	if (ft_strlen(str) > 12 || ft_strlen(str) <= 0)
		return (0);
	if (ft_atoi(str) < INT_MIN || ft_atoi(str) > INT_MAX)
		return (0);
	return (1);
}

