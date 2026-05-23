//#include "push_swap.h"
#include <unistd.h>
#include <stdio.h>

int	ft_isdigit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_isvalid_number(char *str)
{
	if (*str == '+' || *str == '-')
		str++;
	while (*str)
		if (!ft_isdigit(*str++))
			return (0);
	return (1);
}

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 == *s2 && *s1)
	{
		s1++;
		s2++;
	}
	if (*s1 == '\0' && *s2 == '\0')
		return (1);
	else
		return (0);
}

int	ft_parser(char *av)
{
	char	*spl = "simple";
	char	*med = "medium";
	char	*comp = "complex";
	char	*ada = "adaptive";
	char	*ben = "bench";
	
	while (*av == '-')
		av++;
	if (*av == 's' && ft_strcmp(av, spl))
		return (2);
	if (*av == 'm' && ft_strcmp(av, med))
		return (3);
	if (*av == 'c' && ft_strcmp(av, comp))
		return (4);
	if (*av == 'a' && ft_strcmp(av, ada))
		return (5);
	if (*av == 'b'&& ft_strcmp(av, ben))
		return (6);
	return (0);
}

int	ft_check_flags(char *av)
{
	if (*av == '-' && *(av + 1) == '-')
		return (ft_parser(av));
	else
		return (0);
}

int	main(int ac, char **av)
{
	int	i;
	int	mode;

	if (ac < 2) // A changer, en ==. < pour test
		return(0);
	i = 1;
	mode = ft_check_flags(av[i]);
	if (mode == 0)
		return (write (1, "ERROR", 5));
	// if (mode == 6) A voir ce qu on fait.
	printf("Mode = %d\n", mode);
	i = 2;
	while (av[i])
		if (!ft_isvalid_number(av[i++]))
			return (write (1, "ERROR2", 6));
	return (0);
}
