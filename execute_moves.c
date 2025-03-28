/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_moves.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schahir <schahir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 23:13:10 by schahir           #+#    #+#             */
/*   Updated: 2025/03/13 16:48:10 by schahir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

static void	rotate_both(t_stack **a, t_stack **b, t_stack *cheapest)
{
	while (cheapest->cost_a > 0 && cheapest->cost_b > 0)
	{
		rr(a, b, 1);
		cheapest->cost_a--;
		cheapest->cost_b--;
	}
	while (cheapest->cost_a < 0 && cheapest->cost_b < 0)
	{
		rrr(a, b, 1);
		cheapest->cost_a++;
		cheapest->cost_b++;
	}
}

static void	rotate_a(t_stack **a, int cost)
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

static void	rotate_b(t_stack **b, int cost)
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
		total_cost = ft_abs(tmp->cost_a) + ft_abs(tmp->cost_b);
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
	pa(a, b, 1);
}
