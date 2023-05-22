/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_fourfive.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpizzolo <mpizzolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 13:03:56 by mpizzolo          #+#    #+#             */
/*   Updated: 2023/05/20 15:49:28 by mpizzolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	first_steps(int argc, t_list **stack_a, t_list **stack_b)
{
	t_list	*head_a;
	t_list	*head_b;

	if (argc == 5)
	{
		pb(stack_a, stack_b);
		write(1, "pb\n", 3);
	}
	pb(stack_a, stack_b);
	write(1, "pb\n", 3);
	handle_threeargs(stack_a);
	head_a = *stack_a;
	head_b = *stack_b;
	if (head_a->next != NULL && head_b->content > head_a->content
		&& head_b->content < head_a->next->content)
	{	
		pa(stack_a, stack_b);
		write(1, "pa\n", 3);
		swap(stack_a);
		write(1, "sa\n", 3);
	}
}

void	pushing_big(t_list **stack_a, t_list **stack_b)
{
	t_list	*head_a;
	t_list	*head_b;

	head_a = *stack_a;
	head_b = *stack_b;
	if (is_bigger_than_stack(head_b->content, stack_a))
	{
		pa(stack_a, stack_b);
		r(stack_a);
		write(1, "pa\nra\n", 6);
		if (*stack_b)
			head_b = *stack_b;
	}
}

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

void	to_stack_a(t_list **stack_a, t_list **stack_b)
{
	t_list	*head_a;
	t_list	*head_b;
	int		x;

	head_a = *stack_a;
	head_b = *stack_b;
	x = after_which_index(head_b->content, stack_a);
	while (x--)
	{
		r(stack_a);
		write(1, "ra\n", 3);
	}
	pa(stack_a, stack_b);
	write(1, "pa\n", 3);
	head_b = *stack_b;
	x = get_index_of_minimum(stack_a);
	while (x--)
	{
		r(stack_a);
		write(1, "ra\n", 3);
	}
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
