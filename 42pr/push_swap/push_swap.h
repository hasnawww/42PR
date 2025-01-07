/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilhasnao <ilhasnao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 20:45:16 by ilhasnao          #+#    #+#             */
/*   Updated: 2025/01/06 06:12:14 by ilhasnao         ###   ########.fr       */
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
	long	index;
	struct s_stack	*next;
}	t_stack;

// typedef struct s_nodes
// {
// 	t_stack	*a;
// 	t_stack	*b;
// }	t_nodes;

int	lstsize(t_stack *list);
void	*lstcmp(t_stack *list);
void	ft_lstadd_front2(t_stack **lst, t_stack *new);
void	swap_pa(t_nodes *ab);
void	swap_pb(t_nodes *ab);
void	swap_ra(t_nodes *ab);
void	swap_rra(t_nodes *ab);
void	swap_sa(t_nodes *ab);
void	swap_rrb(t_nodes *ab);
void	swap_rb(t_nodes *ab);
int	already_sorted(t_nodes *ab);
// void	swap_pa(t_stack **lista, t_stack **listb);
// void	swap_pb(t_stack **lista, t_stack **listb);
// void	swap_ra(t_stack **list);
// void swap_rra(t_stack **list);
// void	*swap_sa(t_stack **list);
void sort_three(t_stack **a);
// int	already_sorted(t_stack **a);
void sort_four(t_stack **a, t_stack **b);
t_stack	*ft_lstnew(int data);
void	ft_lstadd_back(t_stack **lst, t_stack *new);
// void	ft_lstaddback(t_nodes *lst, t_stack *new);
void	ft_fill(t_stack **a, char **av);
void	print_stack(t_stack *a);
void	sort_five(t_stack **a, t_stack **b);
void push_smallest(t_stack **a, t_stack **b);
// int	adress_to(t_stack **list, int index);
int	find_smallest(t_stack **list);
// void sort_numbers(t_stack **a, t_stack **b);
void	quicksort(int *array, int start, int end);
int	pivot_index(int	*array, int start, int end);
void	swap(int *a, int *b);
int	*array_dup(t_stack **a);
int	*sorted_array(t_stack **a, int size);
void	best_node(t_stack **a, t_stack **b);
void	calculate_moves(t_stack **b, int *array, int size);
void	assign_pos(t_stack **b);
int	pos_in_c(int *array, int size, int index_b);
void	rush_b(t_stack **a, t_stack **b);
void	assign_index(t_stack **a, int *array, int size);
void	final_rotation(t_stack **a);
void	big_sort(t_stack **a, t_stack **b);
// void swap_rrb(t_stack **list);
// void swap_rb(t_stack **list);
int	find_min_index(t_stack **list, int index);

#endif