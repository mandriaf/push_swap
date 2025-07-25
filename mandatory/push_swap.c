/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandriaf <mandriaf@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 13:49:22 by mandriaf          #+#    #+#             */
/*   Updated: 2025/07/25 10:47:38 by mandriaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	print_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

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
			return (0);
		i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
		return (0);
	if (!check_args(argc, argv))
		print_error();
	stack_a = init_stack(argc, argv);
	if (check_double(&stack_a))
	{
		free_stack(&stack_a);
		print_error();
	}
	sort(&stack_a, &stack_b);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
