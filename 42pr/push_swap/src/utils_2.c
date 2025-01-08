/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilhasnao <ilhasnao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 03:43:15 by hasnawww          #+#    #+#             */
/*   Updated: 2025/01/08 19:43:13 by ilhasnao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	number_of_bits(t_stack **a)
{
	int		i;
	int		max;
	t_stack	*temp;

	if (!a)
		return (0);
	temp = *a;
	max = temp->index;
	i = 0;
	while (temp)
	{
		if (temp->index > max)
			max = temp->index;
		temp = temp->next;
	}
	while (max >> i != 0)
		i++;
	return (i);
}

void	dree_split(char **result)
{
	int	i;

	i = 0;
	while (result[i])
		free(result[i++]);
	free(result);
}

void	ft_sprocess(t_stack **a, char **av, int ac)
{
	char	**result;

	result = ft_split(av[1], ' ');
	ft_fill(a, result, ac);
	dree_split(result);
}

void	ft_fill(t_stack **a, char **av, int ac)
{
	int	i;

	if (ac > 2)
		i = 1;
	else
	{
		i = 0;
	}
	while (av[i])
		ft_lstadd_back(a, ft_lstnew(ft_atoi(av[i++])));
}

void	free_lbail(t_stack **a)
{
	t_stack	*temp;

	while (*a)
	{
		temp = *a;
		*a = (*a)->next;
		free(temp);
	}
	free (a);
}
