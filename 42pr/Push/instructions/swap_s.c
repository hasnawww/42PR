/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilhasnao <ilhasnao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 20:44:32 by ilhasnao          #+#    #+#             */
/*   Updated: 2025/01/08 19:41:51 by ilhasnao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <stdlib.h>

void	swap_sa(t_stack **list)
{
	t_stack	*first;
	t_stack	*sec;
	int		temp;

	if (!list || !*list || !(*list)->next)
		return ;
	first = *list;
	sec = (*list)->next;
	temp = first->data;
	first->data = sec->data;
	sec->data = temp;
	ft_putstr_fd("sa\n", 1);
}

void	swap_sb(t_stack **list)
{
	t_stack	*first;
	t_stack	*sec;
	int		temp;

	if (!list || !*list || !(*list)->next)
		return ;
	first = *list;
	sec = (*list)->next;
	temp = first->data;
	first->data = sec->data;
	sec->data = temp;
	ft_putstr_fd("sb\n", 1);
}
