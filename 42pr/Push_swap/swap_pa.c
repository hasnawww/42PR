/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_pa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilhasnao <ilhasnao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 22:40:42 by ilhasnao          #+#    #+#             */
/*   Updated: 2024/12/20 17:40:22 by ilhasnao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstadd_front2(t_stack **lst, t_stack *new)
{
	if (!new || !lst)
		return ;
	new->next = *lst;
	*lst = new;
}

void	swap_pa(t_stack **lista, t_stack **listb)
{
	t_stack	*new;

	new = *listb;
	if (!new)
		return ;
	*listb = (*listb)->next;
	ft_lstadd_front(lista, new);
}

int	main()
{
	t_stack *A;
	t_stack *B;
	t_stack *C;
	t_stack *D;
	t_stack *E;
	t_stack *F;

	A = malloc(sizeof(t_stack));
	B = malloc(sizeof(t_stack));
	C = malloc(sizeof(t_stack));
	A->data = 7;
	A->next = B;
	B->data = 5;
	B->next = C;
	C->next = NULL;
	D = malloc(sizeof(t_stack));
	E = malloc(sizeof(t_stack));
	F = malloc(sizeof(t_stack));
	D->data = 9;
	D->next = E;
	E->data = 5;
	E->next = F;
	F->data = 4;
	F->next = NULL;
	printf("avant: %d\n", A->data);
	swap_pa(&A, &D);
	printf("apres: %d", A->data);
	return (0);
}
