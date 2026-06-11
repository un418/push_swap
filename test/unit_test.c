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
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/wait.h>

// colors
#define RED     "\033[0;31m"
#define GREEN   "\033[0;32m"
#define YELLOW  "\033[0;33m"
#define RESET   "\033[0m"

static int	g_tests;
static int	g_fails;
static int	g_saved_fd = -1;

typedef struct s_suite
{
	int test_all;
	int ft_atol; int in_int_limits; int is_valid_num_fmt; int parse_number;
	int parse_flag_suite;
	int stack_size_suite; int list_creation; int ft_indexator_suite;
	int init_ctx_suite; int swap_suite; int push_suite; int rotate_suite;
	int reverse_suite; int disorder_suite; int counters_suite;
}	t_suite;

// the ops write their name to stdout; mute it so test output stays clean
void	mute_stdout(void)
{
	int	devnull;

	fflush(stdout);
	g_saved_fd = dup(1);
	devnull = open("/dev/null", O_WRONLY);
	dup2(devnull, 1);
	close(devnull);
}

void	restore_stdout(void)
{
	fflush(stdout);
	dup2(g_saved_fd, 1);
	close(g_saved_fd);
	g_saved_fd = -1;
}

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
		else if (is_str_eq(argv[i], "--init_ctx"))
			s.init_ctx_suite = 1;
		else if (is_str_eq(argv[i], "--swap"))
			s.swap_suite = 1;
		else if (is_str_eq(argv[i], "--push"))
			s.push_suite = 1;
		else if (is_str_eq(argv[i], "--rotate"))
			s.rotate_suite = 1;
		else if (is_str_eq(argv[i], "--reverse"))
			s.reverse_suite = 1;
		else if (is_str_eq(argv[i], "--disorder"))
			s.disorder_suite = 1;
		else if (is_str_eq(argv[i], "--counters"))
			s.counters_suite = 1;
		else if (is_str_eq(argv[i], "--parse_flag"))
			s.parse_flag_suite = 1;
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
	if (s.init_ctx_suite || s.test_all)
	{
		printf(YELLOW "\n--- init_ctx ---\n" RESET);
		{
			t_ctx	ctx;

			init_ctx(&ctx);
			check("init_ctx mode", ctx.mode, 0);
			check("init_ctx bench", ctx.bench, 0);
			check("init_ctx parsed NULL", (long)ctx.parsed, 0);
			check("init_ctx parsed_size", (long)ctx.parsed_size, 0);
			check("init_ctx disorder", (long)ctx.disorder, 0);
			check("init_ctx stats.total", ctx.stats.total, 0);
			check("init_ctx stats.sa", ctx.stats.sa, 0);
			check("init_ctx stats.pb", ctx.stats.pb, 0);
			check("init_ctx stats.rrr", ctx.stats.rrr, 0);
		}
	}
	if (s.swap_suite || s.test_all)
	{
		printf(YELLOW "\n--- swap ---\n" RESET);
		{
			int		arr[] = {1, 2, 3};
			t_node	*list;

			list = fill_stack(arr, 3);
			swap_me(&list);
			check("swap_me head", list->nb, 2);
			check("swap_me 2nd", list->next->nb, 1);
			check("swap_me 3rd", list->next->next->nb, 3);
			check("swap_me tail (circular)", list->prev->nb, 3);
			check("swap_me size", stack_size(list), 3);
			free_nodes(&list);
		}
		{
			t_node	*list;

			list = NULL;
			add_last(&list, new_node(7));
			swap_me(&list);
			check("swap_me single no-op nb", list->nb, 7);
			check("swap_me single no-op size", stack_size(list), 1);
			free_nodes(&list);
		}
		{
			int		arr[] = {1, 2};
			t_node	*list;

			list = fill_stack(arr, 2);
			swap_me(&list);
			check("swap_me 2 elements head", list->nb, 2);
			check("swap_me 2 elements 2nd", list->next->nb, 1);
			check("swap_me 2 elements intact (regression #60)",
				list->next->prev == list && list->prev->next == list, 1);
			free_nodes(&list);
		}
	}
	if (s.push_suite || s.test_all)
	{
		printf(YELLOW "\n--- push ---\n" RESET);
		{
			int		src_arr[] = {1, 2, 3};
			int		dst_arr[] = {10, 20};
			t_node	*src;
			t_node	*dst;

			src = fill_stack(src_arr, 3);
			dst = fill_stack(dst_arr, 2);
			push_me(&src, &dst);
			check("push_me src head", src->nb, 2);
			check("push_me src size", stack_size(src), 2);
			check("push_me dst head", dst->nb, 1);
			check("push_me dst 2nd", dst->next->nb, 10);
			check("push_me dst size", stack_size(dst), 3);
			free_nodes(&src);
			free_nodes(&dst);
		}
		{
			int		src_arr[] = {5, 6};
			t_node	*src;
			t_node	*dst;

			src = fill_stack(src_arr, 2);
			dst = NULL;
			push_me(&src, &dst);
			check("push_me empty dst head", dst->nb, 5);
			check("push_me empty dst size", stack_size(dst), 1);
			check("push_me empty src size", stack_size(src), 1);
			free_nodes(&src);
			free_nodes(&dst);
		}
	}
	if (s.rotate_suite || s.test_all)
	{
		printf(YELLOW "\n--- rotate ---\n" RESET);
		{
			int		arr[] = {1, 2, 3};
			t_node	*list;

			list = fill_stack(arr, 3);
			rotate_me(&list);
			check("rotate_me head", list->nb, 2);
			check("rotate_me 2nd", list->next->nb, 3);
			check("rotate_me 3rd", list->next->next->nb, 1);
			check("rotate_me size", stack_size(list), 3);
			free_nodes(&list);
		}
		{
			t_node	*list;

			list = NULL;
			rotate_me(&list);
			check("rotate_me NULL no crash", (long)list, 0);
		}
	}
	if (s.reverse_suite || s.test_all)
	{
		printf(YELLOW "\n--- reverse ---\n" RESET);
		{
			int		arr[] = {1, 2, 3};
			t_node	*list;

			list = fill_stack(arr, 3);
			reverse_me(&list);
			check("reverse_me head", list->nb, 3);
			check("reverse_me 2nd", list->next->nb, 1);
			check("reverse_me 3rd", list->next->next->nb, 2);
			check("reverse_me size", stack_size(list), 3);
			free_nodes(&list);
		}
		{
			int		arr[] = {1, 2, 3};
			t_node	*list;

			list = fill_stack(arr, 3);
			rotate_me(&list);
			reverse_me(&list);
			check("reverse_me undoes rotate", list->nb, 1);
			free_nodes(&list);
		}
	}
	if (s.disorder_suite || s.test_all)
	{
		printf(YELLOW "\n--- disorder ---\n" RESET);
		{
			int		arr[] = {1, 2, 3};
			t_node	*list;

			list = fill_stack(arr, 3);
			check("disorder sorted = 0", (long)(disorder(list) * 1000), 0);
			free_nodes(&list);
		}
		{
			int		arr[] = {3, 2, 1};
			t_node	*list;

			list = fill_stack(arr, 3);
			check("disorder reversed = 1", (long)(disorder(list) * 1000), 1000);
			free_nodes(&list);
		}
		{
			int		arr[] = {2, 1, 3};
			t_node	*list;

			list = fill_stack(arr, 3);
			check("disorder 1 inversion = 1/3", (long)(disorder(list) * 1000), 333);
			free_nodes(&list);
		}
	}
	if (s.counters_suite || s.test_all)
	{
		printf(YELLOW "\n--- counters ---\n" RESET);
		{
			int		a_arr[] = {1, 2, 3};
			int		b_arr[] = {7, 8, 9};
			t_node	*a;
			t_node	*b;
			t_node	*empty;
			t_ctx	ctx;

			a = fill_stack(a_arr, 3);
			b = fill_stack(b_arr, 3);
			empty = NULL;
			init_ctx(&ctx);
			mute_stdout();
			swap_a(&a, &ctx);
			swap_b(&a, &ctx);
			swap_all(&a, &empty, &ctx);
			rotate_a(&a, &ctx);
			rotate_b(&a, &ctx);
			rotate_all(&a, &empty, &ctx);
			reverse_a(&a, &ctx);
			reverse_b(&a, &ctx);
			reverse_all(&a, &empty, &ctx);
			push_b(&a, &b, &ctx);
			push_a(&a, &b, &ctx);
			restore_stdout();
			check("counters sa", ctx.stats.sa, 1);
			check("counters sb", ctx.stats.sb, 1);
			check("counters ss", ctx.stats.ss, 1);
			check("counters ra", ctx.stats.ra, 1);
			check("counters rb", ctx.stats.rb, 1);
			check("counters rr", ctx.stats.rr, 1);
			check("counters rra", ctx.stats.rra, 1);
			check("counters rrb", ctx.stats.rrb, 1);
			check("counters rrr", ctx.stats.rrr, 1);
			check("counters pa", ctx.stats.pa, 1);
			check("counters pb", ctx.stats.pb, 1);
			check("counters total", ctx.stats.total, 11);
			free_nodes(&a);
			free_nodes(&b);
		}
	}
	if (s.parse_flag_suite || s.test_all)
	{
		printf(YELLOW "\n--- parse_flag ---\n" RESET);
		{
			t_ctx ctx = {0};
			check("bench sets bench=1", parse_flag("--bench", &ctx), 1);
		}
		{
			t_ctx ctx = {0};
			parse_flag("--bench", &ctx);
			check("bench leaves mode=0", ctx.mode, 0);
		}
		{
			t_ctx ctx = {0};
			parse_flag("--bench", &ctx);
			parse_flag("--simple", &ctx);
			check("bench+simple: bench=1", ctx.bench, 1);
			check("bench+simple: mode=2", ctx.mode, 2);
		}
		{
			t_ctx ctx = {0};
			parse_flag("--simple", &ctx);
			parse_flag("--bench", &ctx);
			check("simple+bench: mode=2", ctx.mode, 2);
			check("simple+bench: bench=1", ctx.bench, 1);
		}
		{
			t_ctx ctx = {0};
			check("unknown flag rejected", parse_flag("--unknown", &ctx), 0);
		}
		{
			t_ctx ctx = {0};
			parse_flag("--bench", &ctx);
			check("bench repeated rejected", parse_flag("--bench", &ctx), 0);
		}
		{
			t_ctx ctx = {0};
			parse_flag("--simple", &ctx);
			check("two modes rejected", parse_flag("--complex", &ctx), 0);
		}
	}
	print_summary();
	return (g_fails != 0);
}
