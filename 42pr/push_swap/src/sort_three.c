/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilhasnao <ilhasnao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 17:50:42 by ilhasnao          #+#    #+#             */
/*   Updated: 2025/01/06 06:07:54 by ilhasnao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// int	already_sorted(t_stack **a)
// {
// 	t_stack *temp;

// 	if (!a)
// 		return (1);
// 	if (!(*a))
// 		return (1);
// 	temp = *a;
// 	while (temp->next)
// 	{
// 		if (temp->data > temp->next->data)
// 		{
// 			return (0);
// 		}
// 		temp = temp->next;
// 	}
// 	return (1);
// }

void sort_three(t_stack **a)
{
	t_stack	*temp;

	temp = *a;
	write(1, "Before sorting: ", 17);
	print_stack(*a); 
	if (temp->data > temp->next->data 
		&& temp->data < temp->next->next->data)
	{
		swap_sa(a);
	}
	else if (temp->data > temp->next->data
		&& temp->data > temp->next->next->data)
	{
		swap_sa(a);
		swap_rra(a);
	}
	else if (temp->data > temp->next->data
		&& temp->next->data < temp->next->next->data)
	{
		swap_ra(a);
	}
	else if (temp->data < temp->next->data
		&& temp->data < temp->next->next->data)
	{
		swap_sa(a);
		swap_ra(a);
	}
	else if (temp->data < temp->next->data
		&& temp->data > temp->next->next->data)
	{
		swap_rra(a);
	}
	write(1, "After sorting: ", 16);
	print_stack(*a);
}
