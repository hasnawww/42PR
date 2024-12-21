/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilhasnao <ilhasnao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 10:14:35 by ilhasnao          #+#    #+#             */
/*   Updated: 2024/11/22 08:49:19 by ilhasnao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

#include <unistd.h>

int	ft_putnbr_len(int	nb);
int	ft_putstr_len(char	*str);
int	num_len_ten(int	nb);
int	ft_putchar_len(char	c);
int	num_hex_len (int	nb);
int	ft_putvoid(int	nb);
int	ft_putpercent (char	c);
int	ft_uputnbr_len(unsigned int	nb);
int	ft_puthex_len_min(int	nb);
int	ft_puthex_len_maj(int	nb);
int	ft_printf(const char	*format, ...);
// int	ft_verif(char	*format, va_list ap);

# endif