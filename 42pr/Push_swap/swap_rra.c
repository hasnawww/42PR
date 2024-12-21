/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_rra.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilhasnao <ilhasnao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 22:22:17 by ilhasnao          #+#    #+#             */
/*   Updated: 2024/12/20 17:40:22 by ilhasnao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	C->data = 9;
	C->next = NULL;
	printf("avant: %d\n", A->data);
	swap_rra(&A);
	printf("apres: %d", A->data);
	return (0);
}
