#include "push_swap.h"

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
	int		i;
	long	value;
	int		sign;

	i = 0;
	value = 0;
	sign = 1;
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

t_stack	*parse_input(int argc, char **argv)
{
	t_stack	*a;
	long	num;
	int		i;
	char	**tokens;
	int		j;

	a = NULL;
	i = 1;
	while (i < argc)
	{
		tokens = ft_split(argv[i], ' ');
		if (!tokens)
			return (NULL);
		j = 0;
		while (tokens[j])
		{
			if (tokens[j][0] == '\0')
			{
				j++;
				continue ;
			}
			if (!is_valid_number(tokens[j]))
			{
				free_tokens(tokens);
				return (NULL);
			}
			num = ft_atoi(tokens[j]);
			stack_add_back(&a, stack_new((int)num));
			j++;
		}
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
