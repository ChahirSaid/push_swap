/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schahir <schahir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 23:13:23 by schahir           #+#    #+#             */
/*   Updated: 2025/03/13 16:46:37 by schahir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

static void	assign_index(t_stack *stack)
{
	t_stack	*ptr;
	t_stack	*tmp;

	ptr = stack;
	while (ptr)
	{
		ptr->index = 0;
		ptr = ptr->next;
	}
	ptr = stack;
	while (ptr)
	{
		tmp = stack;
		while (tmp)
		{
			if (ptr->value > tmp->value)
				ptr->index++;
			tmp = tmp->next;
		}
		ptr = ptr->next;
	}
}

static void	update_positions(t_stack *stack)
{
	int	pos;

	pos = 0;
	while (stack)
	{
		stack->pos = pos++;
		stack = stack->next;
	}
}

void	sort_large(t_stack **a, t_stack **b)
{
	int	size;
	int	median;

	while (stack_size(*a) > 3)
	{
		assign_index(*a);
		size = stack_size(*a);
		median = size / 2;
		if ((*a)->index < median)
			pb(a, b, 1);
		else
			ra(a, 1);
	}
	sort_three(a);
	while (*b)
	{
		update_positions(*a);
		update_positions(*b);
		calculate_cost(*a, *b);
		execute_cheapest_move(a, b);
	}
	final_rotation(a);
}

void	final_rotation(t_stack **a)
{
	int	min_pos;

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
