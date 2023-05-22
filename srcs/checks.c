/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpizzolo <mpizzolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 13:17:26 by mpizzolo          #+#    #+#             */
/*   Updated: 2023/05/16 17:08:04 by mpizzolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	check_swapnoprint(t_list **stack)
{
	t_list	*head;

	head = *stack;
	if (!head)
		return (0);
	while (head->next)
	{
		if (head->content > head->next->content)
			return (0);
		head = head->next;
	}
	return (1);
}

int	check_duplicate(t_list **stack)
{
	int		dups;
	t_list	*head;
	t_list	*second_h;

	dups = 0;
	head = *stack;
	while (head)
	{
		second_h = *stack;
		while (second_h)
		{
			if (head->content == second_h->content
				&& head->index != second_h->index)
				dups++;
			second_h = second_h->next;
		}
		head = head->next;
	}
	if (dups > 0)
		return (1);
	else
		return (0);
}

int	ft_checks(char *str)
{
	if (!check_not_digit(str) || !check_symbols(str))
		return (0);
	return (1);
}

int	check_not_digit(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if ((str[i] < 48 || str[i] > 57) && str[i] != 45 && str[i] != 43)
			return (0);
	}
	return (1);
}

int	check_symbols(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if ((str[i] == 45 || str[i] == 43)
			&& (str[i + 1] < 48 || str[i + 1] > 57))
			return (0);
	}
	return (1);
}
