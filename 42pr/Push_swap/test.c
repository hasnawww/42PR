/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilhasnao <ilhasnao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 16:45:33 by ilhasnao          #+#    #+#             */
/*   Updated: 2024/12/20 17:40:09 by ilhasnao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

typedef struct s_stack
{
	char	data;
	struct s_stack	*next;
}	b_list;

void list_swap(b_list *list)
{
	b_list	*swap;

	swap = malloc(sizeof(b_list));
	printf("avant : %d\n", list->data);
	swap->data = list->data;
	list->data = list->next->data;
	list->next->data = swap->data;
	printf("apres : %d\n", list->data);
	free(swap);
}

int	main()
{
	b_list	*A;
	b_list	*B;
	b_list	*C;
	
	A = malloc(sizeof(b_list));
	B = malloc(sizeof(b_list));
	C = malloc(sizeof(b_list));
	A->data = 'A';
	A->next = B;
	B->data = 'B';
	B->next = C;
	C->data = 'C';
	C->next = NULL;

	list_swap(A);
	free(A);
	free(B);
	free(C);
	return(0);
}