/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argument.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandriaf <mandriaf@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 13:08:50 by mandriaf          #+#    #+#             */
/*   Updated: 2025/06/13 10:42:01 by mandriaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_is_digit(const char *s)
{
	if (!s)
		exit(0);
	if (*s == '+' || *s == '-')
		s++;
	while (*s)
	{
		if (*s < '0' || *s > '9')
			return (0);
		s++;
	}
	return (1);
}

void	check_argument(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	if (!argv || argc < 2)
		exit(-1);
	while (i < argc)
	{
		if (!ft_is_digit(argv[i]))
		{
			write(2, "Error\n", 6);
			exit (1);
		}
		i++;
	}
}

int	check_double(t_stack **a)
{
	t_stack	*tmp;
	int		value;
	t_stack	*tmp_next;

	if (!a || !*a)
		exit (1);
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
