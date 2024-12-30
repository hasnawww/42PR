/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_ra.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilhasnao <ilhasnao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 03:07:42 by ilhasnao          #+#    #+#             */
/*   Updated: 2024/12/30 02:56:00 by ilhasnao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void free_list(t_stack *list)
{
	t_stack *temp;
	
	while (list)
	{
		temp = list;
		list = list->next;
		free(temp);
	}
}

void print_list(t_stack *list)
{
	while (list)
	{
		ft_putnbr_fd(list->data, 2);
		list = list->next;
	}
	ft_putstr_fd("NULL\n", 2);
}

void	swap_ra(t_stack **list)
{
	t_stack *begin;
	t_stack	*temp;
	int first_val;
	
	begin = (*list);
	first_val = begin->data;
	temp = *list;
	// ft_putnbr_fd(begin->data, 2);
	while (temp->next)
	{
		// ft_putnbr_fd(begin->data, 2);
		temp->data = temp->next->data;
		if (temp->next->next == NULL)
		{
			temp->next->data = first_val;
			// ft_putnbr_fd(begin->data, 2);
			break;
		}
		temp = temp->next;
	}
	ft_putstr_fd("ra\n", 1);
}
