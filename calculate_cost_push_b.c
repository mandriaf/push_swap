/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_cost_push_b.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandriaf <mandriaf@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 16:04:28 by mandriaf          #+#    #+#             */
/*   Updated: 2025/06/30 11:41:09 by mandriaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*best_value_push_b(t_stack *a)
{
	int		cost;
	int		current;
	t_stack	*best;

	// if ((a->cost_a >= 0 && a->cost_b >= 0) || (a->cost_a < 0 && a->cost_b < 0))
	// {
	// 	if (a->cost_a > a->cost_b)
	// 		current = absolute_value(a->cost_a);
	// 	else
	// 		current = absolute_value(a->cost_b);
	// }
	// else
		current = absolute_value(a->cost_a) + absolute_value(a->cost_b);
	best = a;
	a = a->next;
	while (a)
	{
		// if ((a->cost_a >= 0 && a->cost_b >= 0) || (a->cost_a < 0
		// 		&& a->cost_b < 0))
		// {
		// 	if (a->cost_a > a->cost_b)
		// 		cost = absolute_value(a->cost_a);
		// 	else
		// 		cost = absolute_value(a->cost_b);
		// }
		// else
			cost = absolute_value(a->cost_a) + absolute_value(a->cost_b);
		if (cost < current)
		{
			best = a;
			current = cost;
		}
		a = a->next;
	}
	return (best);
}

void	push_b_with_cost(t_stack **a, t_stack **b)
{
	int		cost_a;
	int		cost_b;
	t_stack	*best;

	best = best_value_push_b(*a);
	cost_a = best->cost_a;
	cost_b = best->cost_b;
	double_move(a, b, &cost_a, &cost_b);
	move_a_and_b(a, b, &cost_a, &cost_b);
}
