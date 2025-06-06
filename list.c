/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandriaf <mandriaf@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 12:54:20 by mandriaf          #+#    #+#             */
/*   Updated: 2025/06/04 12:46:00 by mandriaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_stack **head)
{
	t_stack	*tmp;

	if (!head || !*head)
		return ;
	while (*head)
	{
		tmp = (*head)->next;
		free(*head);
		*head = tmp;
	}
}

void	print_list(t_stack **head)
{
	t_stack	*tmp;

	if (!head)
		return ;
	tmp = *head;
	while (tmp)
	{
		printf("%d -> ", tmp->data);
		tmp = tmp->next;
	}
	printf("NULL\n");
}
