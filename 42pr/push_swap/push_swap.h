/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilhasnao <ilhasnao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 20:45:16 by ilhasnao          #+#    #+#             */
/*   Updated: 2025/01/08 23:11:50 by ilhasnao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include "libft/libft.h"
# include "limits.h"

# define ERROR -214748364888

typedef struct s_stack
{
	long			data;
	long			index;
	struct s_stack	*next;
}	t_stack;

int		lstsize(t_stack *list);
void	swap_pa(t_stack **lista, t_stack **listb);
void	swap_pb(t_stack **lista, t_stack **listb);
void	swap_ra(t_stack **list);
void	swap_rra(t_stack **list);
void	swap_sa(t_stack **list);
void	sort_three(t_stack **a);
int		already_sorted(t_stack **a);
void	sort_four(t_stack **a, t_stack **b);
t_stack	*ft_lstnew(int data);
t_stack	*ft_lstlast(t_stack *lst);
void	ft_lstadd_back(t_stack **lst, t_stack *new);
void	ft_fill(t_stack **a, char **av, int ac);
void	print_stack(t_stack *a);
void	sort_five(t_stack **a, t_stack **b);
void	push_smallest(t_stack **a, t_stack **b);
int		find_smallest(t_stack **list);
void	swap_rrb(t_stack **list);
void	swap_rb(t_stack **list);
int		find_min_index(t_stack **list, int index);
void	print_stack(t_stack *a);
void	print_binary(int n);
void	print_index(t_stack *stack);
void	index_stack(t_stack **a);
int		get_min(t_stack **a, int data);
void	ft_lstadd_front2(t_stack **lst, t_stack *new);
void	dree_split(char **result);
void	radix_sort(t_stack **a, t_stack **b);
int		number_of_bits(t_stack **a);
void	ft_sprocess(t_stack **a, char **av, int ac);
void	free_lbail(t_stack **a);
void	show_error(t_stack **a, t_stack **b);
int		has_duplicate(char **av, int num, int i);
int		is_num(char *str);
void	validate_arg(char **av, int ac, t_stack **a, t_stack **b);
void	algo(t_stack **a, t_stack **b);
void	sort_two(t_stack **a);
long	ft_atol(const char *str);

#endif