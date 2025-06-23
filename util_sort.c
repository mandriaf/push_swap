/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandriaf <mandriaf@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 20:33:35 by mandriaf          #+#    #+#             */
/*   Updated: 2025/06/23 10:54:01 by mandriaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	target_b_to_top(t_stack **b, int target)
{
	int	pos;
	int	size;

	size = stack_size(b);
	pos = find_pos_target(b, target);
	if (pos <= size / 2)
	{
		while (pos-- > 0)
			rotate_b(b);
	}
	else
	{
		while (pos++ < size)
			reverse_rotate_b(b);
	}
}

void	target_a_to_top(t_stack **a, int target)
{
	int	pos;
	int	size;

	size = stack_size(a);
	pos = find_pos_target(a, target);
	if (pos <= size / 2)
	{
		while (pos-- > 0)
			rotate_a(a);
	}
	else
	{
		while (pos++ < size)
			reverse_rotate_a(a);
	}
}

t_stack	*find_node(t_stack *stack, int target)
{
	while (stack)
	{
		if (stack->data == target)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}
