/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilhasnao <ilhasnao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 22:49:28 by ilhasnao          #+#    #+#             */
/*   Updated: 2025/01/05 21:40:47 by ilhasnao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	*array_dup(t_stack **a)
{
	int	i;
	t_stack	*temp;
	int	*array;

	temp = *a;
	i = 0;
	array = malloc(sizeof(int) * lstsize(*a));
	if (!array)
		return (NULL);
	while (temp != NULL)
	{
		array[i++] = temp->data;
		temp = temp->next;
	}
	return (array);
}

void	swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

int	pivot_index(int	*array, int start, int end)
{
	int	pivot;
	int	i;
	int	j;

	pivot = array[end];
	i = start - 1;
	j = start;
	while (j < end)
	{
		if (array[j] < pivot)
		{
			i++;
			swap(&array[i], &array[j]);
		}
		j++;
	}
	swap(&array[i + 1], &array[end]);
	return (i + 1);
}

void	quicksort(int *array, int start, int end)
{
	int	pivot;

	if (start < end)
	{
		pivot = pivot_index(array, start, end);
		quicksort(array, start, pivot - 1);
		quicksort(array, pivot + 1, end);
	}
}

void	printnbr(int *array)
{
	int	i;

	i = 0;
	while (array[i] != '\0')
	{
		printf("%d\n", array[i]);
		i++;
	}
}

int	*sorted_array(t_stack **a, int size)
{
	int	*array;

	array = array_dup(a);
	if (!array)
		return (NULL);
	quicksort(array, 0, size -1);
	// printnbr(array);
	return (array);
}
