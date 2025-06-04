/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argument.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandriaf <mandriaf@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 13:08:50 by mandriaf          #+#    #+#             */
/*   Updated: 2025/06/04 10:10:51 by mandriaf         ###   ########.fr       */
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
			write(1, "Error\n", 6);
			exit (-1);
		}
		i++;
	}
}
