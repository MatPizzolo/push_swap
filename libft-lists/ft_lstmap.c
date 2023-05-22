/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpizzolo <mpizzolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 19:46:25 by mpizzolo          #+#    #+#             */
/*   Updated: 2023/03/18 13:17:10 by mpizzolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../push_swap.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(int))
{
	t_list	*temp;
	t_list	*result;
	int		i;

	if (!lst || !f || !del)
		return (NULL);
	result = 0;
	i = 0;
	while (lst)
	{
		temp = ft_lstnew(f(lst->content), i);
		i++;
		if (!temp)
		{
			ft_lstclear(&result, del);
			return (NULL);
		}
		ft_lstadd_back(&result, temp);
		lst = lst->next;
	}
	return (result);
}
