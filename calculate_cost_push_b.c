/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_cost_push_b.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandriaf <mandriaf@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 16:04:28 by mandriaf          #+#    #+#             */
/*   Updated: 2025/06/23 10:55:20 by mandriaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	best_value_push_b(t_stack *stack)
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

void	push_b_with_cost(t_stack **a, t_stack **b)
{
	int		best_value;
	int		target_in_b;
	int		cost_a;
	int		cost_b;
	t_stack	*node;

	best_value = best_value_push_b(*a);
	node = find_node(*a, best_value);
	target_in_b = choice_target_to_b(node, *b);
	cost_a = node->cost_a;
	cost_b = get_cost(*b, target_in_b);
	double_move(a, b, &cost_a, &cost_b);
	move_a_and_b(a, b, &cost_a, &cost_b);
}
