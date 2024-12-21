/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilhasnao <ilhasnao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 07:31:32 by ilhasnao          #+#    #+#             */
/*   Updated: 2024/12/15 19:29:18 by ilhasnao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

b_list	*ft_lstnew(void *content)
{
	b_list	*new_element;

	new_element = malloc(sizeof(b_list));
	if (!new_element)
	{
		return (NULL);
	}
	new_element->content = content;
	new_element->next = NULL;
	return (new_element);
}
