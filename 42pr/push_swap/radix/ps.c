/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilhasnao <ilhasnao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 02:39:00 by ilhasnao          #+#    #+#             */
/*   Updated: 2025/01/06 06:53:28 by ilhasnao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

long	index_of(t_nodes *list, long data)
{
	t_stack	*curr;
	long	index;

	index = 0;
	curr = list->a;
	while (curr)
	{
		if (data >= curr->data)
			index++;
		curr = curr->next;
	}
	return (index);
}

void	give_index(t_nodes *ab, int size)
{
	t_stack	*temp;
	int		i;
	int		finish;
	
	if (!ab)
		return ;
	finish = 1;
	temp = ab->a;
	while (temp && finish < size)
	{
		i = index_of(ab, temp->data);
		temp->index = i;
		temp = temp->next;
		finish++;
	}
}

int	already_sorted(t_nodes *ab)
{
	t_stack	*temp;

	if (!ab)
		return (1);
	if (!ab->a)
		return (1);
	temp = ab->a;
	while (temp->next)
	{
		if (temp->data > temp->next->data)
			return (0);
		temp = temp->next;
	}
	return (1);
}

void	execute_radix_pass(t_nodes *ps, int bit_position, int element_count)
{
	int		index;
	t_stack	*current;

	index = 0;
	while (index < element_count)
	{
		current = ps->a;
		if (((current->index >> bit_position) & 1) == 1)
			swap_ra(ps);
		else
			swap_pb(ps);
		index++;
	}
	while (lstsize(ps->b) > 0)
		swap_pa(ps);
}

void	sort_large_stack(t_nodes *ps, int bits_required, int element_count)
{
	int		bit_position;

	bit_position = 0;
	while (bit_position < bits_required)
	{
		execute_radix_pass(ps, bit_position, element_count);
		bit_position++;
	}
}


void	ft_fil(t_stack **ab, int data)
{
	t_stack	*node;
	t_stack	*temp;

	temp = *ab;
	node = malloc(sizeof(t_stack));
	if (!node)
		return ;
	node->data = data;
	node->index = -1;
	node->next = NULL;
	if (!*ab)
	{
		*ab = node;
		return ;
	}
	while (temp->next)
		temp = temp->next;
	temp->next = node;
	node->next = NULL;
}

t_nodes	*assign(char **av, int ac)
{
	t_nodes	*node;
	int		i;
	int		value;
	
	node = malloc(sizeof(t_nodes));
	if (!node)
		return (NULL);
	node->a = NULL;
	node->b = NULL;
	if (ac == 2)
		i = 0;
	else
		i = 1;
	while (++i < ac)
	{
		value = ft_atoi(av[i]);
		ft_fil(&node->a, value);
	}
	return (node);
}

void	free_lbail(t_stack **a)
{
	t_stack	*temp;
	
	while (*a)
	{
		temp = *a;
		*a = (*a)->next;
		free(temp);
	}
}

void	printt_stack(t_nodes *ab)
{
	t_stack	*temp;

	if (!ab)
		return ;
	temp = ab->a;
	while(temp)
	{
		ft_putnbr_fd(temp->data, 2);
		write(1, "\n", 1);
		temp = temp->next;
	}
}

void	free_split(char **result)
{
	int	i;

	i = 0;
	while (result[i])
		free(result[i++]);
	free(result);
}

void	ft_subprocess(t_nodes *ab, char **av)
{
	char	**result;
	int		i;
	int		j;

	i = 0;
	result = ft_split(av[1], ' ');
	if (!result)
		return ;
	while (result[i])
	{
		j = ft_atoi(result[i]);
		ft_fil(&ab->a, j);
		i++;
	}
	free_split(result);
}

int	calculate_bits_required(t_nodes *ps)
{
	t_stack	*iterator;
	int		highest_value;
	int		bit_count;

	iterator = ps->a;
	bit_count = 0;
	if (iterator == NULL)
		return (0);
	highest_value = iterator->index;
	while (iterator != NULL)
	{
		if (iterator->index > highest_value)
			highest_value = iterator->index;
		iterator = iterator->next;
	}
	while ((highest_value >> bit_count) != 0)
		bit_count++;
	return (bit_count);
}

void	free_pushswap(t_nodes *ps)
{
	t_stack	*current;
	t_stack	*next;

	if (ps)
	{
		current = ps->a;
		while (current)
		{
			next = current->next;
			free(current);
			current = next;
		}
		current = ps->b;
		while (current)
		{
			next = current->next;
			free(current);
			current = next;
		}
		free(ps);
	}
}

void	algo(t_nodes *ps)
{
	int		element_count;
	int		bits_required;

	element_count = lstsize(ps->a);
	bits_required = calculate_bits_required(ps);
	sort_large_stack(ps, bits_required, element_count);
	free_pushswap(ps);
}

int	main(int ac, char **av)
{
	t_nodes	*ab;

	if (ac == 1 || (ac == 2 && !av[1][0]))
	{
		ft_putstr_fd("you're just a chill guy who forgot the input :)\n", 2);
		return (0);
	}
	if (ac == 2)
	{
		ab = malloc(sizeof(t_nodes));
		if (!ab)
			return (0);
		ab->a = NULL;
		ab->b = NULL;
		ft_subprocess(ab, av);
	}
	else
	{
		ab = assign(av, ac);
		if (!ab)
			return (0);
	}
	give_index(ab, ac);
	write(1, "old_list : ", 11);
	printt_stack(ab);
	algo(ab);
	write(1, "new_list : ", 11);
	printt_stack(ab);
	free_pushswap(ab);
	return (0);
}
