/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasnawww <hasnawww@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 19:03:17 by ilhasnao          #+#    #+#             */
/*   Updated: 2025/01/07 06:41:34 by hasnawww         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_slistlen(char *list)
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

// int	valid_input(char *list)
// {
// 	char	*input;
// 	int	i;
// 	int j;
// 	int	count;

// 	j = 0;
// 	i = 0;
// 	count = 0;
// 	input = "-+0123456789";
// 	while (list[i++])
// 	{
// 		j = 0;
// 		while (input[j++])
// 		{
// 			if (list[i] == input[j])
// 			{
// 				count++;
// 				break;
// 			}
// 		}
// 		if (count == ft_slistlen(list))
// 			return (1);
// 		i++;
// 	}
// 	return (0);
// }

int	valid_input(char *list)
{
	int		i;

	i = 0;
	while (list[i])
	{
		if (list[i] >= '0' && list[i] <= '9')
			i++;
		else if (list[i] == '-' || list[i] == '+' || list[i] == ' ')
			i++;
		else
		{
			ft_putstr_fd("bomboclaat\n", 2);
			return (-1);
		}
	}
	return (1);
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
	{
		return (node);
	}
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
		ft_putnbr_fd(a->index, 2);
		write(1, "\n", 1);
		a = a->next;
	}
}

void	ft_fill(t_stack **a, char **av)
{
	int	i;

	i = 0;
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

void	dree_split(char **result)
{
	int	i;

	i = 0;
	while (result[i])
		free(result[i++]);
	free(result);
}
void	ft_sprocess(t_stack **a, char **av)
{
	char	**result;
	
	result = ft_split(av[1], ' ');
	ft_fill(a, result);
	dree_split(result);
}

int	get_min(t_stack **a, int data)
{
	t_stack	*temp;
	int		i;

	temp = *a;
	i = 0;
	while (temp)
	{
		if (data >= temp->data)
			i++;
		temp = temp->next;
	}
	return (i);
}

void	index_stack(t_stack **a)
{
	int		i;
	int		index;
	int		size;
	t_stack	*temp;

	if (!a || !*a)
		return ;
	i = 1;
	size = lstsize(*a);
	temp = *a;
	while (temp && i < size + 1)
	{
		index = get_min(a, temp->data);
		temp->index = index;
		temp = temp->next;
		i++;
	}
}

int	main(int ac, char **av)
{
	// int	i;
	t_stack	**a;
	// t_stack	*b;

	// i = 1;
	a = malloc(sizeof(t_stack *));
	// b = malloc(sizeof(t_stack *));
	if (!a)
		return (0);
	*a = NULL;
	// *b = NULL;
	if (ac == 1 || (ac == 2 && !av[1][0]))
	{
		ft_putstr_fd("you're just a chill guy who forgot the input :)\n", 2);
		return (0);
	}
	if (ac == 2)
		ft_sprocess(a, av);
	else
		ft_fill(a, av);
	write(1, "old_list : ", 11);
	index_stack(a);
	print_stack(*a);
	// big_sort(&a, &b);
	// write(1, "new_list : ", 11);
	// print_stack(a);
	free_lbail(a);
	// free_lbail(&b);
	return (0);
}
