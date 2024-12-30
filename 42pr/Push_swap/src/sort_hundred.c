/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_hundred.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilhasnao <ilhasnao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 22:38:47 by ilhasnao          #+#    #+#             */
/*   Updated: 2024/12/31 00:02:08 by ilhasnao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void sort_numbers(t_stack **a, t_stack **b)
{
	t_stack *tempa;
	// t_stack *tempb;

	tempa= *a;
	ft_putstr_fd("jousuila\n", 1);
	while ((*a))
	{
		push_smallest(a, b);
	}
	while ((*b))
	{
		swap_pa(a, b);
	}
}

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