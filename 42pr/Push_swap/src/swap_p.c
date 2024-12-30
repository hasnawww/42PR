/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilhasnao <ilhasnao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 22:40:42 by ilhasnao          #+#    #+#             */
/*   Updated: 2024/12/30 23:47:39 by ilhasnao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap_pa(t_stack **lista, t_stack **listb)
{
	t_stack	*new;

	new = *listb;
	if (!new)
		return ;
	*listb = (*listb)->next;
	ft_lstadd_front2(lista, new);
	// ft_putstr_fd("pa\n", 1);
}

void	swap_pb(t_stack **lista, t_stack **listb)
{
	t_stack	*new;

	new = *lista;
	if (!new)
		return ;
	*lista = (*lista)->next;
	ft_lstadd_front2(listb, new);
	// ft_putstr_fd("pb\n", 2);
}
