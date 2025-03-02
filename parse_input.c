/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schahir <schahir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 23:13:14 by schahir           #+#    #+#             */
/*   Updated: 2025/03/02 02:44:15 by schahir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

static void	free_tokens(char **tokens)
{
	int	i;

	i = 0;
	while (tokens[i])
	{
		free(tokens[i]);
		i++;
	}
	free(tokens);
}

int	is_valid_number(char *str)
{
	long	value;

	int (i), (sign);
	(1) && (i = 0, value = 0, sign = 1);
	if (!str || !*str)
		return (0);
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	if (!str[i])
		return (0);
	while (str[i] >= '0' && str[i] <= '9')
	{
		value = value * 10 + (str[i] - '0');
		i++;
		if ((sign == 1 && value > INT_MAX) || (sign == -1
				&& value > (long)INT_MAX + 1))
			return (0);
	}
	if (str[i] != '\0')
		return (0);
	return (1);
}

t_stack	*add_numbers_to_stack(char **tokens, t_stack *a)
{
	int		j;
	long	num;

	j = 0;
	while (tokens[j])
	{
		if (!is_valid_number(tokens[j]))
			return (free_tokens(tokens), NULL);
		num = ft_atoi(tokens[j]);
		if(num == LONG_MAX)
			return (NULL);
		stack_add_back(&a, stack_new((int)num));
		j++;
	}
	return (a);
}

t_stack	*parse_input(int ac, char **av)
{
	t_stack	*a;
	int		i;
	char	**tokens;

	a = NULL;
	i = 1;
	while (i < ac)
	{
		if (av[i][0] == '\0')
			return (NULL);
		tokens = ft_split(av[i], ' ');
		if (!tokens)
			return (NULL);
		if (tokens[0] == NULL)
		{
			free_tokens(tokens);
			return (NULL);
		}
		a = add_numbers_to_stack(tokens, a);
		if (!a)
			return (NULL);
		free_tokens(tokens);
		i++;
	}
	return (a);
}

int	has_duplicates(t_stack *stack)
{
	t_stack	*tmp;

	while (stack)
	{
		tmp = stack->next;
		while (tmp)
		{
			if (stack->value == tmp->value)
				return (1);
			tmp = tmp->next;
		}
		stack = stack->next;
	}
	return (0);
}
