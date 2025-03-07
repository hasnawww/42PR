/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilhasnao <ilhasnao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 14:17:10 by ilhasnao          #+#    #+#             */
/*   Updated: 2025/03/07 17:52:08 by ilhasnao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/errordefbonus.h"
#include "includes/solongbonus.h"

int	main(int ac, char **av)
{
	t_datab	*mlx;

	if (ac == 2 && open(av[1], O_RDONLY) != -1)
	{
		mlx = malloc(sizeof(t_datab));
		mlx->map = malloc(sizeof(t_map));
		map_initb(mlx, av);
		parsingb(av, mlx);
		my_mlx_initb(mlx);
		init_windowb(mlx);
		render_mapb(mlx->map->lines, mlx);
		mlx_key_hook(mlx->win, on_keypressb, mlx);
		mlx_hook(mlx->win, 17, 0, free_allb, mlx);
		mlx_loop_hook(mlx->ptr, update_anim, mlx);
		mlx_loop(mlx->ptr);
		free_allb(mlx);
	}
	return (0);
}
