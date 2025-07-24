/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandriaf <mandriaf@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 14:05:21 by mandriaf          #+#    #+#             */
/*   Updated: 2025/07/24 19:05:46 by mandriaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static int	count_words(char const *s1, char sep)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	if (!s1)
		return (0);
	while (s1[i] == sep && s1[i])
		i++;
	if (s1[i])
		count++;
	while (s1[i])
	{
		if (s1[i] == sep && s1[i + 1] != sep && s1[i + 1])
			count++;
		i++;
	}
	return (count);
}

static int	len_words(char const *s1, char sep, int *i)
{
	int	len_word;

	len_word = 0;
	while (s1[*i] == sep && s1[*i])
		(*i)++;
	while (s1[*i] && s1[*i] != sep)
	{
		len_word++;
		(*i)++;
	}
	return (len_word);
}

static void	var(int *i, int *j, int *y)
{
	*y = 0;
	*i = 0;
	*j = 0;
}

static char	**ft_copy(char **sp, const char *s, char c)
{
	int	i;
	int	l_word;
	int	j;
	int	y;
	int	x;

	x = 0;
	var(&i, &j, &y);
	while (i < count_words(s, c))
	{
		j = 0;
		l_word = len_words(s, c, &x);
		sp[i] = malloc(sizeof(char) * (l_word + 1));
		if (sp[i] == NULL)
			return (NULL);
		while (j < l_word)
		{
			while (s[y] == c)
				y++;
			sp[i][j++] = s[y++];
		}
		sp[i][j] = '\0';
		i++;
	}
	return (sp);
}

char	**ft_split(char const *s, char c)
{
	char	**sp;
	int		i;
	int		j;
	int		y;

	if (s == NULL)
		return (NULL);
	var(&i, &j, &y);
	sp = malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (sp == NULL)
		return (NULL);
	sp[count_words(s, c)] = NULL;
	sp = ft_copy(sp, s, c);
	return (sp);
}
