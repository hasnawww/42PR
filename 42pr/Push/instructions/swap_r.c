/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_r.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasnawww <hasnawww@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 03:07:42 by ilhasnao          #+#    #+#             */
/*   Updated: 2025/01/08 01:11:50 by hasnawww         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap_ra(t_stack **a)
{
	t_stack	*begin;
	t_stack	*last;

	if (lstsize(*a) < 2)
		return ;
	begin = *a;
	last = ft_lstlast(begin);
	*a = begin->next;
	begin->next = NULL;
	last->next = begin;
	ft_putstr_fd("ra\n", 1);
}

void	swap_rb(t_stack **b)
{
	t_stack	*begin;
	t_stack	*last;

	if (lstsize(*b) < 2)
		return ;
	begin = *b;
	last = ft_lstlast(begin);
	*b = begin->next;
	begin->next = NULL;
	last->next = begin;
	ft_putstr_fd("rb\n", 1);
}
