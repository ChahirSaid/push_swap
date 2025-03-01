#include "push_swap.h"

void	sort_large(t_stack **a, t_stack **b)
{
	int	size;
	int	push_limit;

	assign_index(*a);
	size = stack_size(*a);
	push_limit = size / 2;
	while (stack_size(*a) > 3 && has_elements_below_index(*a, push_limit))
	{
		if ((*a)->index < push_limit)
			pb(a, b);
		else
			ra(a, 1);
	}
	while (stack_size(*a) > 3)
	{
		if ((*a)->index < size - 3)
            pb(a, b);
        else
            ra(a, 1);
	}
	sort_three(a);
	while (*b)
	{
		assign_index(*b);
		update_positions(*a);
		update_positions(*b);
		calculate_cost(*a, *b);
		execute_cheapest_move(a, b);
	}
	final_rotation(a);
}

int	has_elements_below_index(t_stack *stack, int limit)
{
	t_stack	*tmp;

	tmp = stack;
	while (tmp)
	{
		if (tmp->index < limit)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

void final_rotation(t_stack **a)
{
    int min_pos;
    
    min_pos = find_min_val_pos(*a);
    if (min_pos > stack_size(*a) / 2)
        min_pos -= stack_size(*a);
    while (min_pos > 0)
    {
        ra(a, 1);
        min_pos--;
    }
    while (min_pos < 0)
    {
        rra(a, 1);
        min_pos++;
    }
}
