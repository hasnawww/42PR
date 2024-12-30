/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilhasnao <ilhasnao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 16:45:33 by ilhasnao          #+#    #+#             */
/*   Updated: 2024/12/27 16:21:42 by ilhasnao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "../push_swap.h"

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
