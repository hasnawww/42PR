/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilhasnao <ilhasnao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 20:53:12 by ilhasnao          #+#    #+#             */
/*   Updated: 2024/12/20 17:40:22 by ilhasnao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	main()
{
	t_stack *A;
	t_stack *B;
	t_stack *C;

	A = malloc(sizeof(t_stack));
	B = malloc(sizeof(t_stack));
	C = malloc(sizeof(t_stack));
	A->next = B;
	B->next = C;
	C->next = NULL;
	printf("%d", lstsize(A));
	return (0);
}
