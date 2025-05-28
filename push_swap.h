/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandriaf <mandriaf@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 13:59:14 by mandriaf          #+#    #+#             */
/*   Updated: 2025/05/28 14:36:42 by mandriaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	int				data;
	struct s_list	*next;
}					t_list;

void				argument_analysis(int argc, char **argv);
long				ft_atoi(const char *nptr);
void				lstadd_back(t_list **lst, t_list *new);
void				rotate_a(t_list **lst);
void				reverse_rotate_a(t_list **lst);
void				swap_a_and_b(t_list **stack_a, t_list **stack_b);
void				swap_a(t_list **stack_a);
void				swap_b(t_list **stack_b);
#endif