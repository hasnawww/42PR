/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilhasnao <ilhasnao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 14:31:46 by ilhasnao          #+#    #+#             */
/*   Updated: 2024/11/25 08:32:52 by ilhasnao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>
#include "ft_printf.h"

int	ft_format(const char *format, int index, va_list ap)
{
	int	count;

	count = 0;
	if (format[index] == 's')
		count += ft_putstr_len(va_arg(ap, char *));
	if (format[index] == 'd' || format[index] == 'i')
		count += ft_putnbr_len(va_arg(ap, int));
	if (format[index] == 'c')
		count += ft_putchar_len((char)va_arg(ap, int));
	if (format[index] == 'p')
		count += ft_putvoid(va_arg(ap, void *));
	if (format[index] == 'u')
		count += ft_uputnbr_len(va_arg(ap, unsigned int));
	if (format[index] == 'x')
		count += ft_puthex_len_min(va_arg(ap, unsigned int));
	if (format[index] == 'X')
		count += ft_puthex_len_maj(va_arg(ap, unsigned int));
	if (format[index] == '%')
		count += ft_putchar_len('%');
	return (count);
}

int	ft_verif(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i'
		|| c == 'u' || c == 'x' || c == 'X' || c == '%')
	{
		return (1);
	}
	return (0);
}

int	ft_printf(const char	*format, ...)
{
	va_list	ap;
	int		i;
	int		count;

	va_start(ap, format);
	i = 0;
	count = 0;
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			i++;
			if (ft_verif(format[i]))
			{
				count += ft_format(format, i, ap);
			}
		}
		else
		{
			write(1, &format[i], 1);
			count++;
		}
		i++;
	}
	return (count);
}
