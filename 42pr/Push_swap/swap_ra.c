/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_ra.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilhasnao <ilhasnao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 03:07:42 by ilhasnao          #+#    #+#             */
/*   Updated: 2024/12/20 17:40:22 by ilhasnao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		printf("%d -> ", list->data);
		list = list->next;
	}
	printf("NULL\n");
}

void	swap_ra(t_stack **list)
{
	t_stack *begin;
	t_stack	*temp;
	int first_val;
	
	begin = (*list);
	first_val = begin->data;
	temp = *list;
	printf("avant: %d\n", begin->data);
	while (temp->next)
	{
		printf("pendant: %d\n", begin->data);
		temp->data = temp->next->data;
		if (temp->next->next == NULL)
		{
			temp->next->data = first_val;
			printf("in if: %d\n", begin->data);
			break;
		}
		temp = temp->next;
	}
}

int	main()
{
	t_stack *A;
	t_stack *B;
	t_stack *C;
	
	A = malloc(sizeof(t_stack));
	B = malloc(sizeof(t_stack));
	C = malloc(sizeof(t_stack));
	A->data = 3;
	A->next = B;
	B->data = 2;
	B->next = C;
	C->data = 1;
	C->next = NULL;
	
	printf("Avant: ");
	print_list(A);

	swap_ra(&A);

	printf("Après: ");
	print_list(A);
	free_list(A);
	return (0);
}
