#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


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

static t_stack	*new_stack(int data)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->data = data;
	new->next = NULL;
	return (new);
}

int	main(int argc, char **argv)
{
	int i;
	i = 1;
	t_stack *stack_a = NULL;
	t_stack	*stack_b = NULL;
	stack_b = new_stack(15);
	check_argument(argc, argv);
	while (i < argc)
	{
		lstadd_back(&stack_a, new_stack(ft_atoi(argv[i])));
		i++;
	}
	printf("Avant push:\n");
	print_list(&stack_a);
	print_list(&stack_b);
	// if (argc == 4)
	// 	sort_three(&stack_a);
	push_a(&stack_a, &stack_b);
	printf("Stack A:\n");
	print_list(&stack_a);
	printf("Stack B:\n");
	print_list(&stack_b);
	return (0);
}
