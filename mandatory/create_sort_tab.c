/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_sort_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandriaf <mandriaf@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 11:54:53 by mandriaf          #+#    #+#             */
/*   Updated: 2025/06/17 20:40:57 by mandriaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*create_tab(t_stack **a)
{
	int		*tab;
	int		i;
	t_stack	*tmp;

	tab = malloc(sizeof(int) * stack_size(a));
	if (!tab)
		return (NULL);
	tmp = *a;
	i = 0;
	while (tmp)
	{
		tab[i] = tmp->data;
		tmp = tmp->next;
		i++;
	}
	return (tab);
}

void	sort_tab(int *tab, t_stack **a)
{
	int	i;
	int	j;
	int	size_a;
	int	tmp;

	if (!a)
		return ;
	size_a = stack_size(a);
	i = 0;
	while (i < size_a - 1)
	{
		j = i + 1;
		while (j < size_a)
		{
			if (tab[i] > tab[j])
			{
				tmp = tab[i];
				tab[i] = tab[j];
				tab[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

void	assign_index(int *tab, t_stack **a)
{
	int		i;
	t_stack	*tmp;
	int		size;

	if (!a || !*a)
		return ;
	size = stack_size(a);
	tmp = *a;
	i = 0;
	while (tmp)
	{
		i = 0;
		while (i < size)
		{
			if (tab[i] == tmp->data)
			{
				tmp->index = i;
				break ;
			}
			i++;
		}
		tmp = tmp->next;
	}
	free(tab);
}
