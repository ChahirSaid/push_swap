#include "push_swap.h"

void	sort_large(t_stack **a, t_stack **b)
{
	int	size;
	int	largest_three;

	assign_index(*a);
	size = stack_size(*a);
	largest_three = size - 3;
	while (stack_size(*a) > 3)
	{
		if ((*a)->index < largest_three)
			pb(a, b);
		else
			ra(a, 1);
	}
	sort_three(a);
	while (*b)
	{
		assign_index(*a);
		assign_index(*b);
		update_positions(*a);
		update_positions(*b);
		calculate_cost(*a, *b);
		execute_cheapest_move(a, b);
	}
	final_rotation(a);
}

void	final_rotation(t_stack **a)
{
	int min_pos = 0;
	int min_val = INT_MAX;
	t_stack *tmp = *a;
	int i = 0;

	while (tmp)
	{
		if (tmp->value < min_val)
		{
			min_val = tmp->value;
			min_pos = i;
		}
		tmp = tmp->next;
		i++;
	}
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
