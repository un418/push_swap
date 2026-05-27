#include <unistd.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

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

int	is_flag_prefix(const char *str)
{
	if (*str == '-' && *(str + 1) == '-')
		return (1);
	else
		return (0);
}

int	ft_strlen(const char *str)
{
	int	i;

	if (!str)
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
	if (ft_strlen(str) > 13 || ft_strlen(str) <= 0)
		return (0);
	if (ft_atoi(str) < INT_MIN || ft_atoi(str) > INT_MAX)
		return (0);
	return (1);
}


int	flags_parser(const char *flag)
{
	static	int	mode;

	// this check is redudant with the caller function
	// but it improve code readability
	if (*flag == '-' && *(flag + 1) == '-')
		flag += 2;
	if (mode <= 0 && is_str_eq(flag, "adaptive"))
		mode += 1;
	else if (mode <= 0 && is_str_eq(flag, "simple"))
		mode += 2;
	else if (mode <= 0 && is_str_eq(flag, "medium"))
		mode += 3;
	else if (mode <= 0 && is_str_eq(flag, "complex"))
		mode += 4;
	else if (mode <= 4 && is_str_eq(flag, "bench"))
		mode += 10;
	else
		return (0);
	return (mode);
}

// validate input
// return mode or 0 if input invalid
int	arg_validate(const char **argv)
{
	int	i;
	int	mode;

	i = 1;
	mode = 1;
	while (argv[i] && is_flag_prefix(argv[i]) && i < 3)
	{
		mode = flags_parser(argv[i++]);
		if (mode == 0)
			return (write (2, "ErrorFlag\n", 10), 0);
	}
	while (argv[i])
	{
		if (!is_valid_number(argv[i]) || !in_int_limits(argv[i]))
			return (write (2, "ErrorNb\n", 8), 0);
		i++;
	}
	return (mode);
}


int main(int argc, const char **argv)
{
    int	mode;
    int	i;
    int nb;

    if (argc < 2)
        return (0);
    mode = arg_validate(argv);
    if (mode == 0)
        return (1);
    else
	    printf("Mode = %d\n", mode);
    i = 2;
    if (mode == 1)
	    i = 1;
    while(argv[i])
    {
	    nb = ft_atoi(argv[i]);
	    printf("Nb = %d\n", nb);
	    i++;
    }

    return (0);
}
