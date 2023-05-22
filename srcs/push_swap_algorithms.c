/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_algorithms.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpizzolo <mpizzolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 14:34:35 by mpizzolo          #+#    #+#             */
/*   Updated: 2023/05/16 18:28:21 by mpizzolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap(t_list **stack)
{
	t_list	*first;
	t_list	*second;

	if (*stack != NULL && (*stack)->next != NULL)
	{
		first = *stack;
		second = (*stack)->next;
		first->next = second->next;
		second->next = first;
		*stack = second;
	}
}

void	ss(t_list **stack_a, t_list **stack_b)
{
	swap(stack_a);
	swap(stack_b);
}

void	pa(t_list **stack_a, t_list **stack_b)
{
	t_list	*head_b;
	t_list	*head_a;

	head_a = *stack_a;
	head_b = *stack_b;
	*stack_b = head_b->next;
	head_b->next = head_a;
	*stack_a = head_b;
}

void	pb(t_list **stack_a, t_list **stack_b)
{
	t_list	*head_b;
	t_list	*head_a;

	head_a = *stack_a;
	head_b = *stack_b;
	*stack_a = head_a->next;
	head_a->next = head_b;
	*stack_b = head_a;
}

void	r(t_list **stack)
{
	t_list	*last;
	t_list	*first;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	last = *stack;
	while (last->next != NULL)
	{
		last = last->next;
	}
	first = *stack;
	*stack = first->next;
	last->next = first;
	first->next = NULL;
}
