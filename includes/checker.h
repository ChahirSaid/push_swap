#ifndef CHECKER_H
# define CHECKER_H

# include "../libft/includes/libft.h"
# include "../includes/get_next_line.h"
# include "push_swap.h"

int     parse_operations(t_stack **a, t_stack **b);
int     execute_operation(t_stack **a, t_stack **b, char *op);
int     str_equals(char *s1, char *s2);
int     free_and_return(t_stack **a, t_stack **b, char *line);

#endif