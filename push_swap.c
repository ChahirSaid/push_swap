/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schahir <schahir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 23:58:53 by schahir           #+#    #+#             */
/*   Updated: 2025/03/02 00:43:19 by schahir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

void	handle_error(t_stack **stack)
{
	ft_putstr_fd("Error\n", 2);
	stack_clear(stack);
	exit(1);
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (ac < 2)
		return (0);
	a = parse_input(ac, av);
	if (!a || has_duplicates(a))
		handle_error(&a);
	if (is_sorted(a))
	{
		stack_clear(&a);
		exit(0);
	}
	if (stack_size(a) == 2)
		sa(&a, 1);
	else if (stack_size(a) == 3)
		sort_three(&a);
	else
		sort_large(&a, &b);
	stack_clear(&a);
	return (0);
}
