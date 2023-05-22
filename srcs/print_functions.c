/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpizzolo <mpizzolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 15:14:37 by mpizzolo          #+#    #+#             */
/*   Updated: 2023/05/20 15:46:42 by mpizzolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	printwholestruct(t_list **stack)
{
	t_list	*head;

	head = *stack;
	if (stack == NULL || *stack == NULL)
	{
		printf("Linked list is empty\n");
		return ;
	}
	while (head != NULL)
	{
		printf("content: [%i] %i\n", head->index, head->content);
		head = head->next;
	}
}

// void	printwholestruct_p(t_list **stack)
// {
// 	t_list	*head;

// 	head = *stack;
// 	if (stack == NULL || *stack == NULL)
// 	{
// 		printf("Linked list is empty\n");
// 		return ;
// 	}
// 	while (head != NULL)
// 	{
// 		printf("[%i]-> %i\n", head->content, head->p_content);
// 		head = head->next;
// 	}
// }
