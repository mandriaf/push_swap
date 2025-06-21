/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_cost.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandriaf <mandriaf@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 16:04:28 by mandriaf          #+#    #+#             */
/*   Updated: 2025/06/21 17:58:47 by mandriaf         ###   ########.fr       */
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
	int		target;
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

int	best_value_push_b(t_stack *stack)
{
	int	cost;
	int	current;
	int	best;

	current = absolute_value(stack->cost_a) + absolute_value(stack->cost_b);
	best = stack->data;
	while (stack)
	{
		cost = absolute_value(stack->cost_a) + absolute_value(stack->cost_b);
		if (cost < current)
		{
			best = stack->data;
			current = cost;
		}
		stack = stack->next;
	}
	return (best);
}
