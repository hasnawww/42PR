/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilhasnao <ilhasnao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 11:04:13 by ilhasnao          #+#    #+#             */
/*   Updated: 2024/11/25 08:28:16 by ilhasnao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex_len_maj(unsigned int nb)
{
	char	c;
	int		count;

	count = num_hex_len(nb);
	if (nb >= 16)
	{
		ft_puthex_len_maj(nb / 16);
	}
	nb = nb % 16;
	if (nb < 10)
	{
		c = nb + '0';
	}
	else
	{
		c = nb - 10 + 'A';
	}
	write(1, &c, 1);
	return (count);
}

int	ft_puthex_len_min(unsigned long nb)
{
	char	c;
	int		count;

	count = num_hex_len(nb);
	if (nb >= 16)
	{
		ft_puthex_len_min(nb / 16);
	}
	nb = nb % 16;
	if (nb < 10)
	{
		c = nb + '0';
	}
	else
	{
		c = nb - 10 + 'a';
	}
	write(1, &c, 1);
	return (count);
}
