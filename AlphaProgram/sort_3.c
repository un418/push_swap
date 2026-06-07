#include "push_swap.h"

void	sort_3(t_node **stack_a)
{
    int index_a;
    int index_b;
    int index_c;

    index_a = (*stack_a)->index;
    index_b = (*stack_a)->next->index;
    index_c = (*stack_a)->next->next->index;

    if (index_a > index_b && index_b < index_c && index_a < index_c)
        swap_a(stack_a);
    else if (index_a > index_b && index_b > index_c)
    {
        swap_a(stack_a);
        reverse_a(stack_a);
    }
    else if (index_a > index_b && index_b < index_c && index_a > index_c)
        rotate_a(stack_a);
    else if (index_a < index_b && index_b > index_c && index_a < index_c)
    {
        swap_a(stack_a);
        rotate_a(stack_a);
    }
    else if (index_a < index_b && index_b > index_c && index_a > index_c)
        reverse_a(stack_a);

    write (1, "Sort 3\n", 7);
}