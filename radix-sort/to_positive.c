/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_positive.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpizzolo <mpizzolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 16:45:53 by mpizzolo          #+#    #+#             */
/*   Updated: 2023/05/16 17:27:54 by mpizzolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	get_smallest(t_list **stack)
{
	t_list	*head;
	int		smallest;

	head = *stack;
	smallest = INT16_MAX;
	while (head)
	{
		if (head->content < smallest)
			smallest = head->content;
		head = head->next;
	}
	return (smallest);
}

void	converting_to_positive(t_list **stack)
{
	t_list	*head;
	t_list	*tmp;
	int		smallest;

	head = *stack;
	smallest = get_smallest(stack);
	head = *stack;
	while (head)
	{
		tmp = *stack;
		head->p_content = 0;
		while (tmp)
		{
			if (tmp->content < smallest || tmp->content >= head->content)
				tmp = tmp->next;
			else
			{
				head->p_content++;
				tmp = tmp->next;
			}
		}
		head = head->next;
	}
}
