/* File to test UFT-8 output o nterminal */

// run : cc test_utf.c -I../lib/ft_printf/inc ../lib/ft_printf/libftprintf.a && ./a.out

#include <stdio.h>
#include "ft_printf.h"

int main(int argc, char const *argv[])
{
	printf("Simple / O(n\xc2\xb2)");printf("\n");
	printf("Medium / O(n\xe2\x88\x9an)");printf("\n");
	printf("O(n²)");printf("\n");
	printf("O(n√n)");printf("\n");
	printf("O(n log n)");printf("\n");

	ft_dprintf(FT_STDERR, "Simple / O(n\xc2\xb2)");ft_dprintf(FT_STDERR, "\n");
	ft_dprintf(FT_STDERR, "Medium / O(n\xe2\x88\x9an)");ft_dprintf(FT_STDERR, "\n");
	ft_dprintf(FT_STDERR, "O(n²)");ft_dprintf(FT_STDERR, "\n");
	ft_dprintf(FT_STDERR, "O(n√n)");ft_dprintf(FT_STDERR, "\n");
	ft_dprintf(FT_STDERR, "O(n log n)");ft_dprintf(FT_STDERR, "\n");
	return 0;
}
