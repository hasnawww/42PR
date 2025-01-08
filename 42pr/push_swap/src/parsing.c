/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasnawww <hasnawww@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 16:01:37 by ilhasnao          #+#    #+#             */
/*   Updated: 2025/01/08 03:45:24 by hasnawww         ###   ########.fr       */
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

void	show_error(void)
{
	ft_putstr_fd("Error\n", 1);
	exit(0);
}

int	has_duplicate(char **av)
{
	int	i;
	int	j;

	i = 1;
	while (av[i])
	{
		j = i + 1;
		while (av[j])
		{
			if (ft_atoi(av[i]) == ft_atoi(av[j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	is_num(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

void	validate_arg(char **av, int ac)
{
	int	i;
	int	value;
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
		value = ft_atoi(result[i]);
		if (value < INT_MIN || value > INT_MAX)
			show_error();
		if (has_duplicate(result))
			show_error();
		if (!is_num(result[i]))
			show_error();
		i++;
	}
	if (ac == 2)
		dree_split(result);
}
