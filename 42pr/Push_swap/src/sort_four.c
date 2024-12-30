/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_four.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilhasnao <ilhasnao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 23:36:32 by ilhasnao          #+#    #+#             */
/*   Updated: 2024/12/30 23:56:09 by ilhasnao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	find_smallest(t_stack **list)
{
	int	smallest;
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

int	adress_to(t_stack **list, int index)
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
	return (0);
}

void push_smallest(t_stack **a, t_stack **b)
{
	int smallest;
	int pos;

	smallest = find_smallest(a);
	pos = adress_to(a, smallest);
	if (pos <= lstsize(*a)/2)
	{
		while ((*a)->data != smallest)
			swap_ra(a);
	}
	else
	{
		// printf("jousuila");
		while ((*a)->data != smallest)
		{
			printf("value a->data = %ld\n", (*a)->data);
			swap_rra(a);
		}
	}
	// printf("value a = %ld\n", (*a)->data);
	swap_pb(a, b);
}

void sort_four(t_stack **a, t_stack **b)
{
	push_smallest(a, b);
	if (!already_sorted(a))
		sort_three(a);
	swap_pa(a, b);
}
