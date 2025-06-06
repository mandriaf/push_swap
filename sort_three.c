/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandriaf <mandriaf@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 12:49:11 by mandriaf          #+#    #+#             */
/*   Updated: 2025/06/06 09:33:50 by mandriaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack **head)
{
	int	a;
	int	b;
	int	c;

	if (!head || !*head || !(*head)->next)
		return ;
	a = (*head)->data;
	b = (*head)->next->data;
	c = (*head)->next->next->data;
	if (a > b && b < c && a < c)
		swap_a(head);
	else if (a > b && a > c && b > c)
	{
		rotate_a(head);
		swap_a(head);
	}
	else if (a < b && b > c && a < c)
	{
		swap_a(head);
		rotate_a(head);
	}
	else if (a > b && b < c && a > c)
		rotate_a(head);
	else if (a < b && b > c && a > c)
		reverse_rotate_a(head);
}
