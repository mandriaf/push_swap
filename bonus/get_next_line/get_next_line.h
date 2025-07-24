/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandriaf <mandriaf@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 12:58:21 by mandriaf          #+#    #+#             */
/*   Updated: 2025/07/24 21:41:51 by mandriaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif
# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
size_t	ft_strlen_gnl(const char *s);
char	*ft_strdup_gnl(const char *s);
char	*ft_substr_gnl(const char *s1, unsigned int start, size_t len);
char	*ft_strjoin_gnl(char *s1, char *s2);
char	*ft_strchr_gnl(const char *s, int c);

#endif
