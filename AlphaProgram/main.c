#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_node	*stack_a;
	t_node	*stack_b;
	int		*parsed;
	int		mode;
	int		size;
	int		i;

	if (argc < 2)
		return (0);
	mode = input_validate((const char **)argv);
	if (mode == 0)
		return (1);
	i = 1;
	while (argv[i] && is_flag_prefix((const char *)argv[i]) && i < 3)
		i++;
	parsed = parse_number((const char **)&argv[i]);
	if (!parsed)
		return (write(2, "Error\n", 6), 1);
	stack_a = NULL;
	stack_b = NULL;
	size = 0;
	while (argv[i + size])
	{
		add_last(&stack_a, new_node(parsed[size]));
		size++;
	}
	free(parsed);
	ft_indexator(stack_a);

	if (size == 2)
		swap_a(&stack_a);
	else if (size == 3)
		sort_3(&stack_a);
	else if (size == 4 || size == 5)
		sort_5(&stack_a, &stack_b);

	print_list(stack_a);
	print_list_index(stack_a);

	free_nodes(&stack_a);
	free_nodes(&stack_b);
	return (0);
}