/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_cost_push_a.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandriaf <mandriaf@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 10:59:15 by mandriaf          #+#    #+#             */
/*   Updated: 2025/06/30 11:57:06 by mandriaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*best_value_push_a(t_stack *b)
{
	int		cost;
	int		current;
	t_stack	*best;

	current = absolute_value(b->cost_a) + absolute_value(b->cost_b);
	best = b;
	b = b->next;
	while (b)
	{
		cost = absolute_value(b->cost_a) + absolute_value(b->cost_b);
		if (cost < current)
		{
			best = b;
			current = cost;
		}
		b = b->next;
	}
	return (best);
}

void	push_a_with_cost(t_stack **a, t_stack **b)
{
	int		cost_a;
	int		cost_b;
	t_stack	*best;

	best = best_value_push_a(*b);
	cost_a = best->cost_a;
	cost_b = best->cost_b;
	double_move(a, b, &cost_a, &cost_b);
	move_a_and_b(a, b, &cost_a, &cost_b);
}
