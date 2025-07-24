/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_size.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandriaf <mandriaf@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 10:19:57 by mandriaf          #+#    #+#             */
/*   Updated: 2025/07/24 21:53:06 by mandriaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	stack_size(t_stack **stack)
{
	int		size;
	t_stack	*tmp;

	if (!stack || !*stack)
		return (0);
	size = 0;
	tmp = *stack;
	while (tmp)
	{
		size++;
		tmp = tmp->next;
	}
	return (size);
}
