void	rotate_me(t_node **stack)
{
	(*stack) = (*stack)->next;
}

void	rotate_a(t_node **stack, t_bench *bench)
{
	bench->count++;
	bench->action++;
	rotate_me(stack);
}

void	rotate_b(t_node **stack, t_bench *bench)
{
	bench->count++;
	bench->action++;
	rotate_me(stack);
}

void	rotate_all(t_node **stack_a, t_node **stack_b, t_bench *bench)
{
	bench->count++;
	bench->action++;
	rotate_me(stack_a);
	rotate_me(stack_b);
}
