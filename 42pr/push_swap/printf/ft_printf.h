/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilhasnao <ilhasnao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 10:14:35 by ilhasnao          #+#    #+#             */
/*   Updated: 2024/11/25 08:33:05 by ilhasnao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int	ft_putnbr_len(int nb);
int	ft_putstr_len(char *str);
int	num_len_ten(int nb);
int	ft_putchar_len(char c);
int	num_hex_len(unsigned long nb);
int	ft_putvoid(void *ptr);
int	ft_putpercent(char c);
int	ft_uputnbr_len(unsigned int nb);
int	ft_puthex_len_min(unsigned long nb);
int	ft_puthex_len_maj(unsigned int nb);
int	ft_printf(const char *format, ...);
int	num_len_uten(unsigned int nb);
int	ft_format(const char *format, int index, va_list ap);
int	ft_verif(char c);
int	ft_printf(const char	*format, ...);

#endif