/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandriaf <mandriaf@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 11:54:53 by mandriaf          #+#    #+#             */
/*   Updated: 2025/05/26 12:12:52 by mandriaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*sort_list(t_list *lst, int (*cmp)(int, int))
{
	int	tmp_data;
	t_list	*lstnext;
	t_list	*tmp;

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
