#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int				count_tri_list(t_list *lst, int (*cmp)(int, int));
static int	ft_strlen(const char *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

static int	ft_strcmp(const char *s1, const char *s2)
{
	if (!s1 || !s2)
		return (-1);
	while (*s1 || *s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	return (0);
}

static int	comparaison(int a, int b)
{
	return (a <= b);
}

static t_list	*lstnew(int data)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->data = data;
	new->next = NULL;
	return (new);
}

static void	ft_lstadd_front(t_list **head, t_list *new)
{
	if (!head || !new)
		return ;
	new->next = *head;
	*head = new;
}

int	main(int argc, char **argv)
{
	int i;
	i = 1;
	t_list *stack_a = NULL;

	argument_analysis(argc, argv);
	while (i < argc)
	{
		lstadd_back(&stack_a, lstnew(ft_atoi(argv[i])));
		i++;
	}
	swap_a_and_b(&stack_a, &stack_a);
	t_list *aff = stack_a;
	while (aff)
	{
		printf("%d -> ", aff->data);
		aff = aff->next;
	}
	printf("NULL\n");
	return (0);
}