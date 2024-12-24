/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilhasnao <ilhasnao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 20:45:16 by ilhasnao          #+#    #+#             */
/*   Updated: 2024/12/23 18:46:34 by ilhasnao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "libft/libft.h"

typedef struct s_stack
{
	int	data;
	struct s_stack	*next;
}	t_stack;

int	lstsize(t_stack *list);
void	*lstcmp(t_stack *list);
void	ft_lstadd_front2(t_stack **lst, t_stack *new);
void	swap_pa(t_stack **lista, t_stack **listb);
void	swap_ra(t_stack **list);
void swap_rra(t_stack **list);
void	*swap_sa(t_stack **list);

#endif