/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandriaf <mandriaf@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 09:48:42 by mandriaf          #+#    #+#             */
/*   Updated: 2025/07/24 19:06:11 by mandriaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

char	*ft_strdup(const char *s)
{
	char	*dup;
	int		i;

	if (!s)
		return (NULL);
	i = 0;
	dup = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!dup)
		return (NULL);
	while (*s)
		dup[i++] = *s++;
	dup[i] = '\0';
	return (dup);
}
