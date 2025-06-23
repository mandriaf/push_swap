/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandriaf <mandriaf@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 17:44:00 by mandriaf          #+#    #+#             */
/*   Updated: 2025/06/23 17:44:09 by mandriaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	big_sort(t_stack **a, t_stack **b)
{
	int	*tab;

	tab = create_tab(a);
	sort_tab(tab, a);
	assign_index(tab, a);
	if (is_sorted(*a))
		return ;
	push_b(a, b);
	push_b(a, b);
	while (stack_size(a) > 3)
	{
		calculate_move_push_b(*a, *b);
		push_b_with_cost(a, b);
		if (is_sorted(*a))
			break ;
		push_b(a, b);
	}
	sort_three(a);
	while (*b)
	{
		calculate_move_push_a(*a, *b);
		push_a_with_cost(a, b);
		push_a(a, b);
	}
	target_a_to_top(a, find_min(*a));
}
