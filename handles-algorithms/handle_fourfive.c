/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_fourfive.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpizzolo <mpizzolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 13:03:56 by mpizzolo          #+#    #+#             */
/*   Updated: 2023/05/25 15:59:38 by mpizzolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push_max_or_min(t_list **stack_a, t_list **stack_b)
{
	t_list	*head_a;
	t_list	*head_b;

	head_a = *stack_a;
	head_b = *stack_b;
	while (head_b)
	{
		pushing_big(stack_a, stack_b);
		if (is_smallest_than_stack(head_b->content, stack_a))
		{
			pa(stack_a, stack_b);
			write(1, "pa\n", 3);
			if (*stack_b)
			head_b = *stack_b;
		}
		if (!is_bigger_than_stack(head_b->content, stack_a)
			&& !is_bigger_than_stack(head_b->content, stack_a))
			break ;
	}
}

void	rotate_stack_a(t_list **stack_a, int rotations)
{
	while (rotations--)
	{
		r(stack_a);
		write(1, "ra\n", 3);
	}
}

void	reverse_rotate_stack_a(t_list **stack_a, int rotations)
{
	while (rotations--)
	{
		rev_r(stack_a);
		write(1, "rra\n", 4);
	}
}

void	to_stack_a(t_list **stack_a, t_list **stack_b)
{
	int		x;
	int		diff;
	t_list	*head_b;

	head_b = *stack_b;
	x = after_which_index(head_b->content, stack_a);
	diff = (x - stack_len(stack_a)) * -1;
	if (diff < x)
		reverse_rotate_stack_a(stack_a, diff);
	else
		rotate_stack_a(stack_a, x);
	pa(stack_a, stack_b);
	write(1, "pa\n", 3);
	head_b = *stack_b;
	x = get_index_of_minimum(stack_a);
	diff = (x - stack_len(stack_a)) * -1;
	if (diff < x)
		reverse_rotate_stack_a(stack_a, diff);
	else
		rotate_stack_a(stack_a, x);
}

void	handle_fourfive_args(int argc, t_list **stack_a, t_list **stack_b)
{
	t_list	*head_a;
	t_list	*head_b;

	first_steps(argc, stack_a, stack_b);
	push_max_or_min(stack_a, stack_b);
	head_a = *stack_a;
	head_b = *stack_b;
	if (*stack_b)
	{
		while (*stack_b)
		{
			to_stack_a(stack_a, stack_b);
			head_b = head_b->next;
		}
	}
}
