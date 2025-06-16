/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandriaf <mandriaf@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 09:40:52 by mandriaf          #+#    #+#             */
/*   Updated: 2025/06/16 22:30:36 by mandriaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*join;
	int		i;

	if (!s1)
		return (ft_strdup(s2));
	if (!s1 && !s2)
		return (NULL);
	join = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 3));
	if (!join)
		return (NULL);
	i = 0;
	while (*s1)
		join[i++] = *s1++;
	join[i++] = ' ';
	while (*s2)
		join[i++] = *s2++;
	join[i] = '\0';
	return (join);
}

// int	main(void)
// {
// 	char *x = ft_strjoin("kakana", "maloto");
// 	printf("%s\n", x);
// 	free(x);
// 	return (0);
// }
