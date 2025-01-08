/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasnawww <hasnawww@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 03:35:52 by hasnawww          #+#    #+#             */
/*   Updated: 2025/01/08 03:48:53 by hasnawww         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void sort_two(t_stack **a)
{
    t_stack	*temp;

    temp = *a;
    if (temp->data > temp->next->data)
        swap_sa(a);
}

void sort_three(t_stack **a)
{
	t_stack	*temp;

	temp = *a;
	if (temp->data > temp->next->data 
		&& temp->data < temp->next->next->data)
		swap_sa(a);
	else if (temp->data > temp->next->data
		&& temp->data > temp->next->next->data)
	{
		swap_sa(a);
		swap_rra(a);
	}
	else if (temp->data > temp->next->data
		&& temp->next->data < temp->next->next->data)
		swap_ra(a);
	else if (temp->data < temp->next->data
		&& temp->data < temp->next->next->data)
	{
		swap_sa(a);
		swap_ra(a);
	}
	else if (temp->data < temp->next->data
		&& temp->data > temp->next->next->data)
		swap_rra(a);
}

void sort_four(t_stack **a, t_stack **b)
{
	push_smallest(a, b);
	if (!already_sorted(a))
		sort_three(a);
	swap_pa(a, b);
}

void	sort_five(t_stack **a, t_stack **b)
{
	push_smallest(a, b);
	push_smallest(a, b);
	if (!already_sorted(a))
		sort_three(a);
	swap_pa(a, b);
	swap_pa(a, b);
}

void	radix_sort(t_stack **a, t_stack **b)
{
	t_stack	*first;
	int		i;
	int		j;
	int		size;
	int		max_bits;

	i = 0;
	first = *a;
	size = lstsize(first);
	max_bits = number_of_bits(a);
	while (i < max_bits)
	{
		j = 0;
		while (j++ < size)
		{
			first = *a;
			if (((first->index >> i) & 1) == 1)
				swap_ra(a);
			else
				swap_pb(a, b);
		}
		while (lstsize(*b) != 0)
			swap_pa(a, b);
		i++;
	}
}
