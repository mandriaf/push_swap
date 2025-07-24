/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandriaf <mandriaf@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 12:59:34 by mandriaf          #+#    #+#             */
/*   Updated: 2025/07/24 21:41:45 by mandriaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen_gnl(const char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup_gnl(const char *s)
{
	char	*dup;
	int		i;

	if (!s)
		return (NULL);
	dup = malloc(sizeof(char) * (ft_strlen_gnl(s) + 1));
	if (!dup)
		return (NULL);
	i = 0;
	while (*s)
	{
		dup[i] = *s;
		i++;
		s++;
	}
	dup[i] = '\0';
	return (dup);
}

char	*ft_substr_gnl(const char *s1, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;

	if (!s1)
		return (NULL);
	if (start >= ft_strlen_gnl(s1))
		return (NULL);
	if (len > ft_strlen_gnl(s1) - start)
		return (NULL);
	i = 0;
	sub = malloc(sizeof(char) * (len + 1));
	if (!sub)
		return (NULL);
	while (s1[start] && i < len)
		sub[i++] = s1[start++];
	sub[i] = '\0';
	return (sub);
}

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	char	*join;
	int		i;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup_gnl(s2));
	if (!s2)
		return (ft_strdup_gnl(s1));
	i = 0;
	join = malloc(sizeof(char) * (ft_strlen_gnl(s1) + ft_strlen_gnl(s2) + 1));
	if (!join)
		return (NULL);
	while (*s1)
		join[i++] = *s1++;
	while (*s2)
		join[i++] = *s2++;
	join[i] = '\0';
	return (join);
}

char	*ft_strchr_gnl(const char *s, int c)
{
	size_t	i;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)s + i);
		i++;
	}
	if ((char)c == '\0')
		return ((char *)s + i);
	return (NULL);
}
