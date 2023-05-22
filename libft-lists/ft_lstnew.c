/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpizzolo <mpizzolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 20:04:01 by mpizzolo          #+#    #+#             */
/*   Updated: 2023/05/14 19:54:27 by mpizzolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../push_swap.h"

t_list	*ft_lstnew(int content, int index)
{
	t_list	*head;

	head = (t_list *)malloc(sizeof(*head));
	if (!head)
	{
		free(head);
		return (NULL);
	}
	head->index = index;
	head->content = content;
	head->p_content = 0;
	head->next = NULL;
	return (head);
}
