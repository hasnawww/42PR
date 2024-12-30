/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_rra.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilhasnao <ilhasnao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 22:22:17 by ilhasnao          #+#    #+#             */
/*   Updated: 2024/12/30 23:59:41 by ilhasnao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void swap_rra(t_stack **list)
{
	t_stack *current;
	t_stack *second_last;
	
	printf("ouiuioi\n");
	if (!list || !*list || !(*list)->next)
		return;
	current = *list;
	while (current->next->next != NULL)
		current = current->next;
	second_last = current;
	current = current->next;
	second_last->next = NULL;
	current->next = *list;
	*list = current;
	// ft_putstr_fd("rra\n", 1);
}

