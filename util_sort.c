/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandriaf <mandriaf@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 20:33:35 by mandriaf          #+#    #+#             */
/*   Updated: 2025/06/21 10:59:19 by mandriaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	target_a_to_top_b(t_stack **b, int min)
{
	int	pos;
	int	size;

	size = stack_size(b);
	pos = find_pos(b, min);
	if (pos <= size / 2)
	{
		while (pos > 0)
		{
			rotate_b(b);
			pos--;
		}
	}
	else
	{
		while (pos < size)
		{
			reverse_rotate_b(b);
			pos++;
		}
	}
}

void	target_a_to_top(t_stack **a, int target)
{
	int	pos;
	int	size;

	size = stack_size(a);
	pos = find_pos(a, target);
	if (pos <= size / 2)
	{
		while (pos > 0)
		{
			rotate_a(a);
			pos--;
		}
	}
	else
	{
		while (pos < size)
		{
			reverse_rotate_a(a);
			pos++;
		}
	}
}
