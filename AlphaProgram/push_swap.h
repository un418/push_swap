#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_node
{
	int				nb;
	int				index;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

// Function linklist Prototypes (list_utils.c & list_creation.c)
void	print_list(t_node *head);
void	print_list_cir(t_node *head);
void	print_list_index(t_node *head);
int		stack_size(t_node *head);
t_node	*new_node(int nb);
t_node	*last_node(t_node *head);
t_node	*add_last(t_node **head, t_node *new);
t_node	*add_first(t_node **head, t_node *new);
void	free_nodes(t_node **head);

// Function utils Prototypes (disorder.c, parser.c, parser_utils.c)
long	ft_atol(const char *str);
float	disorder(t_node *head);
int		is_flag_prefix(const char *str);
int		in_int_limits(const char *str);
int		arg_validate(const char **argv);
int		is_str_eq(const char *s1, const char *s2);
int		parse_flag(const char *flag);
void	ft_indexator(t_node *head);
int		*parse_number(const char **argv);
int		input_validate(const char **argv);
int		is_digit(const char c);
int		is_valid_num_fmt(const char *str);


// Function operations Prototypes (swap.c, rotate.c, reverse.c, push.c)
void	swap_me(t_node **stack);
void	swap_a(t_node **stack);
void	swap_b(t_node **stack);
void	swap_all(t_node **stack_a, t_node **stack_b);

void	rotate_me(t_node **stack);
void	rotate_a(t_node **stack);
void	rotate_b(t_node **stack);
void	rotate_all(t_node **stack_a, t_node **stack_b);

void	reverse_me(t_node **stack);
void	reverse_a(t_node **stack);
void	reverse_b(t_node **stack);
void	reverse_all(t_node **stack_a, t_node **stack_b);

void	push_me(t_node **stack_src, t_node **stack_dest);
void	push_a(t_node **stack_a, t_node **stack_b);
void	push_b(t_node **stack_a, t_node **stack_b);

// Algorithm Prototypes (sort_3.c & sort_5.c)
void	sort_3(t_node **stack_a);
void	sort_5(t_node **stack_a, t_node **stack_b);

#endif