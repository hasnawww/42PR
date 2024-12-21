/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpercent.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilhasnao <ilhasnao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 11:46:14 by ilhasnao          #+#    #+#             */
/*   Updated: 2024/11/21 11:54:49 by ilhasnao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <unistd.h>

int	ft_putpercent (char	c)
{
	if (c == '%')
	{
		write(1, "%", 1);
		return (1);
	}
	return (0);
}

// int	main(void)
// {
// 	char	c = '%';

// 	ft_putpercent(c);
// 	return (0);
// }
