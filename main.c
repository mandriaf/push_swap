#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// t_stack	*sort_list(t_stack *lst, int (*cmp)(int, int));
// static int	ft_strlen(const char *s)
// {
// 	int	i;

// 	if (!s)
// 		return (0);
// 	i = 0;
// 	while (s[i])
// 		i++;
// 	return (i);
// }

// static int	ft_strcmp(const char *s1, const char *s2)
// {
// 	if (!s1 || !s2)
// 		return (-1);
// 	while (*s1 || *s2)
// 	{
// 		if (*s1 != *s2)
// 			return (*s1 - *s2);
// 		s1++;
// 		s2++;
// 	}
// 	return (0);
// }

// static int	comparaison(int a, int b)
// {
// 	return (a <= b);
// }

int	main(int argc, char **argv)
{
	int		i;
	t_stack	*stack_a;
	t_stack	*stack_b;

	i = 1;
	stack_a = NULL;
	stack_b = NULL;
	check_argument(argc, argv); //mila verifier-na kely
	while (i < argc)
	{
		lstadd_back(&stack_a, new_stack(ft_atoi(argv[i])));
		i++;
	}
	int	*tab = create_tab(&stack_a);
	sort_tab(tab, &stack_a);
	assign_index(tab, &stack_a);
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
	// free_stack(&stack_a);
	// free_stack(&stack_b);
	return (0);
}
