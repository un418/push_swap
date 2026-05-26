#include "push_swap.h"


/* Standard Colors */
#define RED     "\033[0;31m"
#define GREEN   "\033[0;32m"
#define YELLOW  "\033[0;33m"
#define RESET   "\033[0m"

int itest = 1;

// function to compare to result and pretty print the result to tdout
int check(int t1, int t2)
{
	if (t1 == t2)
	{
		printf(GREEN); printf("TEST #%d PASS\n", itest++); printf(RESET);
		printf("\n\n\n");
		return (0);
	}
	else
	{
		printf(RED);
		printf("TEST #%d FAILED: return:%d - expected:%d\n", itest++, t1 , t2);
		printf(RESET);
		return (1);
	}
}

int main()
{
	printf("%d\n",(int)ft_atoi("-2"));

	printf("%d\n",(int)ft_atoi("2147483647"));
	printf("%ld\n",ft_atoi("2147483649"));

	/* 1 */ check(ft_atoi("2"), 3);
	/* 1 */ check(ft_atoi("2"), 2);




	return 0;
}
