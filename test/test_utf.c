/* File to test UFT-8 output o nterminal */

#include <stdio.h>

int main(int argc, char const *argv[])
{
	printf("Simple / O(n\xc2\xb2)");printf("\n");
	printf("Medium / O(n\xe2\x88\x9an)");printf("\n");
	printf("O(n2)");printf("\n");
	printf("O(n√n)");printf("\n");
	printf("O(n log n)");printf("\n");
	return 0;
}
