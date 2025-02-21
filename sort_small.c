#include "push_swap.h"

void	sort_three(t_stack **a)
{
	int top = (*a)->value;
	int mid = (*a)->next->value;
	int bot = (*a)->next->next->value;

	if (top > mid && mid < bot && top < bot)
		sa(a, 1);
	else if (top > mid && mid > bot)
	{
		sa(a, 1);
		rra(a, 1);
	}
	else if (top > mid && mid < bot)
		ra(a, 1);
	else if (top < mid && mid > bot && top < bot)
	{
		sa(a, 1);
		ra(a, 1);
	}
	else if (top < mid && mid > bot)
		rra(a, 1);
}
