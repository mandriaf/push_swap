/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_cost.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandriaf <mandriaf@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 16:04:28 by mandriaf          #+#    #+#             */
/*   Updated: 2025/06/23 10:12:11 by mandriaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	absolute_value(int value)
{
	if (value < 0)
		return (-value);
	return (value);
}

static int	get_cost(t_stack *stack, int target)
{
	int	size;
	int	pos;

	size = stack_size(&stack);
	pos = find_pos_target(&stack, target);
	if (pos <= size / 2)
		return (pos);
	return (pos - size);
}

void	calculate_move_top(t_stack *a, t_stack *b)
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

int	best_value_push_b(t_stack *stack)
{
	int	cost;
	int	current;
	int	best;

	current = absolute_value(stack->cost_a) + absolute_value(stack->cost_b);
	best = stack->data;
	while (stack)
	{
		cost = absolute_value(stack->cost_a) + absolute_value(stack->cost_b);
		if (cost < current)
		{
			best = stack->data;
			current = cost;
		}
		stack = stack->next;
	}
	return (best);
}

static t_stack	*find_node(t_stack *stack, int target)
{
	while (stack)
	{
		if (stack->data == target)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

void	double_move(t_stack **a, t_stack **b, int *cost_a, int *cost_b)
{
	while (*cost_a > 0 && *cost_b > 0)
	{
		rotate_a_and_b(a, b);
		(*cost_a)--;
		(*cost_b)--;
	}
	while (*cost_a < 0 && *cost_b < 0)
	{
		reverse_rotate_a_and_b(a, b);
		(*cost_a)++;
		(*cost_b)++;
	}
}

void	move_a_and_b(t_stack **a, t_stack **b, int *cost_a, int *cost_b)
{
	while (*cost_a > 0)
	{
		rotate_a(a);
		(*cost_a)--;
	}
	while (*cost_a < 0)
	{
		reverse_rotate_a(a);
		(*cost_a)++;
	}
	while (*cost_b > 0)
	{
		rotate_b(b);
		(*cost_b)--;
	}
	while (*cost_b < 0)
	{
		reverse_rotate_b(b);
		(*cost_b)++;
	}
}

void	push_b_with_cost(t_stack **a, t_stack **b)
{
	int		best_value;
	int		target_in_b;
	int		cost_a;
	int		cost_b;
	t_stack	*node;

	best_value = best_value_push_b(*a);
	node = find_node(*a, best_value);
	target_in_b = choice_target_to_b(node, *b);
	cost_a = node->cost_a;
	cost_b = get_cost(*b, target_in_b);
	double_move(a, b, &cost_a, &cost_b);
	move_a_and_b(a, b, &cost_a, &cost_b);
}
