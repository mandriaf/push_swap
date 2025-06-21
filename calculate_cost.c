/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_cost.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandriaf <mandriaf@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 16:04:28 by mandriaf          #+#    #+#             */
/*   Updated: 2025/06/21 17:35:21 by mandriaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	absolute_value(int value)
{
	if (value < 0)
		return (-value);
	return (value);
}

static int	get_cost(t_stack *stack, int target)
{
	int	size;
	int	pos;

	size = stack_size(&stack);
	pos = find_pos_target(&stack, target);
	if (pos <= size / 2)
		return (pos);
	return (pos - size);
}

void	calculate_move_top(t_stack *a, t_stack *b)
{
	int	target;
	t_stack	*tmp;

	tmp = a;
	while (tmp)
	{
		target = choice_target_to_b(tmp, b);
		tmp->cost_a = get_cost(a, tmp->data);
		tmp->cost_b = get_cost(b, target);
		tmp = tmp->next;
	}
}

int	best_value_push_b(t_stack *a, t_stack *b)
{
	int	cost;
	int	current;
	int	best;

	calculate_move_top(a, b);
	current = absolute_value(a->cost_a) + absolute_value(a->cost_b);
	best = a->data;
	while (a)
	{
		cost = absolute_value(a->cost_a) + absolute_value(a->cost_b);
		if (cost < current)
		{
			best = a->data;
			current = cost;
		}
		a = a->next;
	}
	return (best);
}
