#include "push_swap.h"

int ft_isdigit(int nb)
{
    if (nb >= '0' && nb <= '9')
        return (1);
    return (0);
}

int ft_isvalid_number(char *str)
{
    if (*str == '+' || *str == '-')
    {
        str++;
        if (*str == '+' || *str == '-')
            return (0);
    }
    while (*str)
    {
        if (*str < 48 && *str > 57)
            return (0);
        str++;
    }
    return (1);
}