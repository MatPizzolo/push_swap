/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpizzolo <mpizzolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 19:39:06 by mpizzolo          #+#    #+#             */
/*   Updated: 2023/03/18 13:11:22 by mpizzolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../push_swap.h"

void	ft_lstiter(t_list *lst, void (*f)(int))
{
	t_list	*temp;

	if (lst || f)
	{
		temp = lst;
		while (temp != NULL)
		{
			f(temp->content);
			temp = temp->next;
		}
	}
}
