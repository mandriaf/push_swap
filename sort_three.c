/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandriaf <mandriaf@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 12:49:11 by mandriaf          #+#    #+#             */
/*   Updated: 2025/05/26 14:57:15 by mandriaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
//1 2 3
//2 1 3
//3 1 2
//2 3 1
void	sort_three(t_list **lst)
{
	int	a;
	int	b;
	int	c;

	if (!lst || !*lst || !(*lst)->next)
		return ;
	a = (*lst)->data;
	b = (*lst)->next->data;
	c = (*lst)->next->next->data;
	if (a < b && a < c)
		return ;
	else if (a > b && b < c && a > c)
		rotate_a(lst);
	else if (a > b && b < c)
		swap_a(lst);
}
