/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilhasnao <ilhasnao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 09:33:00 by ilhasnao          #+#    #+#             */
/*   Updated: 2025/02/11 16:56:03 by ilhasnao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(const char *c)
{
	int	i;

	i = 0;
	while (c[i] != '\0')
	{
		if (c[i] == '\n')
			break;
		i++;
	}
	return (i);
}

// int	main(void)
// {
// 	char	oui[] = "dewd";
// 	printf("%zu",ft_strlen (oui));
// 	return (0);
// }
