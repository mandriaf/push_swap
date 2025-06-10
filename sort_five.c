/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandriaf <mandriaf@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 11:08:52 by mandriaf          #+#    #+#             */
/*   Updated: 2025/06/10 10:42:39 by mandriaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	min_value(t_stack **a)
{
	int		min;
	t_stack	*tmp;

	if (!a || !*a)
		exit(1);
	tmp = *a;
	min = tmp->data;
	while (tmp)
	{
		if (min > tmp->data)
			min = tmp->data;
		tmp = tmp->next;
	}
	return (min);
}

static int	find_pos_min(t_stack **a, int min)
{
	int		i;
	t_stack	*tmp;

	i = 0;
	tmp = *a;
	while (tmp)
	{
		if (tmp->data == min)
			return (i);
		tmp = tmp->next;
		i++;
	}
	return (-1);
}

static void	min_to_top(t_stack **a, int min)
{
	int	pos;
	int	size;

	size = stack_size(a);
	pos = find_pos_min(a, min);
	if (pos <= size / 2)
	{
		while (pos > 0)
		{
			rotate_a(a);
			pos--;
		}
	}
	else
	{
		while (pos < size)
		{
			reverse_rotate_a(a);
			pos++;
		}
	}
}

static int	is_sorted(t_stack **a)
{
	t_stack	*tmp;
	t_stack	*tmp1;

	tmp = *a;
	while (tmp->next)
	{
		tmp1 = tmp->next;
		while (tmp1)
		{
			if (tmp->data > tmp1->data)
				return (0);
			tmp1 = tmp1->next;
		}
		tmp = tmp->next;
	}
	return (1);
}

void	small_sort(t_stack **a, t_stack **b)
{
	int	min;
	int	pos;

	if (!a || !*a || !(*a)->next)
		return ;
	while (stack_size(a) > 3)
	{
		min = min_value(a);
		pos = find_pos_min(a, min);
		min_to_top(a, min);
		if (is_sorted(a))
			break ;
		push_b(a, b);
	}
	sort_three(a);
	while (*b)
		push_a(a, b);
}

// int main (void)
// {
// 	t_stack *a;
// 	t_stack	*b;

// 	a = NULL;
// 	b = NULL;
// 	lstadd_back(&a, new_stack(2));
// 	lstadd_back(&a, new_stack(-100));
// 	lstadd_back(&a, new_stack(0));
// 	lstadd_back(&a, new_stack(-3));
// 	lstadd_back(&a, new_stack(150));
// 	lstadd_back(&a, new_stack(-200));
// 	lstadd_back(&a, new_stack(-165498));
// 	lstadd_back(&a, new_stack(20033));
// 	lstadd_back(&a, new_stack(20));
// 	lstadd_back(&a, new_stack(42));
// 	small_sort(&a, &b);
// 	return (0);
// }
