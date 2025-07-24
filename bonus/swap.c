/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandriaf <mandriaf@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 08:39:35 by mandriaf          #+#    #+#             */
/*   Updated: 2025/07/24 21:23:53 by mandriaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static void	swap(t_stack **stack)
{
	t_stack	*tmp;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	tmp = (*stack)->next;
	(*stack)->next = tmp->next;
	tmp->next = *stack;
	*stack = tmp;
}

void	swap_a(t_stack **stack_a)
{
	if (!stack_a || !*stack_a || !(*stack_a)->next)
		return ;
	swap(stack_a);
}

void	swap_b(t_stack **stack_b)
{
	if (!stack_b || !*stack_b || !(*stack_b)->next)
		return ;
	swap(stack_b);
}

void	swap_a_and_b(t_stack **stack_a, t_stack **stack_b)
{
	if (!*stack_a || !(*stack_a)->next)
	{
		swap_b(stack_b);
		return ;
	}
	if (!*stack_b || !(*stack_b)->next)
	{
		swap_a(stack_a);
		return ;
	}
	swap(stack_a);
	swap(stack_b);
}
