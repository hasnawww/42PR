/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_rra.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilhasnao <ilhasnao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 22:22:17 by ilhasnao          #+#    #+#             */
/*   Updated: 2025/01/06 06:26:02 by ilhasnao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void swap_rra(t_stack **list)
{
	t_stack *current;
	t_stack *second_last;
	
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
	ft_putstr_fd("rra\n", 2);
}

void swap_rrb(t_stack **list)
{
	t_stack *current;
	t_stack *second_last;
	
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
	ft_putstr_fd("rrb\n", 2);
}

// void	swap_rra(t_nodes *ab)
// {
// 	t_stack *current;
// 	t_stack *second_last;
	
// 	if (!ab || !ab->a || !ab->a->next)
// 		return;
// 	current = ab->a;
// 	second_last = NULL;
// 	while (current->next->next != NULL)
// 	{
// 		second_last = current;
// 		current = current->next;
// 	}
// 	if (second_last)
// 		second_last->next = NULL;
// 	current->next = ab->a;
// 	ab->a = current;
// 	ft_putstr_fd("rra\n", 2);
// }

// void	swap_rrb(t_nodes *ab)
// {
// 	t_stack *current;
// 	t_stack *second_last;
	
// 	if (!ab || !ab->b || !ab->b->next)
// 		return;
// 	current = ab->b;
// 	second_last = NULL;
// 	while (current->next->next != NULL)
// 	{
// 		second_last = current;
// 		current = current->next;
// 	}
// 	if (second_last)
// 		second_last->next = NULL;
// 	current->next = ab->b;
// 	ab->b = current;
// 	ft_putstr_fd("rra\n", 2);
// }
