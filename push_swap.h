/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandriaf <mandriaf@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 13:59:14 by mandriaf          #+#    #+#             */
/*   Updated: 2025/06/13 10:40:31 by mandriaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int				data;
	int				index;
	struct s_stack	*next;
}					t_stack;

t_stack				*new_stack(int data);
void				check_argument(int argc, char **argv);
int					check_double(t_stack **a);
long				ft_atoi(const char *nptr);
void				lstadd_back(t_stack **lst, t_stack *new);
void				push_a(t_stack **stack_a, t_stack **stack_b);
void				push_b(t_stack **stack_a, t_stack **stack_b);
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
void				small_sort(t_stack **a, t_stack **b);
void				sort(t_stack **a, t_stack **b);
void				free_stack(t_stack **head);
char				**ft_split(char const *s, char c);
int					stack_size(t_stack **a);
int					*create_tab(t_stack **a);
void				assign_index(int *tab, t_stack **a);
void				sort_tab(int *tab, t_stack **a);
#endif