/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandriaf <mandriaf@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 12:59:20 by mandriaf          #+#    #+#             */
/*   Updated: 2025/07/24 20:54:02 by mandriaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "../push_swap_bonus.h"

static void	free_and_null(char **ptr)
{
	if (*ptr)
	{
		free(*ptr);
		*ptr = NULL;
	}
}

static char	*read_and_join(int fd, char *join)
{
	ssize_t	verif_read;
	char	*buffer;
	char	*tmp;

	if (BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	verif_read = read(fd, buffer, BUFFER_SIZE);
	if (verif_read == -1)
		return (free(buffer), free_and_null(&join), NULL);
	while (verif_read > 0)
	{
		tmp = join;
		buffer[verif_read] = '\0';
		join = ft_strjoin_gnl(tmp, buffer);
		free(tmp);
		if (ft_strchr_gnl(join, '\n'))
			break ;
		verif_read = read(fd, buffer, BUFFER_SIZE);
	}
	free(buffer);
	return (join);
}

static char	*after_line(char *s)
{
	char	*after;
	int		i;

	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	if (s[i] == '\n')
		i++;
	after = ft_substr_gnl(s, i, ft_strlen_gnl(s) - i);
	free_and_null(&s);
	return (after);
}

static char	*ft_line(char *s)
{
	char	*line;
	int		i;

	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	if (s[i] == '\n')
		i++;
	line = ft_substr_gnl(s, 0, i);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*tmp;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	tmp = read_and_join(fd, tmp);
	if (!tmp || tmp[0] == '\0')
		return (free_and_null(&tmp), NULL);
	line = ft_line(tmp);
	if (!line || line[0] == '\0')
		return (free_and_null(&tmp), NULL);
	tmp = after_line(tmp);
	return (line);
}
