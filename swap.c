/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandriaf <mandriaf@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 08:39:35 by mandriaf          #+#    #+#             */
/*   Updated: 2025/05/28 14:36:40 by mandriaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a_and_b(t_list **stack_a, t_list **stack_b)
{
	int	a;

	if (!stack_a || !stack_b)
		return ;
	else if (!*stack_a || !*stack_b)
		return ;
	else if (!(*stack_a)->next || !(*stack_b)->next)
		return ;
	a = (*stack_a)->data;
	(*stack_a)->data = (*stack_a)->next->data;
	(*stack_b)->next->data = a;
	a = (*stack_b)->data;
	(*stack_b)->data = (*stack_b)->next->data;
	(*stack_b)->next->data = a;
	write(1, "ss\n", 3);
}

void	swap_a(t_list **stack_a)
{
	int	tmp;

	if (!stack_a || !*stack_a || !(*stack_a)->next)
		return ;
	tmp = (*stack_a)->data;
	(*stack_a)->data = (*stack_a)->next->data;
	(*stack_a)->next->data = tmp;
	write(1, "sa\n", 3);
}

void	swap_b(t_list **stack_b)
{
	int	tmp;

	if (!stack_b || !*stack_b || !(*stack_b)->next)
		return ;
	tmp = (*stack_b)->data;
	(*stack_b)->data = (*stack_b)->next->data;
	(*stack_b)->next->data = tmp;
	write(1, "sb\n", 3);
}
