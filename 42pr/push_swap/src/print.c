/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilhasnao <ilhasnao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 01:07:49 by hasnawww          #+#    #+#             */
/*   Updated: 2025/01/08 19:47:40 by ilhasnao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	print_stack(t_stack *a)
{
	while (a)
	{
		ft_putnbr_fd(a->data, 2);
		write(1, "\n", 1);
		a = a->next;
	}
}

void	print_binary(int n)
{
	unsigned int	mask;

	mask = 1 << (sizeof(int) * 8 - 1);
	while (mask > 0)
	{
		if (n & mask)
			ft_putstr_fd("1", 2);
		else
			ft_putstr_fd("0", 2);
		mask >>= 1;
	}
	ft_putstr_fd("\n", 1);
}

void	print_index(t_stack *stack)
{
	while (stack)
	{
		ft_putnbr_fd(stack->index, 1);
		stack = stack->next;
	}
}
