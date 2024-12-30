/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilhasnao <ilhasnao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 02:50:06 by ilhasnao          #+#    #+#             */
/*   Updated: 2024/12/30 22:37:36 by ilhasnao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_five(t_stack **a, t_stack **b)
{
	push_smallest(a, b);
	push_smallest(a, b);
	if (!already_sorted(a))
		sort_three(a);
	swap_pa(a, b);
	swap_pa(a, b);
}

