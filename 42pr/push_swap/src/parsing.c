/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilhasnao <ilhasnao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 16:01:37 by ilhasnao          #+#    #+#             */
/*   Updated: 2025/01/08 23:13:12 by ilhasnao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	already_sorted(t_stack **a)
{
	t_stack	*temp;

	if (!a || !*a)
		return (1);
	temp = *a;
	while (temp->next)
	{
		if (temp->data > temp->next->data)
			return (0);
		temp = temp->next;
	}
	return (1);
}

void	show_error(t_stack **a, t_stack **b)
{
	free_lbail(a);
	free_lbail(b);
	ft_putstr_fd("Error\n", 1);
	exit(0);
}

int	has_duplicate(char **av, int num, int i)
{
	i++;
	while (av[i])
	{
		if (ft_atoi(av[i]) == num)
			return (1);
		i++;
	}
	return (0);
}

int	is_num(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (!str[i + 1])
			return (0);
		i++;
	}
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

void	validate_arg(char **av, int ac, t_stack **a, t_stack **b)
{
	int		i;
	long	value;
	char	**result;

	i = 0;
	if (ac == 2)
		result = ft_split(av[1], ' ');
	else
	{
		i = 1;
		result = av;
	}
	while (result[i])
	{
		value = ft_atol(result[i]);
		if (value < INT_MIN || value > INT_MAX
			|| (has_duplicate(result, value, i))
			|| !is_num(result[i]))
		{
			if (ac == 2)
				dree_split(result);
			show_error(a, b);
		}
		i++;
	}
}
