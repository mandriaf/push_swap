/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandriaf <mandriaf@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 09:36:45 by mandriaf          #+#    #+#             */
/*   Updated: 2025/06/06 11:02:56 by mandriaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*new_stack(int data)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->data = data;
	new->index = -1;
	new->next = NULL;
	return (new);
}
