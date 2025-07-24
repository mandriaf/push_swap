/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandriaf <mandriaf@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 09:36:45 by mandriaf          #+#    #+#             */
/*   Updated: 2025/07/24 20:37:14 by mandriaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

t_stack	*new_stack(int data)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->data = data;
	new->next = NULL;
	return (new);
}
