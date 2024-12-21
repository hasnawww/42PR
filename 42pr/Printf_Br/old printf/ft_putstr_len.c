/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_len.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilhasnao <ilhasnao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 10:16:42 by ilhasnao          #+#    #+#             */
/*   Updated: 2024/11/22 11:08:38 by ilhasnao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_putstr_len(char	*str)
{
	int	count;

	if (!str)
	{
		str = "(null)";
	}
	count = 0;
	while (str[count])
	{
		write(1, &str[count], 1);
		count++;
	}
	return (count);
}

// int	main (void)
// {
// 	char	st[] = "wojfiewf";
	
// 	ft_putstr_len(st);
// 	return (0);
// }