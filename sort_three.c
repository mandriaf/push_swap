/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandriaf <mandriaf@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 12:49:11 by mandriaf          #+#    #+#             */
/*   Updated: 2025/05/29 09:38:30 by mandriaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
//1 2 3
//2 1 3 => sa()
//3 2 1 =>
//1 3 2
//3 1 2 =>ra()
//2 3 1 => 3 2 1
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
