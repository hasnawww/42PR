/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putvoid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilhasnao <ilhasnao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 08:17:16 by ilhasnao          #+#    #+#             */
/*   Updated: 2024/11/22 08:56:59 by ilhasnao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libftprintf.h"

int	ft_putvoid(int	nb)
{
	// void	*ptr;
	int		i;
	
	i = 0;
	// ptr = nb;
	if (!nb)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	write(1, "0", 1);
	write(1, "x", 1);
	return (ft_puthex_len_min(nb) + 2);
}