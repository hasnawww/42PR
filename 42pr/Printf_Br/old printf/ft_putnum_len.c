/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnum_len.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilhasnao <ilhasnao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 09:51:03 by ilhasnao          #+#    #+#             */
/*   Updated: 2024/11/22 08:59:47 by ilhasnao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libftprintf.h"

int	ft_putnbr_len(int	nb)
{
	char	c;
	int		i;
	
	i = num_len_ten(nb);
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (nb < 0)
	{
		write(1, "-", 1);
		nb = -nb;
	}
	if (nb >= 10)
	{
		ft_putnbr_len(nb / 10);
		nb = nb % 10;
	}
	c = nb + '0';
	write(1, &c, 1);
	return(i);
}

int	ft_uputnbr_len(unsigned int	nb)
{
	char	c;
	int		i;
	
	i = num_len_ten(nb);
	if (nb >= 10)
	{
		ft_uputnbr_len(nb / 10);
		nb = nb % 10;
	}
	c = nb + '0';
	write(1, &c, 1);
	return(i);
}
