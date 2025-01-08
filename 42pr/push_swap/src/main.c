/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasnawww <hasnawww@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 19:03:17 by ilhasnao          #+#    #+#             */
/*   Updated: 2025/01/08 04:04:00 by hasnawww         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	main(int ac, char **av)
{
	t_stack	**a;
	t_stack	**b;

	a = malloc(sizeof(t_stack *));
	b = malloc(sizeof(t_stack *));
	if (!a || !b)
		return (0);
	*a = NULL;
	*b = NULL;
	if (ac == 1 || (ac == 2 && !av[1][0]))
	{
		ft_putstr_fd("you're just a chill guy who forgot the input :)\n", 2);
		return (free_lbail(a), free_lbail(b), show_error(), 0);
	}
	if (ac == 2)
		ft_sprocess(a, av, ac);
	else
		ft_fill(a, av, ac);
	validate_arg(av, ac);
	index_stack(a);
	if (!already_sorted(a))
		algo(a, b);
	free_lbail(a);
	free_lbail(b);
	return (0);
}
