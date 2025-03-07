/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilhasnao <ilhasnao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 14:17:10 by ilhasnao          #+#    #+#             */
/*   Updated: 2025/03/07 17:39:05 by ilhasnao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/errordef.h"
#include "includes/solong.h"

int	main(int ac, char **av)
{
	t_data	*mlx;

	if (ac == 2 && open(av[1], O_RDONLY) != -1)
	{
		mlx = malloc(sizeof(t_data));
		mlx->map = malloc(sizeof(t_map));
		map_init(mlx, av);
		parsing(av, mlx);
		my_mlx_init(mlx);
		init_window(mlx);
		render_map(mlx->map->lines, mlx);
		mlx_key_hook(mlx->win, on_keypress, mlx);
		mlx_hook(mlx->win, 17, 0, free_all, mlx);
		mlx_loop(mlx->ptr);
		free_all(mlx);
	}
	return (0);
}
