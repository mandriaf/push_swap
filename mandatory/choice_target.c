/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choice_target.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandriaf <mandriaf@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 16:14:46 by mandriaf          #+#    #+#             */
/*   Updated: 2025/06/23 17:38:00 by mandriaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_index_max(int value, t_stack *stack)
{
	while (stack && (stack->data != value))
		stack = stack->next;
	return (stack->index);
}

int	choice_target_to_b(t_stack *a, t_stack *b)
{
	int	diff;
	int	target;

	if (a->data > find_max(b) || a->data < find_min(b))
		return (find_max(b));
	diff = find_index_max(find_max(b), b);
	while (b)
	{
		if ((a->index - b->index < diff) && (a->index - b->index >= 0))
		{
			diff = a->index - b->index;
			target = b->data;
		}
		b = b->next;
	}
	return (target);
}

int	choice_target_to_a(t_stack *a, t_stack *b)
{
	int	diff;
	int	target;

	if (b->data > find_max(a) || b->data < find_min(a))
		return (find_min(a));
	diff = find_index_max(find_max(a), a);
	while (a)
	{
		if ((a->index - b->index < diff) && (a->index - b->index >= 0))
		{
			diff = a->index - b->index;
			target = a->data;
		}
		a = a->next;
	}
	return (target);
}
