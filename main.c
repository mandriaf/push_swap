/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandriaf <mandriaf@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 13:49:22 by mandriaf          #+#    #+#             */
/*   Updated: 2025/06/22 17:21:32 by mandriaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
int	best_value_push_b(t_stack *a);
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

static void	print_stack(t_stack *stack)
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
	int		*tab;

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
	tab = create_tab(&stack_a);
	sort_tab(tab, &stack_a);
	assign_index(tab, &stack_a);
	push_b(&stack_a, &stack_b);
	push_b(&stack_a, &stack_b);
	push_b(&stack_a, &stack_b);
	push_b(&stack_a, &stack_b);
	push_b(&stack_a, &stack_b);
	push_b(&stack_a, &stack_b);
	push_b(&stack_a, &stack_b);
	calculate_move_top(stack_a, stack_b);
	t_stack *tmp = stack_a;

	printf("STACK A:\n");
	print_stack(stack_a);
	printf("STACK B:\n");
	print_stack(stack_b);

	while (tmp)
	{
		printf("data = %d\tcout A = %d\tcout B = %d\n", tmp->data, tmp->cost_a, tmp->cost_b);
		tmp = tmp->next;
	}
	int best = best_value_push_b(stack_a);
	printf("best = %d\n", best);
	sort(&stack_a, &stack_b);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
