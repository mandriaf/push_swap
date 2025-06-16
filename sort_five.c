/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandriaf <mandriaf@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 11:08:52 by mandriaf          #+#    #+#             */
/*   Updated: 2025/06/16 21:41:43 by mandriaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_sorted(t_stack *a)
{
	while (a && a->next)
	{
		if (a->data > a->next->data)
			return (0);
		a = a->next;
	}
	return (1);
}

void	sort_four_and_five(t_stack **a, t_stack **b)
{
	int	min;

	if (!a || !*a || !(*a)->next)
		return ;
	while (stack_size(a) > 3)
	{
		min = find_min(*a);
		min_to_top(a, min);
		if (is_sorted(*a))
			break ;
		push_b(a, b);
	}
	sort_three(a);
	while (*b)
		push_a(a, b);
}
