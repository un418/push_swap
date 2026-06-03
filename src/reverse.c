void	reverse_me(t_node **stack)
{
	(*stack) = (*stack)->prev;
}

void	reverse_a(t_node **stack, t_bench *bench)
{
	bench->count++;
	bench->action++;
	reverse_me(stack);
}

void	reverse_b(t_node **stack, t_bench *bench)
{
	bench->count++;
	bench->action++;
	reverse_me(stack);
}

void	reverse_all(t_node **stack_a, t_node **stack_b, t_bench *bench)
{
	bench->count++;
	bench->action++;
	reverse_me(stack_a);
	reverse_me(stack_b);
}
