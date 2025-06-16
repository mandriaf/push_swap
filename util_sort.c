/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandriaf <mandriaf@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 20:33:35 by mandriaf          #+#    #+#             */
/*   Updated: 2025/06/16 21:34:54 by mandriaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_min(t_stack *stack)
{
	int	min;

	if (!stack)
		return (-1);
	min = stack->data;
	while (stack)
	{
		if (min > stack->data)
			min = stack->data;
		stack = stack->next;
	}
	return (min);
}

int	find_max(t_stack *stack)
{
	int	max;

	if (!stack)
		return (-1);
	max = stack->data;
	while (stack)
	{
		if (max < stack->data)
			max = stack->data;
		stack = stack->next;
	}
	return (max);
}

int	find_pos(t_stack **a, int min)
{
	int		i;
	t_stack	*tmp;

	i = 0;
	tmp = *a;
	while (tmp)
	{
		if (tmp->data == min)
			return (i);
		tmp = tmp->next;
		i++;
	}
	return (-1);
}

void	min_to_top(t_stack **a, int min)
{
	int	pos;
	int	size;

	size = stack_size(a);
	pos = find_pos(a, min);
	if (pos <= size / 2)
	{
		while (pos > 0)
		{
			rotate_a(a);
			pos--;
		}
	}
	else
	{
		while (pos < size)
		{
			reverse_rotate_a(a);
			pos++;
		}
	}
}
