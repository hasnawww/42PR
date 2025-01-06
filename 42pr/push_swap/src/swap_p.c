/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilhasnao <ilhasnao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 22:40:42 by ilhasnao          #+#    #+#             */
/*   Updated: 2025/01/06 06:30:20 by ilhasnao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap_pa(t_nodes *ab)
{
	t_stack	*new;

	if (!ab || !ab->b)
		return ;
	new = ab->b;
	ab->b = new->next;
	new->next = ab->a;
	ab->a = new;
	ft_putstr_fd("pa\n", 1);
}
// {
// 	t_stack	*new;

// 	new = *listb;
// 	if (!new)
// 		return ;
// 	*listb = (*listb)->next;
// 	ft_lstadd_front2(lista, new);
// 	// printf("pa = %ld\n", new->data);
// 	ft_putstr_fd("pa\n", 1);
// }

void	swap_pb(t_nodes *ab)
{
	t_stack	*new;

	if (!ab || !ab->a)
		return ;
	new = ab->a;
	ab->a = new->next;
	new->next = ab->b;
	ab->a = new;
	ft_putstr_fd("pb\n", 1);
}
