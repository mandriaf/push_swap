/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandriaf <mandriaf@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 11:08:52 by mandriaf          #+#    #+#             */
/*   Updated: 2025/06/21 10:50:21 by mandriaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_four_and_five(t_stack **a, t_stack **b)
{
	if (!a || !*a || !(*a)->next)
		return ;
	while (stack_size(a) > 3)
	{
		target_a_to_top(a, find_min(*a));
		if (is_sorted(*a))
			break ;
		push_b(a, b);
	}
	sort_three(a);
	while (*b)
		push_a(a, b);
}
