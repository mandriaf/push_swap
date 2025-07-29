/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandriaf <mandriaf@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 20:33:35 by mandriaf          #+#    #+#             */
/*   Updated: 2025/07/29 19:32:29 by mandriaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	target_a_to_top(t_stack **a, int target)
{
	int	pos;
	int	size;

	size = stack_size(a);
	pos = find_pos_target(a, target);
	if (pos <= size / 2)
	{
		while (pos-- > 0)
			rotate_a(a);
	}
	else
	{
		while (pos++ < size)
			reverse_rotate_a(a);
	}
}
