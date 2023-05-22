/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpizzolo <mpizzolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 18:57:29 by mpizzolo          #+#    #+#             */
/*   Updated: 2023/05/06 11:32:28 by mpizzolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../push_swap.h"

void	ft_lstclear(t_list **lst, void (*del)(int))
{	
	t_list	*ptr;
	t_list	*temp;

	if (lst)
	{
		temp = *lst;
		while (temp != NULL)
		{
			ptr = temp->next;
			ft_lstdelone(temp, del);
			temp = ptr;
		}
		*lst = NULL;
	}
}
