/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandriaf <mandriaf@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 11:54:53 by mandriaf          #+#    #+#             */
/*   Updated: 2025/05/29 09:18:05 by mandriaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*sort_list(t_stack *lst, int (*cmp)(int, int))
{
	int	tmp_data;
	t_stack	*lstnext;
	t_stack	*tmp;

	if (!lst || !cmp)
		return (NULL);
	tmp = lst;
	while (tmp->next)
	{
		lstnext = tmp->next;
		while (lstnext)
		{
			if (!cmp(tmp->data, lstnext->data))
			{
				tmp_data = tmp->data;
				tmp->data = lstnext->data;
				lstnext->data = tmp_data;
			}
			lstnext = lstnext->next;
		}
		tmp = tmp->next;
	}
	return (lst);
}
