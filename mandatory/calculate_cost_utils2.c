/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_cost_utils2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandriaf <mandriaf@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 11:40:35 by mandriaf          #+#    #+#             */
/*   Updated: 2025/07/21 14:58:02 by mandriaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	absolute_value(int value)
{
	if (value < 0)
		return (-value);
	return (value);
}

static int	ft_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	choice_best_cost(int cost_a, int cost_b)
{
	if ((cost_a >= 0 && cost_b >= 0) || (cost_a < 0 && cost_b < 0))
		return (ft_max(absolute_value(cost_a), absolute_value(cost_b)));
	else
		return (absolute_value(cost_a) + absolute_value(cost_b));
}
