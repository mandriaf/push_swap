/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argument.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandriaf <mandriaf@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 13:08:50 by mandriaf          #+#    #+#             */
/*   Updated: 2025/05/29 08:35:45 by mandriaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	argument_analysis(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	if (!argv || argc < 2)
		exit(-1);
	while (i < argc)
	{
		j = 0;
		if ((argv[i][0]) == '+' || argv[i][0] == '-')
			j++;
		while (argv[i][j])
		{
			if (argv[i][j] < '0' || argv[i][j] > '9')
			{
				write(2, "Error\n", 6);
				exit(-1);
			}
			j++;
		}
		i++;
	}
}
