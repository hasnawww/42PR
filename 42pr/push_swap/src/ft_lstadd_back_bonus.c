/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilhasnao <ilhasnao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 11:01:14 by ilhasnao          #+#    #+#             */
/*   Updated: 2025/01/06 03:43:31 by ilhasnao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_lstaddback(t_nodes *ab, t_stack *new)
{
	t_stack	*temp;

	if (!ab)
		return ;
	temp = ab->a;
	while (temp->next)
		temp = temp->next;
	temp->next = new;
}
