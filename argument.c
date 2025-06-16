/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argument.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandriaf <mandriaf@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 13:08:50 by mandriaf          #+#    #+#             */
/*   Updated: 2025/06/16 22:22:18 by mandriaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_is_digit(int c)
{
	if (c < '0' && c > '9')
		return (0);
	return (1);
}

void	check_argument(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if ((s[i] == '+' || s[i] == '-')
			&& (s[i + 1] != '+' || s[i + 1] != '-'))
			i++;
		if (ft_is_digit(s[i]) == 0)
		{
			write(2, "Error\n", 6);
			free(s);
			exit(1);
		}
		i++;
	}
}

int	check_double(t_stack **a)
{
	t_stack	*tmp;
	t_stack	*tmp_next;

	if (!a || !*a)
		exit(1);
	tmp = *a;
	while (tmp && tmp->next)
	{
		tmp_next = tmp->next;
		while (tmp_next)
		{
			if (tmp->data == tmp_next->data)
				return (1);
			tmp_next = tmp_next->next;
		}
		tmp = tmp->next;
	}
	return (0);
}
