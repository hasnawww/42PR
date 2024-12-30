/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_sa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilhasnao <ilhasnao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 20:44:32 by ilhasnao          #+#    #+#             */
/*   Updated: 2024/12/30 23:47:30 by ilhasnao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <stdlib.h>

void	*swap_sa(t_stack **list)
{
	t_stack	*temp;
	
	if (!list || (*list)->next == NULL)
		return (NULL);
	temp = malloc(sizeof(t_stack));
	if(!temp)
		return (NULL);
	if (lstsize(*list) > 1)
	{
		temp->data = (*list)->data;
		(*list)->data = (*list)->next->data;
		(*list)->next->data = temp->data;
	}
	free(temp);
	// ft_putstr_fd("sa\n", 1);
	return (NULL);
}
