/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilhasnao <ilhasnao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 19:03:17 by ilhasnao          #+#    #+#             */
/*   Updated: 2024/12/23 19:12:08 by ilhasnao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_sstrlen(char *list)
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
	count = 0;
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
		if (count == ft_sstrlen(list))
			return (1);
		i++;
	}
	return (0);
}

t_stack	*assign(t_stack *a, int new_data)
{
	t_stack *node;
	t_stack	*temp;

	node = malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->data = new_data;
	node->next = NULL;
	if (!a)
		return (node);
	temp = a;
	while (temp->next)
		temp = temp->next;
	temp->next = node;
	return (a);
}

void	print_stack(t_stack *a)
{
	while(a)
	{
		ft_putnbr_fd(a->data, 2);
		write(1, "\n", 1);
		a = a->next;
	}
}

void	free_lbail(t_stack *a)
{
	t_stack	*temp;
	while (a)
	{
		temp = a;
		a = a->next;
		free(temp);
	}
}

int	main(int ac, char **av)
{
	int	i;
	t_stack *a;
	
	i = 1;
	a = NULL;
	while (i < ac)
	{
		if (!valid_input(av[i]))
		{
			ft_putstr_fd("mais cv pas ou quoi\n", 2);
			free_lbail(a);
			return (1);
		}
		a = assign(a, ft_atoi(av[i]));
		i++;
	}
	print_stack(a);
	free_lbail(a);
	return (0);
}
