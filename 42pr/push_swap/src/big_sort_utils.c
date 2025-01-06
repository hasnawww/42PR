/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilhasnao <ilhasnao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 23:53:41 by ilhasnao          #+#    #+#             */
/*   Updated: 2025/01/06 03:51:33 by ilhasnao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	assign_index(t_stack **a, int *array, int size)
{
	t_stack	*temp;
	int		i;
	
	i = 0;
	temp = *a;
	while (temp)
	{
		i = 0;
		while (i < size)
		{
			if (temp->data == array[i])
			{
				temp->index = i;
				break;
			}
			i++;
		}
		temp = temp->next;
	}
}

void	rush_b(t_stack **a, t_stack **b)
{
	while (*a)
	{
		swap_pb(a, b);
	}
}

int	pos_in_c(int *array, int size, int index_b)
{
	int	i;

	i = 0;
	while(i < size)
	{
		if (array[i] == index_b)
			return (i);
		i++;
	}
	return (-1);
}

void	assign_pos(t_stack **b)
{
	t_stack	*temp;
	int		pos;

	pos = 0;
	temp = *b;
	while (temp)
	{
		temp->pos = pos;
		pos++;
		temp = temp->next;
	}
}

void	calculate_moves(t_stack **b, int *array, int size)
{
	t_stack	*tmpb;
	int		sizeb;
	int		pos_c;

	tmpb = *b;
	sizeb = lstsize(*b);
	assign_pos(b);
	while (tmpb)
	{
		pos_c = pos_in_c(array, size, tmpb->index);
		if (tmpb->pos <= sizeb / 2)
		{
			tmpb->rb = tmpb->pos;
			tmpb->rrb = 0;
		}
		else
		{
			tmpb->rb = 0;
			tmpb->rrb = sizeb - tmpb->pos;
		}
		if (pos_c <= size / 2)
		{
			tmpb->ra = pos_c;
			tmpb->rra = 0;
		}
		else
		{
			tmpb->ra = 0;
			tmpb->rra = size - pos_c;
		}
		tmpb = tmpb->next;
	}
}

void	best_node(t_stack **a, t_stack **b)
{
	t_stack	*tmp;
	t_stack	*best_one;
	int		min_moves;
	int		total_moves;
	
	tmp = *b;
	best_one = tmp;
	min_moves = tmp->ra + tmp->rb + tmp->rra + tmp->rrb;
	total_moves = 0;
	while (*b)
	{
		tmp = *b;
		best_one = tmp;
		min_moves = tmp->ra + tmp->rb + tmp->rra + tmp->rrb;
		while (tmp)
		{
			total_moves = tmp->ra + tmp->rb + tmp->rra + tmp->rrb;
			if (total_moves < min_moves)
			{
				min_moves = total_moves;
				best_one = tmp;
			}
			tmp = tmp->next;
		}
		while (best_one->rrb-- > 0)
			swap_rrb(a);
		while (best_one->rb-- > 0)
			swap_rb(b);
		while (best_one->rra-- > 0)
			swap_rra(a);
		while (best_one->ra-- > 0)
			swap_ra(b);
		swap_pa(a, b);
	}
}

void	final_rotation(t_stack **a)
{
	int	min_index;
	int	size;

	min_index = find_min_index(a, find_smallest(a));
	size = lstsize(*a);
	if (min_index < size / 2)
	{
		while (min_index-- > 0)
			swap_ra(a);
	}
	else
	{
		while (min_index++ < size)
			swap_rra(a);
	}
}
