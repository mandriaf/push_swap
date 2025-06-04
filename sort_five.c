/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandriaf <mandriaf@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 11:08:52 by mandriaf          #+#    #+#             */
/*   Updated: 2025/06/04 12:43:44 by mandriaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	min_value(t_stack **a)
{
	int	min;
	t_stack	*tmp;

	if (!a || !*a)
		exit (-1);
	tmp = *a;
	while (tmp)
	{
		min = tmp->data;
		if (min > tmp->data)
			min = tmp->data;
		tmp = tmp->next; 
	}
	return (min);
}
