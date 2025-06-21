/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandriaf <mandriaf@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 17:44:00 by mandriaf          #+#    #+#             */
/*   Updated: 2025/06/21 14:14:44 by mandriaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_index_max(int value, t_stack *stack)
{
	while (stack && (stack->data != value))
		stack = stack->next;
	return (stack->index);
}

static int	choice_target_to_b(t_stack *a, t_stack *b)
{
	int	diff;
	int	target;

	if (a->data > find_max(b) || a->data < find_min(b))
		return (find_max(b));
	diff = find_index_max(find_max(b), b);
	while (b)
	{
		if ((a->index - b->index < diff) && (a->index - b->index >= 0))
		{
			diff = a->index - b->index;
			target = b->data;
		}
		b = b->next;
	}
	return (target);
}

static int	choice_target_to_a(t_stack *a, t_stack *b)
{
	int	diff;
	int	target;

	if (b->data > find_max(a) || b->data < find_min(a))
		return (find_min(a));
	diff = find_index_max(find_max(a), a);
	while (a)
	{
		if ((a->index - b->index < diff) && (a->index - b->index >= 0))
		{
			diff = a->index - b->index;
			target = a->data;
		}
		a = a->next;
	}
	return (target);
}

void	big_sort(t_stack **a, t_stack **b)
{
	int	*tab;

	tab = create_tab(a);
	sort_tab(tab, a);
	assign_index(tab, a);
	if (is_sorted(*a))
		return ;
	push_b(a, b);
	push_b(a, b);
	while (stack_size(a) > 3)
	{
		target_b_to_top(b, choice_target_to_b(*a, *b));
		push_b(a, b);
	}
	sort_three(a);
	while (*b)
	{
		target_a_to_top(a, choice_target_to_a(*a, *b));
		push_a(a, b);
	}
	target_a_to_top(a, find_min(*a));
}
