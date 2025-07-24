/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandriaf <mandriaf@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 09:34:46 by mandriaf          #+#    #+#             */
/*   Updated: 2025/07/24 19:56:58 by mandriaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	is_sorted(t_stack *a)
{
	while (a && a->next)
	{
		if (a->data > a->next->data)
			return (0);
		a = a->next;
	}
	return (1);
}
