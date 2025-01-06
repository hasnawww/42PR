/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_four.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilhasnao <ilhasnao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 23:36:32 by ilhasnao          #+#    #+#             */
/*   Updated: 2025/01/05 03:58:16 by ilhasnao         ###   ########.fr       */
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

void sort_four(t_stack **a, t_stack **b)
{
	push_smallest(a, b);
	if (!already_sorted(a))
		sort_three(a);
	swap_pa(a, b);
}
