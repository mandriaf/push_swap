/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandriaf <mandriaf@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 10:43:18 by mandriaf          #+#    #+#             */
/*   Updated: 2025/07/24 20:34:48 by mandriaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static void	free_all_split(char **s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		free(s[i]);
		i++;
	}
	free(s);
}

static char	*join_args(int argc, char **argv)
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

static int	is_valid_number(char *s)
{
	if (!s)
		exit(1);
	if (*s == '+' || *s == '-')
		s++;
	if (!*s)
		return (0);
	while (*s)
	{
		if (*s < '0' || *s > '9')
			return (0);
		s++;
	}
	return (1);
}

t_stack	*init_stack(int argc, char **argv)
{
	t_stack	*stack_a;
	char	**tmp;
	int		i;
	char	*tmp_argv;

	stack_a = NULL;
	i = 0;
	tmp_argv = join_args(argc, argv);
	tmp = ft_split(tmp_argv, ' ');
	free(tmp_argv);
	while (tmp[i])
	{
		if (!is_valid_number(tmp[i]) || ft_atoi(tmp[i]) < INT_MIN
			|| ft_atoi(tmp[i]) > INT_MAX)
		{
			write(2, "Error\n", 6);
			free_all_split(tmp);
			free_stack(&stack_a);
			exit(1);
		}
		lstadd_back(&stack_a, new_stack(ft_atoi(tmp[i])));
		i++;
	}
	free_all_split(tmp);
	return (stack_a);
}
