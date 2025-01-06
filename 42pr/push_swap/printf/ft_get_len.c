/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_num_len.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilhasnao <ilhasnao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 09:46:59 by ilhasnao          #+#    #+#             */
/*   Updated: 2024/11/25 08:24:59 by ilhasnao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	num_len_ten(int nb)
{
	int	i;

	i = 0;
	if (nb == 0)
	{
		return (1);
	}
	if (nb < 0)
	{
		nb = -nb;
		i = 1;
	}
	while (nb > 0)
	{
		nb = nb / 10;
		i++;
	}
	return (i);
}

int	num_len_uten(unsigned int nb)
{
	int	i;

	i = 0;
	if (nb == 0)
	{
		return (1);
	}
	while (nb > 0)
	{
		nb = nb / 10;
		i++;
	}
	return (i);
}

int	num_hex_len(unsigned long nb)
{
	int	count;

	count = 0;
	if (nb == 0)
	{
		return (1);
	}
	while (nb > 0)
	{
		nb = nb / 16;
		count++;
	}
	return (count);
}
