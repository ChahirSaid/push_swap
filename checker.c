/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schahir <schahir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 23:13:04 by schahir           #+#    #+#             */
/*   Updated: 2025/03/02 17:24:46 by schahir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/checker.h"

int	free_and_return(t_stack **a, t_stack **b, char *line)
{
	if (line)
		free(line);
	if (a && *a)
		stack_clear(a);
	if (b && *b)
		stack_clear(b);
	return (0);
}

int	execute_operation(t_stack **a, t_stack **b, char *op)
{
	if (!ft_strcmp(op, "sa"))
		sa(a, 0);
	else if (!ft_strcmp(op, "sb"))
		sb(b, 0);
	else if (!ft_strcmp(op, "ss"))
		ss(a, b, 0);
	else if (!ft_strcmp(op, "pa"))
		pa(a, b, 0);
	else if (!ft_strcmp(op, "pb"))
		pb(a, b, 0);
	else if (!ft_strcmp(op, "ra"))
		ra(a, 0);
	else if (!ft_strcmp(op, "rb"))
		rb(b, 0);
	else if (!ft_strcmp(op, "rr"))
		rr(a, b, 0);
	else if (!ft_strcmp(op, "rra"))
		rra(a, 0);
	else if (!ft_strcmp(op, "rrb"))
		rrb(b, 0);
	else if (!ft_strcmp(op, "rrr"))
		rrr(a, b, 0);
	else
		return (0);
	return (1);
}

int	parse_operations(t_stack **a, t_stack **b)
{
	char	*line;
	int		i;

	while (1)
	{
		line = get_next_line(0);
		if (!line)
			break ;
		i = 0;
		while (line[i] && line[i] != '\n')
			i++;
		if (line[i] == '\n')
			line[i] = '\0';
		if (!execute_operation(a, b, line))
		{
			free(line);
			return (0);
		}
		free(line);
	}
	return (1);
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
		return (ft_putstr_fd("Error\n", 2), stack_clear(&a), 1);
	if (!parse_operations(&a, &b))
	{
		ft_putstr_fd("Error\n", 2);
		stack_clear(&a);
		stack_clear(&b);
		return (1);
	}
	if (is_sorted(a) && !b)
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
	stack_clear(&a);
	stack_clear(&b);
	return (0);
}
