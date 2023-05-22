/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_two.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpizzolo <mpizzolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 13:45:31 by mpizzolo          #+#    #+#             */
/*   Updated: 2023/05/16 14:41:15 by mpizzolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	handle_twoargs(t_list **stack_a)
{
	t_list	*head_a;

	head_a = *stack_a;
	if (head_a->content > head_a->next->content)
	{
		write(1, "sa\n", 3);
		swap(stack_a);
	}
}
