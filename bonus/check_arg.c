/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandriaf <mandriaf@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 13:08:50 by mandriaf          #+#    #+#             */
/*   Updated: 2025/07/24 20:13:34 by mandriaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	check_double(t_stack **a)
{
	t_stack	*tmp;
	t_stack	*tmp_next;

	if (!a || !*a)
		exit(1);
	tmp = *a;
	while (tmp && tmp->next)
	{
		tmp_next = tmp->next;
		while (tmp_next)
		{
			if (tmp->data == tmp_next->data)
				return (1);
			tmp_next = tmp_next->next;
		}
		tmp = tmp->next;
	}
	return (0);
}
