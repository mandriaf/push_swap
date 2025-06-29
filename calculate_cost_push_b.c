/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_cost_push_b.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandriaf <mandriaf@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 16:04:28 by mandriaf          #+#    #+#             */
/*   Updated: 2025/06/29 21:24:10 by mandriaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	best_value_push_b(t_stack *a)
{
	int	cost;
	int	current;
	int	best;

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

void	push_b_with_cost(t_stack **a, t_stack **b)
{
	int		best_value;
	int		cost_a;
	int		cost_b;
	t_stack	*best;

	best_value = best_value_push_b(*a);
	best = find_node(*a, best_value);
	cost_a = best->cost_a;
	cost_b = best->cost_b;
	double_move(a, b, &cost_a, &cost_b);
	move_a_and_b(a, b, &cost_a, &cost_b);
}
