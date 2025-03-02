/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_calculation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schahir <schahir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 23:13:06 by schahir           #+#    #+#             */
/*   Updated: 2025/03/01 23:13:07 by schahir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

void	assign_index(t_stack *stack)
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

void	calculate_cost(t_stack *a, t_stack *b)
{
	int		size_a;
	int		size_b;
	t_stack	*tmp;

	size_a = stack_size(a);
	size_b = stack_size(b);
	tmp = b;
	while (tmp)
	{
		tmp->target_pos = find_target_pos(a, tmp->value);
		tmp->cost_a = tmp->target_pos;
		if (tmp->target_pos > size_a / 2)
			tmp->cost_a = tmp->target_pos - size_a;
		tmp->cost_b = tmp->pos;
		if (tmp->pos > size_b / 2)
			tmp->cost_b = tmp->pos - size_b;
		tmp = tmp->next;
	}
}

int	find_min_val_pos(t_stack *a)
{
	int		pos;
	int		min_pos;
	int		min_val;
	t_stack	*tmp;

	tmp = a;
	pos = 0;
	min_pos = 0;
	min_val = INT_MAX;
	while (tmp)
	{
		if (tmp->value < min_val)
		{
			min_val = tmp->value;
			min_pos = pos;
		}
		pos++;
		tmp = tmp->next;
	}
	return (min_pos);
}

int	find_target_pos(t_stack *a, int b_val)
{
	int		pos;
	int		target_pos;
	int		target_val;
	t_stack	*tmp;

	tmp = a;
	pos = 0;
	target_val = INT_MAX;
	while (tmp)
	{
		if (tmp->value > b_val && tmp->value < target_val)
		{
			target_val = tmp->value;
			target_pos = pos;
		}
		pos++;
		tmp = tmp->next;
	}
	if (target_val != INT_MAX)
		return (target_pos);
	return (find_min_val_pos(a));
}

void	update_positions(t_stack *stack)
{
	int	pos;

	pos = 0;
	while (stack)
	{
		stack->pos = pos++;
		stack = stack->next;
	}
}
