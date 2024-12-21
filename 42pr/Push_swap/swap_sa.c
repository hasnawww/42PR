/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_sa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilhasnao <ilhasnao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 20:44:32 by ilhasnao          #+#    #+#             */
/*   Updated: 2024/12/20 17:40:22 by ilhasnao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

int	lstsize(t_stack *lst)
{
	int		i;

	i = 0;
	while(lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

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
		if ((*list)->data > (*list)->next->data)
		{
			temp->data = (*list)->data;
			(*list)->data = (*list)->next->data;
			(*list)->next->data = temp->data;
		}
	}
	return (NULL);
}

int	main()
{
	t_stack *A;
	t_stack *B;
	t_stack *C;

	A = malloc(sizeof(t_stack));
	B = malloc(sizeof(t_stack));
	C = malloc(sizeof(t_stack));
	A->data = 7;
	A->next = B;
	B->data = 5;
	B->next = C;
	C->next = NULL;
	printf("avant: %d", A->data);
	swap_sa(&A);
	printf("apres: %d", A->data);
	return (0);
}
