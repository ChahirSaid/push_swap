/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schahir <schahir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 23:12:48 by schahir           #+#    #+#             */
/*   Updated: 2025/03/02 17:26:26 by schahir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rra(t_stack **a, int print)
{
	t_stack	*current;
	t_stack	*prev;

	current = *a;
	prev = NULL;
	if (!*a || !(*a)->next)
		return ;
	while (current->next)
	{
		prev = current;
		current = current->next;
	}
	prev->next = NULL;
	current->next = *a;
	*a = current;
	if (print)
		write(1, "rra\n", 4);
}

void	rrb(t_stack **b, int print)
{
	t_stack	*current;
	t_stack	*prev;

	if (!*b || !(*b)->next)
		return ;
	current = *b;
	prev = NULL;
	while (current->next)
	{
		prev = current;
		current = current->next;
	}
	prev->next = NULL;
	current->next = *b;
	*b = current;
	if (print)
		write(1, "rrb\n", 4);
}

void	rrr(t_stack **a, t_stack **b, int print)
{
	rra(a, 0);
	rrb(b, 0);
	if (print)
		write(1, "rrr\n", 4);
}
