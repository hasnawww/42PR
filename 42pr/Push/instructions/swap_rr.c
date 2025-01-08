/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_rr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilhasnao <ilhasnao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 22:22:17 by ilhasnao          #+#    #+#             */
/*   Updated: 2025/01/08 19:32:27 by ilhasnao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap_rra(t_stack **ps)
{
	t_stack	*last;
	t_stack	*second_last;

	if (!ps || !*ps || !(*ps)->next)
		return ;
	last = *ps;
	second_last = NULL;
	while (last->next != NULL)
	{
		second_last = last;
		last = last->next;
	}
	if (second_last)
		second_last->next = NULL;
	last->next = *ps;
	*ps = last;
	ft_putstr_fd("rra\n", 1);
}

void	swap_rrb(t_stack **ps)
{
	t_stack	*last;
	t_stack	*second_last;

	if (!ps || !*ps || !(*ps)->next)
		return ;
	last = *ps;
	second_last = NULL;
	while (last->next != NULL)
	{
		second_last = last;
		last = last->next;
	}
	if (second_last)
		second_last->next = NULL;
	last->next = *ps;
	*ps = last;
	ft_putstr_fd("rrb\n", 1);
}
