#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int	main(int argc, char **argv)
{
	int		i;
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	**tmp;

	i = 1;
	stack_a = NULL;
	stack_b = NULL;
	check_argument(argc, argv); //mila verifier-na kely
	while (i < argc)
	{
		if (ft_atoi(argv[i]) < INT_MIN || ft_atoi(argv[i]) > INT_MAX)
		{
			write (2, "Error\n", 7);
			exit (1);
		}
		lstadd_back(&stack_a, new_stack(ft_atoi(argv[i])));
		i++;
	}
	int	*tab = create_tab(&stack_a);
	// sort_tab(tab, &stack_a);
	// assign_index(tab, &stack_a);
	// t_stack *t = stack_a;
	// while (t)
	// {
	// 	printf("index %d\tvalue %d\n", t->index, t->data);
	// 	t = t->next;
	// }
	if (stack_size(&stack_a) == 2)
	{
		if (stack_a->data > stack_a->next->data)
			swap_a(&stack_a);
	}
	else
		small_sort(&stack_a, &stack_b);
	// print_list(&stack_a);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
