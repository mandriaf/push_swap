/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandriaf <mandriaf@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 09:42:36 by mandriaf          #+#    #+#             */
/*   Updated: 2025/06/16 20:48:38 by mandriaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort(t_stack **a, t_stack **b)
{
	if (!a || !*a)
		return ;
	if (stack_size(a) == 2)
	{
		if ((*a)->data > (*a)->next->data)
			swap_a(a);
	}
	else if (stack_size(a) == 3)
		sort_three(a);
	else
		sort_four_and_five(a, b);
}
