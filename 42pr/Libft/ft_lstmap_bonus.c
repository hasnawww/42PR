/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilhasnao <ilhasnao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 10:46:43 by ilhasnao          #+#    #+#             */
/*   Updated: 2024/11/16 13:41:03 by ilhasnao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_elem;
	t_list	*new_list;
	t_list	*last;

	new_list = NULL;
	last = NULL;
	while (lst)
	{
		new_elem = malloc(sizeof(t_list));
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
