/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandriaf <mandriaf@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 17:44:00 by mandriaf          #+#    #+#             */
/*   Updated: 2025/06/21 16:16:26 by mandriaf         ###   ########.fr       */
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
		target_b_to_top(b, choice_target_to_b(*a, *b));
		push_b(a, b);
	}
	sort_three(a);
	while (*b)
	{
		target_a_to_top(a, choice_target_to_a(*a, *b));
		push_a(a, b);
	}
	target_a_to_top(a, find_min(*a));
}
