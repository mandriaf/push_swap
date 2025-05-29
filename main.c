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

	argument_analysis(argc, argv);
	while (i < argc)
	{
		lstadd_back(&stack_a, new_stack(ft_atoi(argv[i])));
		i++;
	}
	printf("argc == %d\n", argc);
	if (argc == 4)
		sort_three(&stack_a);
	t_stack *aff = stack_a;
	while (aff)
	{
		printf("%d -> ", aff->data);
		aff = aff->next;
	}
	printf("NULL\n");
	return (0);
}
