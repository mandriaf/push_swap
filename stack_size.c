/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_size.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandriaf <mandriaf@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 10:19:57 by mandriaf          #+#    #+#             */
/*   Updated: 2025/06/10 12:55:54 by mandriaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_size(t_stack **a)
{
	int		size;
	t_stack	*tmp;

	if (!a || !*a)
		return (-1);
	size = 0;
	tmp = *a;
	while (tmp)
	{
		size++;
		tmp = tmp->next;
	}
	return (size);
}
