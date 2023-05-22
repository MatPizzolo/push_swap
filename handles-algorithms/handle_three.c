/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_three.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpizzolo <mpizzolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 13:34:23 by mpizzolo          #+#    #+#             */
/*   Updated: 2023/05/16 17:10:30 by mpizzolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	check_lowest_on_top(t_list	**stack_a)
{
	t_list	*head_a;
	int		position;
	int		temp;

	position = 0;
	head_a = *stack_a;
	temp = head_a->content;
	head_a = head_a->next;
	if (temp < head_a->content && temp < head_a->next->content)
		position = 0;
	if (temp > head_a->content && head_a->content < head_a->next->content)
		position = 1;
	if (temp > head_a->next->content && head_a->content > head_a->next->content)
		position = 2;
	return (position);
}

int	check_biggest_on_top(t_list	**stack_a)
{
	t_list	*head_a;
	int		position;
	int		temp;

	position = 0;
	head_a = *stack_a;
	temp = head_a->content;
	head_a = head_a->next;
	if (temp > head_a->content && temp > head_a->next->content)
		position = 0;
	if (temp < head_a->content && head_a->content > head_a->next->content)
		position = 1;
	if (temp < head_a->next->content && head_a->content < head_a->next->content)
		position = 2;
	return (position);
}

void	hdl_sml_lgst(int small, int large, t_list **stack_a)
{
	if (small == 1 && large == 2)
	{
		swap(stack_a);
		write(1, "sa\n", 3);
	}
	else if (small == 2 && large == 1)
	{	
		rev_r(stack_a);
		write(1, "rra\n", 4);
	}
	else if (small == 2 && large == 0)
	{	
		swap(stack_a);
		write(1, "sa\n", 3);
		rev_r(stack_a);
		write(1, "rra\n", 4);
	}
}

void	hdl_smallest_largest(int small, int large, t_list **stack_a)
{
	if ((small == 0 && large == 1))
	{	
		swap(stack_a);
		write(1, "sa\n", 3);
		r(stack_a);
		write(1, "ra\n", 3);
	}
	else if (small == 1 && large == 0)
	{
		r(stack_a);
		write(1, "ra\n", 3);
	}
	else
		hdl_sml_lgst(small, large, stack_a);
}

void	handle_threeargs(t_list **stack_a)
{
	int		small_position;
	int		large_position;

	small_position = check_lowest_on_top(stack_a);
	large_position = check_biggest_on_top(stack_a);
	hdl_smallest_largest(small_position, large_position, stack_a);
}
