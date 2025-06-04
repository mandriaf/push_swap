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
//12 0 1 -1 10
int	main(int argc, char **argv)
{
	int		i;
	t_stack	*stack_a;
	t_stack	*stack_b;

	i = 1;
	stack_a = NULL;
	stack_b = NULL;
	stack_b = new_stack(15);
	check_argument(argc, argv);
	while (i < argc)
	{
		lstadd_back(&stack_a, new_stack(ft_atoi(argv[i])));
		i++;
	}
	// printf("Avant tri:\n");
	// print_list(&stack_a);
	sort_three(&stack_a);
	// printf("Stack A:\n");
	print_list(&stack_a);
	return (0);
}
