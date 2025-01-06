/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilhasnao <ilhasnao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 02:46:35 by ilhasnao          #+#    #+#             */
/*   Updated: 2025/01/05 22:22:40 by ilhasnao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	big_sort(t_stack **a, t_stack **b)
{
	int	size;
	int	*array;

	size = lstsize(*a);
	array = sorted_array(a, size);
	if (!array)
		return;
	assign_index(a, array, size);
	rush_b(a, b);
	while(*b)
	{
	calculate_moves(b, array, size);
	best_node(a, b);
	}
	final_rotation(a);
	free(array);
}
