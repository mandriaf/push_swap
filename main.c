#include "push_swap.h"
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char **argv)
{
	int		i;
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	**tmp;

	i = 1;
	stack_a = NULL;
	stack_b = NULL;
	check_argument(argc, argv);
	while (i < argc)
	{
		if (ft_atoi(argv[i]) < INT_MIN || ft_atoi(argv[i]) > INT_MAX)
		{
			write(2, "Error\n", 6);
			exit(1);
		}
		lstadd_back(&stack_a, new_stack(ft_atoi(argv[i])));
		i++;
	}
	if (check_double(&stack_a))
	{
		write(2, "Error\n", 6);
		free_stack(&stack_a);
		exit (1);
	}
	sort(&stack_a, &stack_b);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
