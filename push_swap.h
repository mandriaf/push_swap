/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandriaf <mandriaf@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 13:59:14 by mandriaf          #+#    #+#             */
/*   Updated: 2025/07/23 15:10:05 by mandriaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int				data;
	int				index;
	int				cost_a;
	int				cost_b;
	struct s_stack	*next;
}					t_stack;

t_stack				*new_stack(int data);
void				check_argument(char *s);
int					check_double(t_stack **a);
char				*join_args(int argc, char **argv);
t_stack				*init_stack(int argc, char **argv);
long				ft_atoi(const char *nptr);
void				lstadd_back(t_stack **lst, t_stack *new);
void				push_a(t_stack **stack_a, t_stack **stack_b);
void				push_b(t_stack **stack_a, t_stack **stack_b);
void				rotate_a(t_stack **stack_a);
void				rotate_b(t_stack **stack_b);
void				rotate_a_and_b(t_stack **stack_a, t_stack **stack_b);
void				reverse_rotate_a(t_stack **stack_a);
void				reverse_rotate_b(t_stack **stack_b);
void				reverse_rotate_a_and_b(t_stack **stack_a,
						t_stack **stack_b);
void				swap_a_and_b(t_stack **stack_a, t_stack **stack_b);
void				swap_a(t_stack **stack_a);
void				swap_b(t_stack **stack_b);
void				sort_three(t_stack **head);
void				sort_four_and_five(t_stack **a, t_stack **b);
void				sort(t_stack **a, t_stack **b);
void				free_stack(t_stack **head);
char				**ft_split(char const *s, char c);
int					stack_size(t_stack **a);
int					*create_tab(t_stack **a);
void				assign_index(int *tab, t_stack **a);
void				sort_tab(int *tab, t_stack **a);
int					ft_strlen(const char *s);
char				*ft_strdup(const char *s);
char				*ft_strjoin(const char *s1, const char *s2);
int					is_sorted(t_stack *a);
int					find_min(t_stack *stack);
int					find_max(t_stack *stack);
int					find_pos_target(t_stack **a, int target);
void				target_a_to_top(t_stack **a, int target);
void				target_b_to_top(t_stack **b, int target);
void				big_sort(t_stack **a, t_stack **b);
int					choice_target_to_a(t_stack *a, t_stack *b);
int					choice_target_to_b(t_stack *a, t_stack *b);
void				calculate_move_push_b(t_stack *a, t_stack *b);
void				calculate_move_push_a(t_stack *a, t_stack *b);
void				push_b_with_cost(t_stack **a, t_stack **b);
void				push_a_with_cost(t_stack **a, t_stack **b);
void				double_move(t_stack **a, t_stack **b, int *cost_a,
						int *cost_b);
void				move_a_and_b(t_stack **a, t_stack **b, int *cost_a,
						int *cost_b);
int					get_cost(t_stack *stack, int target);
int					choice_best_cost(int cost_a, int cost_b);
#endif