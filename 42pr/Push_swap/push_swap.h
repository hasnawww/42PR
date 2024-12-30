/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilhasnao <ilhasnao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 20:45:16 by ilhasnao          #+#    #+#             */
/*   Updated: 2024/12/30 02:53:37 by ilhasnao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "libft/libft.h"
#include "limits.h"

typedef struct s_stack
{
	long	data;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

int	lstsize(t_stack *list);
void	*lstcmp(t_stack *list);
void	ft_lstadd_front2(t_stack **lst, t_stack *new);
void	swap_pa(t_stack **lista, t_stack **listb);
void	swap_pb(t_stack **lista, t_stack **listb);
void	swap_ra(t_stack **list);
void swap_rra(t_stack **list);
void	*swap_sa(t_stack **list);
void sort_three(t_stack **a);
int	already_sorted(t_stack **a);
void sort_four(t_stack **a, t_stack **b);
t_stack	*ft_lstnew(int data);
void	ft_lstadd_back(t_stack **lst, t_stack *new);
void	ft_fill(t_stack **a, char **av);
void	print_stack(t_stack *a);
void	sort_five(t_stack **a, t_stack **b);
void push_smallest(t_stack **a, t_stack **b);
int	adress_to(t_stack **list, int index);
int	find_smallest(t_stack **list);

#endif