/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilhasnao <ilhasnao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 10:46:43 by ilhasnao          #+#    #+#             */
/*   Updated: 2024/12/15 19:29:18 by ilhasnao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

b_list	*ft_lstmap(b_list *lst, void *(*f)(void *), void (*del)(void *))
{
	b_list	*new_elem;
	b_list	*new_list;
	b_list	*last;

	new_list = NULL;
	last = NULL;
	while (lst)
	{
		new_elem = malloc(sizeof(b_list));
		if (!new_elem)
		{
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		new_elem->content = f(lst->content);
		new_elem->next = NULL;
		if (!new_list)
			new_list = new_elem;
		else
			last->next = new_elem;
		last = new_elem;
		lst = lst->next;
	}
	return (new_list);
}
