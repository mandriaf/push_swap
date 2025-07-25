/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandriaf <mandriaf@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 09:47:04 by mandriaf          #+#    #+#             */
/*   Updated: 2025/07/25 12:45:40 by mandriaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static int	do_swap_push(t_stack **a, t_stack **b, char *line)
{
	if (!ft_strcmp(line, "sa\n"))
		swap_a(a);
	else if (!ft_strcmp(line, "sb\n"))
		swap_b(b);
	else if (!ft_strcmp(line, "ss\n"))
		swap_a_and_b(a, b);
	else if (!ft_strcmp(line, "pa\n"))
		push_a(a, b);
	else if (!ft_strcmp(line, "pb\n"))
		push_b(a, b);
	else
		return (0);
	return (1);
}

static int	do_rotate(t_stack **a, t_stack **b, char *line)
{
	if (!ft_strcmp(line, "ra\n"))
		rotate_a(a);
	else if (!ft_strcmp(line, "rb\n"))
		rotate_b(b);
	else if (!ft_strcmp(line, "rr\n"))
		rotate_a_and_b(a, b);
	else if (!ft_strcmp(line, "rra\n"))
		reverse_rotate_a(a);
	else if (!ft_strcmp(line, "rrb\n"))
		reverse_rotate_b(b);
	else if (!ft_strcmp(line, "rrr\n"))
		reverse_rotate_a_and_b(a, b);
	else
		return (0);
	return (1);
}

void	do_operation(t_stack **a, t_stack **b)
{
	char	*line;

	while (1)
	{
		line = get_next_line(0);
		if (!line)
			break ;
		if (!do_swap_push(a, b, line) && !do_rotate(a, b, line))
		{
			free(line);
			free_stack(a);
			free_stack(b);
			print_error();
		}
		free(line);
	}
}
