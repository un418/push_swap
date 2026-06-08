/* ************************************************************************** */
/*                                                                            */
/*   unit_test.c                                                              */
/*                                                                            */
/*   Unit tests for push_swap.                                                */
/*   Build & run : make unit_test   (exits != 0 if any test fails)            */
/*                                                                            */
/*   Not subject to 42 norm (string literal concatenation).                   */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

// colors
#define RED     "\033[0;31m"
#define GREEN   "\033[0;32m"
#define YELLOW  "\033[0;33m"
#define RESET   "\033[0m"

static int	g_tests;
static int	g_fails;

typedef struct s_suite
{
	int test_all;
	int ft_atol; int in_int_limits; int is_valid_num_fmt; int parse_number;
	int stack_size_suite; int list_creation; int ft_indexator_suite;
}	t_suite;

// long params cover int and the long returned by ft_atol without truncation
int	check(const char *label, long got, long expected)
{
	g_tests++;
	if (got == expected)
	{
		printf(GREEN "[PASS]" RESET " %s\n", label);
		return (0);
	}
	printf(RED "[FAIL]" RESET " %s: got %ld expected %ld\n",
		label, got, expected);
	g_fails++;
	return (1);
}

void	print_summary(void)
{
	printf("\n");
	if (g_fails == 0)
		printf(GREEN "==> %d/%d passed\n" RESET, g_tests - g_fails, g_tests);
	else
		printf(RED "==> %d/%d passed (%d failed)\n" RESET,
			g_tests - g_fails, g_tests, g_fails);
}

t_suite	parse_args(int argc, const char **argv)
{
	t_suite	s;
	int		selected;
	int		i;

	s = (t_suite){0};
	selected = 0;
	i = 1;
	while (i < argc)
	{
		if (is_str_eq(argv[i], "--test-all"))
			s.test_all = 1;
		else if (is_str_eq(argv[i], "--ft_atol"))
			s.ft_atol = 1;
		else if (is_str_eq(argv[i], "--in_int_limits"))
			s.in_int_limits = 1;
		else if (is_str_eq(argv[i], "--is_valid_num_fmt"))
			s.is_valid_num_fmt = 1;
		else if (is_str_eq(argv[i], "--parse_number"))
				s.parse_number = 1;
		else if (is_str_eq(argv[i], "--stack_size"))
			s.stack_size_suite = 1;
		else if (is_str_eq(argv[i], "--list_creation"))
			s.list_creation = 1;
		else if (is_str_eq(argv[i], "--ft_indexator"))
			s.ft_indexator_suite = 1;
		else
		{
			fprintf(stderr, RED "unknown suite: %s\n" RESET, argv[i]);
			exit(1);
		}
		selected++;
		i++;
	}
	if (!selected)
		s.test_all = 1;
	return (s);
}

int	main(int argc, const char **argv)
{
	t_suite	s;

	s = parse_args(argc, argv);
	if (s.ft_atol || s.test_all)
	{
		printf(YELLOW "--- ft_atol ---\n" RESET);
		check("atol \"0\"", ft_atol("0"), 0);
		check("atol \"42\"", ft_atol("42"), 42);
		check("atol \"-42\"", ft_atol("-42"), -42);
		check("atol \"+42\"", ft_atol("+42"), 42);
		check("atol INT_MAX", ft_atol("2147483647"), INT_MAX);
		check("atol INT_MIN", ft_atol("-2147483648"), INT_MIN);
		check("atol INT_MAX+1 (no truncation)", ft_atol("2147483648"), 2147483648L);
	}
	if (s.in_int_limits || s.test_all)
	{
		printf(YELLOW "\n--- in_int_limits ---\n" RESET);
		check("limits INT_MAX ok", in_int_limits("2147483647"), 1);
		check("limits INT_MAX+1 reject", in_int_limits("2147483648"), 0);
		check("limits INT_MIN ok", in_int_limits("-2147483648"), 1);
		check("limits INT_MIN-1 reject", in_int_limits("-2147483649"), 0);
		check("limits \"0\" ok", in_int_limits("0"), 1);
	}
	if (s.is_valid_num_fmt || s.test_all)
	{
		printf(YELLOW "\n--- is_valid_num_fmt ---\n" RESET);
		check("valid \"+\" alone reject", is_valid_num_fmt("+"), 0);
		check("valid \"-\" alone reject", is_valid_num_fmt("-"), 0);
		check("valid \"+0\"", is_valid_num_fmt("+0"), 1);
		check("valid \"-0\"", is_valid_num_fmt("-0"), 1);
		check("valid \"42\"", is_valid_num_fmt("42"), 1);
		check("valid \"-3\"", is_valid_num_fmt("-3"), 1);
		check("valid \"abc\" reject", is_valid_num_fmt("abc"), 0);
	}

	if (s.parse_number || s.test_all)
	{
		printf(YELLOW "\n--- parse_number ---\n" RESET);
		{
			const char *input[] = {"1", "-1", "42", NULL};
			t_ctx ctx = {0};
			int ret = parse_number(input, &ctx);
			check("parse_number valid size3 ret", ret, 1);
			check("parse_number valid size3 [0]", ctx.parsed[0], 1);
			check("parse_number valid size3 [1]", ctx.parsed[1], -1);
			check("parse_number valid size3 [2]", ctx.parsed[2], 42);
			check("parse_number valid size3 size", (long)ctx.parsed_size, 3);
			free(ctx.parsed);
		}
		{
			const char *input[] = {"1", NULL};
			t_ctx ctx = {0};
			int ret = parse_number(input, &ctx);
			check("parse_number valid size1 ret", ret, 1);
			check("parse_number valid size1 [0]", ctx.parsed[0], 1);
			check("parse_number valid size1 size", (long)ctx.parsed_size, 1);
			free(ctx.parsed);
		}
		{
			const char *input[] = {NULL};
			t_ctx ctx = {0};
			int ret = parse_number(input, &ctx);
			check("parse_number empty num list", ret, 0);
			check("parse_number empty leaves parsed NULL", (long)ctx.parsed, 0);
		}
		{
			const char *input[] = {"a1", "-1", "42", NULL};
			t_ctx ctx = {0};
			int ret = parse_number(input, &ctx);
			check("parse_number unvalid at start", ret, 0);
			check("parse_number unvalid at start parsed NULL", (long)ctx.parsed, 0);
		}
		{
			const char *input[] = {"1", "-1", "4a2", NULL};
			t_ctx ctx = {0};
			int ret = parse_number(input, &ctx);
			check("parse_number unvalid at end", ret, 0);
			check("parse_number unvalid at end parsed NULL", (long)ctx.parsed, 0);
		}
		{
			const char *input[] = {"1", "1", "42", NULL};
			t_ctx ctx = {0};
			int ret = parse_number(input, &ctx);
			check("parse_number positive duplicate", ret, 0);
			check("parse_number positive duplicate parsed NULL", (long)ctx.parsed, 0);
		}
		{
			const char *input[] = {"-1", "-1", "42", NULL};
			t_ctx ctx = {0};
			int ret = parse_number(input, &ctx);
			check("parse_number negative duplicate", ret, 0);
			check("parse_number negative duplicate parsed NULL", (long)ctx.parsed, 0);
		}
		{
			const char *input[] = {"-1", "42", "-1", NULL};
			t_ctx ctx = {0};
			int ret = parse_number(input, &ctx);
			check("parse_number negative duplicate start/end", ret, 0);
			check("parse_number negative duplicate start/end parsed NULL", (long)ctx.parsed, 0);
		}
	}


	if (s.stack_size_suite || s.test_all)
	{
		printf(YELLOW "\n--- stack_size ---\n" RESET);
		check("stack_size NULL", stack_size(NULL), 0);
		{
			t_node	*list;

			list = NULL;
			add_last(&list, new_node(7));
			check("stack_size 1 node", stack_size(list), 1);
			free_nodes(&list);
		}
		{
			int		arr[] = {3, 1, 2};
			t_node	*list;

			list = fill_stack(arr, 3);
			check("stack_size 3 nodes", stack_size(list), 3);
			free_nodes(&list);
		}
	}
	if (s.list_creation || s.test_all)
	{
		printf(YELLOW "\n--- list_creation ---\n" RESET);
		{
			t_node	*n;

			n = new_node(42);
			check("new_node nb", n->nb, 42);
			check("new_node index", n->index, 0);
			free(n);
		}
		{
			t_node	*list;

			list = NULL;
			add_last(&list, new_node(10));
			check("add_last empty size", stack_size(list), 1);
			check("add_last empty nb", list->nb, 10);
			add_last(&list, new_node(20));
			check("add_last 2nd size", stack_size(list), 2);
			check("add_last 2nd order", list->next->nb, 20);
			free_nodes(&list);
		}
		{
			t_node	*list;

			list = NULL;
			add_last(&list, new_node(10));
			add_first(&list, new_node(5));
			check("add_first changes head", list->nb, 5);
			check("add_first tail nb", list->prev->nb, 10);
			free_nodes(&list);
		}
		{
			int		arr[] = {3, 1, 2};
			t_node	*list;

			list = fill_stack(arr, 3);
			check("fill_stack non-NULL", (long)list != 0, 1);
			check("fill_stack size", stack_size(list), 3);
			check("fill_stack head nb", list->nb, 3);
			free_nodes(&list);
		}
	}
	if (s.ft_indexator_suite || s.test_all)
	{
		printf(YELLOW "\n--- ft_indexator ---\n" RESET);
		{
			int		arr[] = {1, 2, 3};
			t_node	*list;

			list = fill_stack(arr, 3);
			indexator(list);
			check("indexator [1,2,3] head", list->index, 0);
			check("indexator [1,2,3] mid", list->next->index, 1);
			check("indexator [1,2,3] tail", list->next->next->index, 2);
			free_nodes(&list);
		}
		{
			int		arr[] = {3, 2, 1};
			t_node	*list;

			list = fill_stack(arr, 3);
			indexator(list);
			check("indexator [3,2,1] head", list->index, 2);
			check("indexator [3,2,1] mid", list->next->index, 1);
			check("indexator [3,2,1] tail", list->next->next->index, 0);
			free_nodes(&list);
		}
		{
			int		arr[] = {2, 0, 1};
			t_node	*list;

			list = fill_stack(arr, 3);
			indexator(list);
			check("indexator [2,0,1] head", list->index, 2);
			check("indexator [2,0,1] mid", list->next->index, 0);
			check("indexator [2,0,1] tail", list->next->next->index, 1);
			free_nodes(&list);
		}
	}
	print_summary();
	return (g_fails != 0);
}
