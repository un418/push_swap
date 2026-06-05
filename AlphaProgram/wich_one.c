#include "push_swap.h"

void	wich_one(t_node **stack_a, t_node **stack_b, int size, int mode)
{
	if (size <= 1)
		return ;
	if (size == 2)
		return (swap_a(stack_a));
	if (size == 3)
		return (sort_3(stack_a));
    if (size <= 5)
        return (sort_5(stack_a, stack_b));
	// if (mode == 1)
	// 	;
	else if (mode == 2) 
		sort_5(stack_a, stack_b); 
	// else if (mode == 3) 
	// 	;
	// else if (mode == 4)
        // ;
		
}