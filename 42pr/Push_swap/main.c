/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilhasnao <ilhasnao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 19:03:17 by ilhasnao          #+#    #+#             */
/*   Updated: 2024/12/20 18:16:19 by ilhasnao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strlen(char *list)
{
	int	i;
	
	i = 0;
	while (*list)
	{
		while(*list == 9 || *list == 32)
			list++;
		i++;
		list++;	
	}
	return (i);
}

int	valid_input(char *list)
{
	char	*input;
	int	i;
	int j;
	int	count;

	j = 0;
	i = 0;
	input = "-+0123456789";
	while (list[i++])
	{
		j = 0;
		while (input[j++])
		{
			if (list[i] == input[j])
			{
				count++;
				break;
			}
		}
		if (count = ft_strlen)
			return (1);
		i++;
	}
	return (0);
}

int	main(int ac, char **av)
{
	int	i;
	
	i = 0;
	if (ac = 2)
		ft_split(av[1], " ");
	ft_putstr_fd(av[1], 2);
	swap_sa(av[1]);
	ft_putstr_fd(av[1], 2);
	return (0);
}
