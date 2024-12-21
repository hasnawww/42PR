/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilhasnao <ilhasnao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 14:31:46 by ilhasnao          #+#    #+#             */
/*   Updated: 2024/11/22 11:23:36 by ilhasnao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>
#include "libftprintf.h"
#include <stdio.h>

// 	int	ft_verif(const char	*format, va_list ap)
// {
// 	int	count;

// 	count = 0;
// 	if (*format == 's')
// 	{
// 		count = ft_putstr_len(va_arg(ap, char *));
// 	}
// 	return (count);
// }

int	ft_printf(const char	*format, ...)
{
	va_list	ap;
	va_start(ap, format);
	int	i;
	int	count;
	
	i = 0;
	count = 0;
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			i++;
			if (format[i] == 's')
			{
				ft_putstr_len(va_arg(ap, char *));
			}
			else
			{
				count += write(1, &format[i], i);
			}
		}
		else
		{
			write(1, &format[i], 1);
			count++;
		}
		i++;
	}
	va_end(ap);
	return (count);
}

#include <stdio.h>
int	main (void)
{
	const char	*format = "zongoledozo";

	// printf("%s", format);
	ft_printf("%s", format);
	return (0);
}
