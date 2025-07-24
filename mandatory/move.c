/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandriaf <mandriaf@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 10:26:46 by mandriaf          #+#    #+#             */
/*   Updated: 2025/06/23 10:28:54 by mandriaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	double_move(t_stack **a, t_stack **b, int *cost_a, int *cost_b)
{
	while (*cost_a > 0 && *cost_b > 0)
	{
		rotate_a_and_b(a, b);
		(*cost_a)--;
		(*cost_b)--;
	}
	while (*cost_a < 0 && *cost_b < 0)
	{
		reverse_rotate_a_and_b(a, b);
		(*cost_a)++;
		(*cost_b)++;
	}
}

void	move_a_and_b(t_stack **a, t_stack **b, int *cost_a, int *cost_b)
{
	while (*cost_a > 0)
	{
		rotate_a(a);
		(*cost_a)--;
	}
	while (*cost_a < 0)
	{
		reverse_rotate_a(a);
		(*cost_a)++;
	}
	while (*cost_b > 0)
	{
		rotate_b(b);
		(*cost_b)--;
	}
	while (*cost_b < 0)
	{
		reverse_rotate_b(b);
		(*cost_b)++;
	}
}
