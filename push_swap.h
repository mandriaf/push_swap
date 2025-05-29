/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandriaf <mandriaf@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 13:59:14 by mandriaf          #+#    #+#             */
/*   Updated: 2025/05/29 09:18:29 by mandriaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int				data;
	struct s_stack	*next;
}					t_stack;

void				argument_analysis(int argc, char **argv);
long				ft_atoi(const char *nptr);
void				lstadd_back(t_stack **lst, t_stack *new);
void				rotate(t_stack **head);
void				rotate_a(t_stack **stack_a);
void				rotate_b(t_stack **stack_b);
void				rotate_a_and_b(t_stack **stack_a, t_stack **stack_b);
void				reverse_rotate(t_stack **head);
void				reverse_rotate_a(t_stack **stack_a);
void				reverse_rotate_b(t_stack **stack_b);
void				reverse_rotate_a_and_b(t_stack **stack_a,
						t_stack **stack_b);
void				swap(t_stack **stack);
void				swap_a_and_b(t_stack **stack_a, t_stack **stack_b);
void				swap_a(t_stack **stack_a);
void				swap_b(t_stack **stack_b);
void				sort_three(t_stack **head);

#endif