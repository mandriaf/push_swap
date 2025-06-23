/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandriaf <mandriaf@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 13:49:22 by mandriaf          #+#    #+#             */
/*   Updated: 2025/06/23 11:58:35 by mandriaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	only_space(const char *s)
{
	if (!s)
		return (-1);
	while (*s)
	{
		if (*s != ' ')
			return (0);
		s++;
	}
	return (1);
}

static int	check_args(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (only_space(argv[i]))
			return (1);
		i++;
	}
	return (0);
}

void	print(t_stack *stack)
{
	while (stack)
	{
		printf("%d -> ", stack->data);
		stack = stack->next;
	}
	printf("NULL\n");
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
		return (0);
	if (check_args(argc, argv))
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	stack_a = init_stack(argc, argv);
	if (check_double(&stack_a))
	{
		write(2, "Error\n", 6);
		free_stack(&stack_a);
		exit(1);
	}
	int *tab = create_tab(&stack_a);
	sort_tab(tab, &stack_a);
	assign_index(tab, &stack_a);
	push_b(&stack_a, &stack_b);	
	push_b(&stack_a, &stack_b);
	push_b(&stack_a, &stack_b);
	push_b(&stack_a, &stack_b);
	print(stack_a);
	print(stack_b);
	calculate_move_push_a(stack_a, stack_b);
	t_stack *tmp = stack_b;
	while (tmp)
	{
		printf("Data : %d\tCout de A %d\tB %d\n", tmp->data, tmp->cost_a, tmp->cost_b);
		tmp = tmp->next;
	}
	// sort(&stack_a, &stack_b);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
