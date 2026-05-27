/* ************************************************************************** */
/*                                                                            */
/*   unit_test.c                                                              */
/*                                                                            */
/*   Harnais de tests unitaires pour push_swap.                               */
/*   Build & run :  make unit_test   (code de sortie != 0 si un test echoue)  */
/*                                                                            */
/*   Fichier de test : non soumis a la norme 42 (concatenation de litteraux). */
/* ************************************************************************** */

#include "push_swap.h"

/* Standard Colors */
#define RED     "\033[0;31m"
#define GREEN   "\033[0;32m"
#define YELLOW  "\033[0;33m"
#define RESET   "\033[0m"

static int	g_tests;
static int	g_fails;

/*
** check : compare `got` a `expected`, affiche une ligne PASS/FAIL etiquetee,
** met a jour les compteurs et retourne 1 en cas d'echec.
** Les parametres sont des `long` -> couvre int / char et le `long` renvoye par
** ft_atol, sans troncature.
*/
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

int	main(void)
{
	check("placeholder", ft_atol("2"), 2);

	print_summary();
	return (g_fails != 0);
}
