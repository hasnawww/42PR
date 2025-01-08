/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasnawww <hasnawww@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 01:11:46 by hasnawww          #+#    #+#             */
/*   Updated: 2025/01/08 02:26:01 by hasnawww         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	find_smallest(t_stack **list)
{
	int		smallest;
	t_stack	*temp;

	temp = *list;
	smallest = temp->data;
	while (temp)
	{
		if (temp->data < smallest)
			smallest = temp->data;
		temp = temp->next;
	}
	return (smallest);
}

int	find_min_index(t_stack **list, int index)
{
	t_stack	*temp;
	int	pos;

	pos = 0;
	temp = *list;
	while (temp)
	{
		if (temp->data == index)
			return(pos);
		pos++;
		temp = temp->next;
	}
	return (-1);
}

void push_smallest(t_stack **a, t_stack **b)
{
	int smallest;
	int pos;

	smallest = find_smallest(a);
	pos = find_min_index(a, smallest);
	if (pos <= lstsize(*a)/2)
	{
		while ((*a)->data != smallest)
			swap_ra(a);
	}
	else
	{
		while ((*a)->data != smallest)
		{
			swap_rra(a);
		}
	}
	swap_pb(a, b);
}

int	get_min(t_stack **a, int data)
{
	t_stack	*temp;
	int		i;

	temp = *a;
	i = 0;
	while (temp)
	{
		if (data > temp->data)
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
