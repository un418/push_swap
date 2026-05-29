typedef struct s_node
{
    int nb;

    struct s_node *next;
    struct s_node *prev;

} t_node;

void    swap(t_node **stack)
{
    t_node *first;
    t_node *second;
    t_node *last;

    if (!(*stack) || (*stack)->next == stack)
        return;
    first = stack;
    second = (*stack)->next;
    last = (*stack)->prev;
    
    
    second->prev = (*stack)->prev;
    second->next->prev = first;
    first->next = second->next;
    second->next = first;
    first->prev = second;
    last->next = second;

    (*stack) = second;

    write (1, "ra\n", 2);
    write (1, "rb\n", 2);
}

void    rotate(t_node **stack)
{
    (*stack) = (*stack)->next;
}

void    reverse_rotate(t_node **stack)
{
    (*stack) = (*stack)->prev;
}