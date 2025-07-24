/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandriaf <mandriaf@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 12:08:16 by mandriaf          #+#    #+#             */
/*   Updated: 2025/07/24 21:27:33 by mandriaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static void	rotate(t_stack **head)
{
	t_stack	*first;
	t_stack	*tail;

	if (!head || !*head || !(*head)->next)
		return ;
	first = *head;
	*head = first->next;
	first->next = NULL;
	tail = *head;
	while (tail && tail->next)
		tail = tail->next;
	tail->next = first;
}

void	rotate_a(t_stack **stack_a)
{
	if (!stack_a || !*stack_a || !(*stack_a)->next)
		return ;
	rotate(stack_a);
}

void	rotate_b(t_stack **stack_b)
{
	if (!stack_b || !*stack_b || !(*stack_b)->next)
		return ;
	rotate(stack_b);
}

void	rotate_a_and_b(t_stack **stack_a, t_stack **stack_b)
{
	if (!*stack_a || !(*stack_a)->next)
	{
		rotate_b(stack_b);
		return ;
	}
	if (!*stack_b || !(*stack_b)->next)
	{
		rotate_a(stack_a);
		return ;
	}
	rotate(stack_a);
	rotate(stack_b);
}
