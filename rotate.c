/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandriaf <mandriaf@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 12:08:16 by mandriaf          #+#    #+#             */
/*   Updated: 2025/05/28 13:45:24 by mandriaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

//./a.out a b c d
// void	rotate_a(t_list **lst)
// {
// 	t_list	*tmp;
// 	int		value;

// 	if (!lst || !*lst || !(*lst)->next)
// 		return ;
// 	value = (*lst)->data;
// 	tmp = *lst;
// 	while (tmp && tmp->next)
// 	{
// 		tmp->data = tmp->next->data;
// 		tmp = tmp->next;
// 	}
// 	tmp->data = value;
// 	printf("ra\n");
// }
void	rotate_a(t_list **lst)
{
	t_list	*head;
	t_list	*tail;

	if (!lst || !*lst || !(*lst)->next)
		return ;
	head = *lst;
	*lst = head->next;
	head->next = NULL;
	tail = *lst;
	while (tail && tail->next)
		tail = tail->next;
	tail->next = head;
	write(1, "ra\n", 3);
}

// rapitso ndray oooo
void	reverse_rotate_a(t_list **lst)
{
	t_list	*tail;
	t_list	*head;

	if (!lst || !*lst || !(*lst)->next)
		return ;
	tail = *lst;
	while (tail && tail->next)
	{
		head = tail;
		tail = tail->next;
	}
	head->next = NULL;
	tail->next = *lst;
	*lst = tail;
	write(1, "rra\n", 4);
}
