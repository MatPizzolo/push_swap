/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_max_min.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpizzolo <mpizzolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 10:55:20 by mpizzolo          #+#    #+#             */
/*   Updated: 2023/05/06 07:56:23 by mpizzolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	get_index_of_minimum(t_list **stack)
{
	int		min;
	int		min_index;
	int		i;
	t_list	*head;

	head = *stack;
	min = head->content;
	i = 0;
	min_index = i;
	while (head)
	{
		if (head->content < min)
		{
			min = head->content;
			min_index = i;
		}
		head = head->next;
		i++;
	}
	return (min_index);
}

int	get_index_of_maximum(t_list **stack)
{
	int		min;
	int		min_index;
	int		i;
	t_list	*head;

	head = *stack;
	min = head->content;
	i = 0;
	min_index = i;
	while (head)
	{
		if (head->content > min)
		{
			min = head->content;
			min_index = i;
		}
		head = head->next;
		i++;
	}
	return (min_index);
}
