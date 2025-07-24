/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandriaf <mandriaf@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 13:49:22 by mandriaf          #+#    #+#             */
/*   Updated: 2025/07/24 21:39:15 by mandriaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static void	print_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}
//
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
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	*op;
	t_stack	*tmp;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
		print_error();
	if (!check_args(argc, argv))
		print_error();
	stack_a = init_stack(argc, argv);
	if (check_double(&stack_a))
	{
		free_stack(&stack_a);
		print_error();
	}
	while ((op = get_next_line(0)))
	{
		if (!ft_strcmp(op, "sa\n"))
			swap_a(&stack_a);
		else if (!ft_strcmp(op, "sb\n"))
			swap_b(&stack_b);
		else if (!ft_strcmp(op, "ss\n"))
			swap_a_and_b(&stack_a, &stack_b);
		else if (!ft_strcmp(op, "pb\n"))
			push_b(&stack_a, &stack_b);
		else if (!ft_strcmp(op, "pa\n"))
			push_a(&stack_a, &stack_b);
		else if (!ft_strcmp(op, "ra\n"))
			rotate_a(&stack_a);
		else if (!ft_strcmp(op, "rb\n"))
			rotate_b(&stack_b);
		else if (!ft_strcmp(op, "rr\n"))
			rotate_a_and_b(&stack_a, &stack_b);
		else if (!ft_strcmp(op, "rra\n"))
			reverse_rotate_a(&stack_a);
		else if (!ft_strcmp(op, "rrb\n"))
			reverse_rotate_b(&stack_b);
		else if (!ft_strcmp(op, "rrr\n"))
			reverse_rotate_a_and_b(&stack_a, &stack_b);
		else
		{
			free(op);
			free_stack(&stack_a);
			free_stack(&stack_b);
			print_error();
		}
		free(op);
	}
	tmp = stack_a;
	while (tmp)
	{
		printf("%d->", tmp->data);
		tmp = tmp->next;
	}
	t_stack	*tmp2 = stack_b;
	tmp2 = stack_b;
	while (tmp2)
	{
		printf("%d->", tmp2->data);
		tmp2 = tmp2->next;
	}
	if (is_sorted(stack_a))
		write (1, "OK\n", 3);
	else
		write (1, "KO\n", 3);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
