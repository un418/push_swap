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
				s.in_int_limits = 1;
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
			int *output = parse_number(input);
			check("parse_number valid list size3", output[0], 1);
			check("parse_number valid list size3", output[1], -1);
			check("parse_number valid list size3", output[2], 42);
			// check("parse_number valid list size3", output[3], 0); // should heap buffer overflow because out of range
		}
		{
			const char *input[] = {"1", NULL};
			int *output = parse_number(input);
			check("parse_number valid list size1", output[0], 1);
			// check("parse_number valid list size1", output[1], 0); // should heap buffer overflow because out of range
		}
		{
			const char *input[] = {NULL};
			int *output = parse_number(input);
			check("parse_number empty num list", (long)output, 0);
			// check("parse_number size1", output[1], 0); // should heap buffer overflow because out of range
		}
		{
			const char *input[] = {"a1", "-1", "42", NULL};
			int *output = parse_number(input);
			check("parse_number unvalid at start", (long)output, 0);
			// cast pointer to long to use check()
		}
		{
			const char *input[] = {"1", "-1", "4a2", NULL};
			int *output = parse_number(input);
			check("parse_number unvalid at end", (long)output, 0);
			// cast pointer to long to use check()
		}
	}


	print_summary();
	return (g_fails != 0);
}
