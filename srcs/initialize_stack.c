/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpizzolo <mpizzolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 12:12:43 by mpizzolo          #+#    #+#             */
/*   Updated: 2023/05/20 15:36:23 by mpizzolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	check_no_nbr_in_str(char *str)
{
	int	i;
	int	check_nbr;

	i = -1;
	check_nbr = 0;
	while (str[++i])
	{
		if ((str[i] >= 48 && str[i] <= 57))
			check_nbr++;
	}
	if (check_nbr)
		return (1);
	else
		return (0);
}

int	check_add(char *str, t_list **stack, int i)
{
	t_list	*new;
	int		nbr;
	int		err;

	nbr = ft_atoi_err(str, &err);
	if (!ft_checks(str) || !err)
		return (0);
	new = ft_lstnew(nbr, i);
	ft_lstadd_back(stack, new);
	return (1);
}

void	free_matrix(char **matrix)
{
	int	i;

	i = -1;
	while (matrix[++i])
		free(matrix[i]);
	free(matrix);
}

int	check_multiple_numbers(t_list **stack_a, char *str, int index)
{
	char	**numbers;
	int		z;

	if (!check_no_nbr_in_str(str))
		return (0);
	numbers = ft_split(str, ' ');
	z = -1;
	while (numbers[++z])
	{
		if (!check_add(numbers[z], stack_a, index++))
			return (free_matrix(numbers), 0);
	}
	return (free_matrix(numbers), 1);
}

int	initialize_stack(t_list **stack_a, int argc, char **argv)
{
	int		i;

	i = 0;
	while (++i <= argc - 1)
	{
		if (!(ft_strrchr(argv[i], ' ')))
		{
			if (!check_add(argv[i], stack_a, (i - 1)))
				return (0);
		}
		else
		{
			if (!check_multiple_numbers(stack_a, argv[i], (i - 1)))
				return (0);
		}
	}
	return (1);
}
