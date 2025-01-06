/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_hundred.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilhasnao <ilhasnao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 22:38:47 by ilhasnao          #+#    #+#             */
/*   Updated: 2025/01/05 03:02:47 by ilhasnao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// int	get_min(t_stack **list, int chunk_index, int chunk_size)
// {
// 	int	smallest;
// 	t_stack	*temp;
// 	int	limit_low;
// 	int	upper_limit;
	
// 	temp = *list;
// 	limit_low = (chunk_index - 1) * chunk_size;
// 	upper_limit = chunk_index * chunk_size;
// 	smallest = temp->data;
// 	while (temp)
// 	{
// 		if (temp->data >= limit_low && temp->data < upper_limit)
// 		{
// 			if (temp->data < smallest)
// 				smallest = temp->data;
// 		}
// 		temp = temp->next;
// 	}
// 	return (smallest);
// }

// int	get_max(t_stack **list, int chunk_index, int chunk_size)
// {
// 	int	max;
// 	t_stack	*temp;
// 	int	limit_low;
// 	int	upper_limit;
	
// 	temp = *list;
// 	limit_low = (chunk_index - 1) * chunk_size;
// 	upper_limit = chunk_index * chunk_size;
// 	max = temp->data;
// 	while (temp)
// 	{
// 		if (temp->data >= limit_low && temp->data < upper_limit)
// 		{
// 			if (temp->data > max)
// 				max = temp->data;
// 		}
// 		temp = temp->next;
// 	}
// 	return (max);
// }

int	get_chunk_numbers(int size)
{
	if (size <= 50)
		return (5);
	else if (size <= 200)
		return (size / 20 + 2);
	else
		return (size / 25 + 5);
}

// void push_small(t_stack **a, t_stack **b)
// {
// 	int	smallest;
// 	t_stack	*temp;
	
// 	temp = *a;
// 	smallest = find_smallest(a);
// 	while (temp)
// 	{
// 		if (temp->data == smallest)
// 		{
// 			swap_pb(a, b);
// 			return;
// 		}
// 		temp = temp->next;
// 	}
// }
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
		while ((*a)->data != smallest)
		{
			swap_rra(a);
		}
	}
	swap_pb(a, b);
}

void	sort_numbers(t_stack **a, t_stack **b)
{
	int	size; 
	int	chunk_count;
	int	chunk_size;
	int	chunk_index;
	int	remaining_size;
	int	current_chunk_size;

	size = lstsize(*a);
	chunk_count = get_chunk_numbers(size);
	chunk_size = size / chunk_count;
	chunk_index = 1;
	while (lstsize(*a) > 0)
	{
		remaining_size = lstsize(*a);
		current_chunk_size = chunk_size;
		if (remaining_size < chunk_size)
			current_chunk_size = remaining_size;
		while (lstsize(*a) > 0 && current_chunk_size > 0)
		{
			push_smallest(a, b);
			current_chunk_size--;
		}
		chunk_index++;
	}
	while (lstsize(*b) > 0)
		swap_pa(a, b);
}

// void sort_numbers(t_stack **a, t_stack **b)
// {
// 	t_stack *tempa;
// 	// t_stack *tempb;

// 	tempa= *a;
// 	ft_putstr_fd("jousuila\n", 1);
// 	while ((*a))
// 	{
// 		push_smallest(a, b);
// 	}
// 	while ((*b))
// 	{
// 		swap_pa(a, b);
// 	}
// }

// void sort_hundred(t_stack **a, t_stack **b)
// {
// 	int	size;
// 	int	number_of_chunks;
// 	int	chunks_count;
// 	int	*chunks;
// 	int	i;

// 	number_of_chunks = size / chunks_count;
// 	chunks = malloc(sizeof(int) * chunks_count);
// 	i = 0;
// 	chunks_count = 5;
// 	while (i < chunks_count)
// 	{
		
// 	} 

// }