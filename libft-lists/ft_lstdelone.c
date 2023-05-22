/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpizzolo <mpizzolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 18:50:27 by mpizzolo          #+#    #+#             */
/*   Updated: 2023/05/06 11:32:22 by mpizzolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../push_swap.h"

void	ft_lstdelone(t_list *lst, void (*del)(int))
{
	if (lst && del)
	{
		del(lst->content);
		free(lst);
	}
}
