/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasnawww <hasnawww@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 03:38:27 by hasnawww          #+#    #+#             */
/*   Updated: 2025/01/08 03:51:59 by hasnawww         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void    algo(t_stack **a, t_stack **b)
{
    if (lstsize(*a) == 2)
        sort_two(a);
    else if (lstsize(*a) == 3)
        sort_three(a);
    else if (lstsize(*a) == 4)
        sort_four(a, b);
    else if (lstsize(*a) == 5)
        sort_five(a, b);
    else
        radix_sort(a, b);
}
