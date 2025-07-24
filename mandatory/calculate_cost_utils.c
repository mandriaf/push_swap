/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_cost_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandriaf <mandriaf@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 10:50:52 by mandriaf          #+#    #+#             */
/*   Updated: 2025/07/18 11:49:23 by mandriaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_cost(t_stack *stack, int target)
{
	int	size;
	int	pos;

	size = stack_size(&stack);
	pos = find_pos_target(&stack, target);
	if (pos <= size / 2)
		return (pos);
	return (pos - size);
}

void	calculate_move_push_b(t_stack *a, t_stack *b)
{
	int		target;
	t_stack	*tmp;

	tmp = a;
	while (tmp)
	{
		target = choice_target_to_b(tmp, b);
		tmp->cost_a = get_cost(a, tmp->data);
		tmp->cost_b = get_cost(b, target);
		tmp = tmp->next;
	}
}

void	calculate_move_push_a(t_stack *a, t_stack *b)
{
	int		target;
	t_stack	*tmp;

	tmp = b;
	while (tmp)
	{
		target = choice_target_to_a(a, tmp);
		tmp->cost_a = get_cost(a, target);
		tmp->cost_b = get_cost(b, tmp->data);
		tmp = tmp->next;
	}
}
