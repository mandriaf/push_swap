/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandriaf <mandriaf@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 10:43:18 by mandriaf          #+#    #+#             */
/*   Updated: 2025/06/16 14:23:52 by mandriaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	free_all_split(char **s, int j)
{
	int	i;

	i = 0;
	while (i <= j)
	{
		free(s[i]);
		i++;
	}
	free(s);
}

char	*join_args(int argc, char **argv)
{
	char	*argv_joined;
	int		i;
	char	*tmp;

	argv_joined = NULL;
	i = 1;
	while (i < argc)
	{
		tmp = argv_joined;
		if (argv[i][0] == '\0')
		{
			free(tmp);
			write(2, "Error\n", 6);
			exit(1);
		}
		argv_joined = ft_strjoin(tmp, argv[i]);
		free(tmp);
		i++;
	}
	return (argv_joined);
}

t_stack	*init_stack(int argc, char **argv)
{
	t_stack	*stack_a;
	char	**tmp;
	int		i;
	char	*tmp_argv;

	i = 0;
	stack_a = NULL;
	tmp_argv = join_args(argc, argv);
	check_argument(tmp_argv);
	tmp = ft_split(tmp_argv, ' ');
	free(tmp_argv);
	while (tmp[i])
	{
		if (ft_atoi(tmp[i]) < INT_MIN || ft_atoi(tmp[i]) > INT_MAX)
		{
			write(2, "Error\n", 6);
			free_all_split(tmp, i);
			free_stack(&stack_a);
			return (NULL);
		}
		lstadd_back(&stack_a, new_stack(ft_atoi(tmp[i])));
		i++;
	}
	free_all_split(tmp, i);
	return (stack_a);
}
