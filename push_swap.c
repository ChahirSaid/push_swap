#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (argc < 2)
		return (0);
	a = parse_input(argc, argv);
	if (!a || has_duplicates(a))
	{
		ft_putstr_fd("Error\n", 2);
		stack_clear(&a);
		exit(1);
	}
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
