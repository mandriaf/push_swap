/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandriaf <mandriaf@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 18:40:48 by mandriaf          #+#    #+#             */
/*   Updated: 2025/07/24 21:06:28 by mandriaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int				data;
	struct s_stack	*next;
}					t_stack;

int					check_double(t_stack **a);
void				free_stack(t_stack **head);
long				ft_atoi(const char *nptr);
char				**ft_split(char const *s, char c);
char				*ft_strdup(const char *s);
char				*ft_strjoin(const char *s1, const char *s2);
int					ft_strlen(const char *s);
char				*get_next_line(int fd);
t_stack				*init_stack(int argc, char **argv);
int					is_sorted(t_stack *a);
void				lstadd_back(t_stack **lst, t_stack *new);
t_stack				*new_stack(int data);
void				swap_a(t_stack **stack_a);
void				swap_b(t_stack **stack_b);
void				swap_a_and_b(t_stack **stack_a, t_stack **stack_b);
void				push_a(t_stack **stack_a, t_stack **stack_b);
void				push_b(t_stack **stack_a, t_stack **stack_b);
void				reverse_rotate_a(t_stack **stack_a);
void				reverse_rotate_b(t_stack **stack_b);
void				reverse_rotate_a_and_b(t_stack **stack_a,
						t_stack **stack_b);
void				rotate_a(t_stack **stack_a);
void				rotate_b(t_stack **stack_b);
void				rotate_a_and_b(t_stack **stack_a, t_stack **stack_b);
int					ft_strcmp(char *s1, char *s2);
#endif
