/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandriaf <mandriaf@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 09:34:46 by mandriaf          #+#    #+#             */
/*   Updated: 2025/07/25 12:49:14 by mandriaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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

void	check_sorted(t_stack **a, t_stack **b)
{
	if (stack_size(b) == 0)
	{
		if (is_sorted(*a))
			write(1, "OK\n", 3);
		else
			write(1, "KO\n", 3);
	}
	else
		write(1, "KO\n", 3);
}
