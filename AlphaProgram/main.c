#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_node	*stack_a;
	t_node	*stack_b;
	int		*parsed;
	int		i;
	int		size;
	//int		mode;
	t_ctx	ctx;
	int		ret;

	if (argc < 2)
		return (0);
	i = 1;
	init_ctx(&ctx);
	ret = input_validate((const char **)argv, &ctx);
	if (!ret || !ctx.mode)
		return (1);
	printf("Mode = %d\n", ctx.mode); 

	while (argv[i] && is_flag_prefix(argv[i]) && i < 3)
		i++;
	size = argc - i;
	parsed = parse_number((const char **)&argv[i], &ctx);
	if (!parsed)
		return (write(2, "Error\n", 6), 1);
	stack_a = fill_stack(parsed, size);
	free(parsed);
	if (!stack_a)
		return (write(2, "Error\n", 6), 1);
	stack_b = NULL;
	ft_indexator(stack_a);
	wich_one(&stack_a, &stack_b, size, &ctx);
	print_list_index(stack_a);
	print_list(stack_a);
	free_nodes(&stack_a);
	free_nodes(&stack_b);
	printf("Stack_a head = %p\n", stack_a);
	printf("Stack_b head = %p\n", stack_b);
	return (0);
}
