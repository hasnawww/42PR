/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilhasnao <ilhasnao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 14:17:10 by ilhasnao          #+#    #+#             */
/*   Updated: 2025/02/26 23:46:09 by ilhasnao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "errordef.h"
#include "solong.h"

int	close_win(int keycode, void *ptr)
{
	if (keycode == XK_Escape)
		mlx_loop_end(ptr);
	return (0);
}

void	my_mlx_init(t_data *mlx)
{
	mlx->ptr = mlx_init();
	if (!mlx->ptr)
	{
		ft_putstr_fd("Error: MLX initialization failed\n", 2);
		exit(1);
	}
	mlx->path_wall = "textures/wall.xpm";
	mlx->path_floor = "textures/floor.xpm";
	mlx->path_player = "textures/player.xpm";
	mlx->wall = mlx_xpm_file_to_image(mlx->ptr, mlx->path_wall, &mlx->img_x, &mlx->img_y);
	mlx->floor = mlx_xpm_file_to_image(mlx->ptr, mlx->path_floor, &mlx->img_x, &mlx->img_y);
	mlx->player = mlx_xpm_file_to_image(mlx->ptr, mlx->path_player, &mlx->img_x, &mlx->img_y);
	if (!mlx->wall || !mlx->floor || !mlx->player)
	{
		ft_putstr_fd("Error: Failed to load textures\n", 2);
		mlx_loop_end(mlx->ptr);
	}
}

void	init_window(t_data *mlx, t_map *map)
{
	mlx->win_y = map->height * mlx->img_y + 41 * map->length;
	mlx->win_x = map->length * mlx->img_x - 41 * map->length;
	mlx->win = mlx_new_window(mlx->ptr, 1920, 1080, "So long");
	if (!mlx->win)
	{
		ft_putstr_fd("Error: Failed to create window\n", 2);
		mlx_loop_end(mlx->ptr);
	}
}

void	render_map(char **map, t_data *mlx)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '1')
				mlx_put_image_to_window(mlx->ptr, 
						mlx->win, mlx->wall, j * TILE_SIZE, i * TILE_SIZE);
			else if (map[i][j] == '0')
				mlx_put_image_to_window(mlx->ptr, 
						mlx->win, mlx->floor, j * TILE_SIZE, i * TILE_SIZE);
			else if (map[i][j] == 'P')
				mlx_put_image_to_window(mlx->ptr, 
						mlx->win, mlx->player, j * TILE_SIZE, i * TILE_SIZE);
			j++;
		}
		i++;
	}
}

void	free_all(t_map *map, t_data *mlx)
{
	if (map)
		genkidama(map);
	if (mlx->wall)
		mlx_destroy_image(mlx->ptr, mlx->wall);
	if (mlx->floor)
		mlx_destroy_image(mlx->ptr, mlx->floor);
	if (mlx->player)
		mlx_destroy_image(mlx->ptr, mlx->player);
	if (mlx->win)
		mlx_destroy_window(mlx->ptr, mlx->win);
	if (mlx->ptr)
	{
		mlx_destroy_display(mlx->ptr);
		free(mlx->ptr);
	}
}

int	main(int ac, char **av)
{
	t_data	mlx;
	t_map	map;

	if (ac == 2)
	{
		map_init(&map, av);
		// print_map(map.copy);
		// genkidama(&map);
		my_mlx_init(&mlx);
		init_window(&mlx, mlx.ptr);
		mlx_key_hook(mlx.win, close_win, mlx.ptr);
		render_map(map.lines, &mlx);
		mlx_loop(mlx.ptr);
		free_all(&map, &mlx);
	}
	return (0);
}
