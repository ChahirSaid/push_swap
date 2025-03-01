#include "includes/push_swap.h"

void	rotate_both(t_stack **a, t_stack **b, t_stack *cheapest)
{
	while (cheapest->cost_a > 0 && cheapest->cost_b > 0)
	{
		rr(a, b);
		cheapest->cost_a--;
		cheapest->cost_b--;
	}
	while (cheapest->cost_a < 0 && cheapest->cost_b < 0)
	{
		rrr(a, b);
		cheapest->cost_a++;
		cheapest->cost_b++;
	}
}

void	rotate_a(t_stack **a, int cost)
{
	while (cost > 0)
	{
		ra(a, 1);
		cost--;
	}
	while (cost < 0)
	{
		rra(a, 1);
		cost++;
	}
}

void	rotate_b(t_stack **b, int cost)
{
	while (cost > 0)
	{
		rb(b, 1);
		cost--;
	}
	while (cost < 0)
	{
		rrb(b, 1);
		cost++;
	}
}
void	execute_cheapest_move(t_stack **a, t_stack **b)
{
	t_stack	*tmp;
	t_stack	*cheapest;
	int		min_cost;
	int		total_cost;

	tmp = *b;
	cheapest = tmp;
	min_cost = INT_MAX;
	while (tmp)
	{
		total_cost = abs(tmp->cost_a) + abs(tmp->cost_b);
		if (total_cost < min_cost)
		{
			min_cost = total_cost;
			cheapest = tmp;
		}
		tmp = tmp->next;
	}
	rotate_both(a, b, cheapest);
	rotate_a(a, cheapest->cost_a);
	rotate_b(b, cheapest->cost_b);
	pa(a, b);
}
