#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "libft/includes/libft.h"

typedef struct s_stack {
    int             value;
    int             index;
    int             pos;
    int             target_pos;
    int             cost_a;
    int             cost_b;
    struct s_stack  *next;
} t_stack;

t_stack *stack_new(int value);
void    stack_add_back(t_stack **stack, t_stack *new);
t_stack *stack_last(t_stack *stack);
int     stack_size(t_stack *stack);
void    stack_clear(t_stack **stack);
int     is_sorted(t_stack *stack);

t_stack *parse_input(int ac, char **av);
int     is_valid_number(char *str);
int     has_duplicates(t_stack *stack);

void    sort_three(t_stack **a);
void    sort_large(t_stack **a, t_stack **b);
void    assign_index(t_stack *stack);
int     has_elements_below_index(t_stack *stack, int limit);
void    calculate_cost(t_stack *a, t_stack *b);
int     find_target_pos(t_stack *a, int b_val);
void    update_positions(t_stack *stack);
void    execute_cheapest_move(t_stack **a, t_stack **b);
void    final_rotation(t_stack **a);
int     is_valid_number(char *str);

void    sa(t_stack **a, int print);
void    sb(t_stack **b, int print);
void    ss(t_stack **a, t_stack **b);
void    pa(t_stack **a, t_stack **b);
void    pb(t_stack **a, t_stack **b);
void    ra(t_stack **a, int print);
void    rb(t_stack **b, int print);
void    rr(t_stack **a, t_stack **b);
void    rra(t_stack **a, int print);
void    rrb(t_stack **b, int print);
void    rrr(t_stack **a, t_stack **b);



#endif