/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilhasnao <ilhasnao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 14:17:10 by ilhasnao          #+#    #+#             */
/*   Updated: 2025/02/28 01:23:45 by ilhasnao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "errordef.h"
#include "solong.h"

int	on_keypress(int keycode, t_data *mlx)
{
	if (keycode == ESC)
		mlx_loop_end(mlx->ptr);
	if (keycode == 100)
		move_right(mlx);
	if (keycode == 97)
		move_left(mlx);
	if (keycode == 119)
		move_up(mlx);
	if (keycode == 115)
		move_down(mlx);
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
	mlx->path_coin = "textures/coin.xpm";
	mlx->path_exit = "textures/exit.xpm";
	mlx->exit = mlx_xpm_file_to_image(mlx->ptr, mlx->path_exit, &mlx->img_x, &mlx->img_y);
	mlx->coin = mlx_xpm_file_to_image(mlx->ptr, mlx->path_coin, &mlx->img_x, &mlx->img_y);
	mlx->wall = mlx_xpm_file_to_image(mlx->ptr, mlx->path_wall, &mlx->img_x, &mlx->img_y);
	mlx->floor = mlx_xpm_file_to_image(mlx->ptr, mlx->path_floor, &mlx->img_x, &mlx->img_y);
	mlx->player = mlx_xpm_file_to_image(mlx->ptr, mlx->path_player, &mlx->img_x, &mlx->img_y);
	if (!mlx->wall || !mlx->floor || !mlx->player)
	{
		ft_putstr_fd("Error: Failed to load textures\n", 2);
		mlx_loop_end(mlx->ptr);
	}
}

void	init_window(t_data *mlx)
{
	mlx->win = mlx_new_window(mlx->ptr, mlx->map->length * 64, mlx->map->height * 64, "So long");
	if (!mlx->win)
	{
		ft_putstr_fd("Error: Failed to create window\n", 2);
		mlx_loop_end(mlx->ptr);
	}
}

void	put_image(char c, t_data *mlx, int i, int j)
{
	if (c == '1')
		mlx_put_image_to_window(mlx->ptr, 
				mlx->win, mlx->wall, j * TILE_SIZE, i * TILE_SIZE);
	else if (c == '0')
		mlx_put_image_to_window(mlx->ptr, 
				mlx->win, mlx->floor, j * TILE_SIZE, i * TILE_SIZE);
	else if (c == 'P')
		mlx_put_image_to_window(mlx->ptr, 
				mlx->win, mlx->player, j * TILE_SIZE, i * TILE_SIZE);
	else if (c == 'C')
		mlx_put_image_to_window(mlx->ptr, 
						mlx->win, mlx->coin, j * TILE_SIZE, i * TILE_SIZE);
	else if (c == 'E')
		mlx_put_image_to_window(mlx->ptr, 
						mlx->win, mlx->exit, j * TILE_SIZE, i * TILE_SIZE);
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
			put_image(map[i][j], mlx, i, j);
			j++;
		}
		i++;
	}
}

int	free_all (t_data *mlx)
{
	if (mlx->wall)
		mlx_destroy_image(mlx->ptr, mlx->wall);
	if (mlx->floor)
		mlx_destroy_image(mlx->ptr, mlx->floor);
	if (mlx->player)
		mlx_destroy_image(mlx->ptr, mlx->player);
	if (mlx->coin)
		mlx_destroy_image(mlx->ptr, mlx->coin);
	if (mlx->exit)
		mlx_destroy_image(mlx->ptr, mlx->exit);
	if (mlx->win)
		mlx_destroy_window(mlx->ptr, mlx->win);
	if (mlx->ptr)
	{
		mlx_destroy_display(mlx->ptr);
		free(mlx->ptr);
	}
	if (mlx->map)
		genkidama(mlx->map);
	free(mlx);
	exit(0);
	return (0);
}

void	move_up(t_data *mlx)
{
	int	x;
	int	y;

	get_coordinates(mlx->map->lines, &x, &y);
	if (mlx->map->lines[x - 1][y] == '1')
		return ;
	if (mlx->map->lines[x - 1][y] == 'E'
		&& mlx->map->map_items->C_coin != 0)
		return ;
	else if (mlx->map->lines[x - 1][y] == 'E'
		&& mlx->map->map_items->C_coin == 0)
		mlx_loop_end(mlx->ptr);
	else if (mlx->map->lines[x - 1][y] == 'C')
	{
		mlx->map->lines[x - 1][y] = 'P';
		mlx->map->lines[x][y] = '0';
		mlx->map->map_items->C_coin--;
	}
	else if (mlx->map->lines[x - 1][y] == '0')
	{
		mlx->map->lines[x - 1][y] = 'P';
		mlx->map->lines[x][y] = '0';
	}
	render_map(mlx->map->lines, mlx);
}

void	move_down(t_data *mlx)
{
	int	x;
	int	y;

	get_coordinates(mlx->map->lines, &x, &y);
	if (mlx->map->lines[x + 1][y] == '1')
		return ;
	if (mlx->map->lines[x + 1][y] == 'E'
		&& mlx->map->map_items->C_coin != 0)
		return ;
	else if (mlx->map->lines[x + 1][y] == 'E'
		&& mlx->map->map_items->C_coin == 0)
		mlx_loop_end(mlx->ptr);
	else if (mlx->map->lines[x + 1][y] == 'C')
	{
		mlx->map->lines[x + 1][y] = 'P';
		mlx->map->lines[x][y] = '0';
		mlx->map->map_items->C_coin--;
	}
	else if (mlx->map->lines[x + 1][y] == '0')
	{
		mlx->map->lines[x + 1][y] = 'P';
		mlx->map->lines[x][y] = '0';
	}
	render_map(mlx->map->lines, mlx);
}

void	move_right(t_data *mlx)
{
int	x;
	int	y;

	get_coordinates(mlx->map->lines, &x, &y);
	if (mlx->map->lines[x][y + 1] == '1')
		return ;
	if (mlx->map->lines[x][y + 1] == 'E'
		&& mlx->map->map_items->C_coin != 0)
		return ;
	else if (mlx->map->lines[x][y + 1] == 'E'
		&& mlx->map->map_items->C_coin == 0)
		mlx_loop_end(mlx->ptr);
	else if (mlx->map->lines[x][y + 1] == 'C')
	{
		mlx->map->lines[x][y + 1] = 'P';
		mlx->map->lines[x][y] = '0';
		mlx->map->map_items->C_coin--;
	}
	else if (mlx->map->lines[x][y + 1] == '0')
	{
		mlx->map->lines[x][y + 1] = 'P';
		mlx->map->lines[x][y] = '0';
	}
	render_map(mlx->map->lines, mlx);
}

void	move_left(t_data *mlx)
{
	int	x;
	int	y;

	get_coordinates(mlx->map->lines, &x, &y);
	if (mlx->map->lines[x][y - 1] == '1')
		return ;
	if (mlx->map->lines[x][y - 1] == 'E'
		&& mlx->map->map_items->C_coin != 0)
		return ;
	else if (mlx->map->lines[x][y - 1] == 'E'
		&& mlx->map->map_items->C_coin == 0)
		mlx_loop_end(mlx->ptr);
	else if (mlx->map->lines[x][y - 1] == 'C')
	{
		mlx->map->lines[x][y - 1] = 'P';
		mlx->map->lines[x][y] = '0';
		mlx->map->map_items->C_coin--;
	}
	else if (mlx->map->lines[x][y - 1] == '0')
	{
		mlx->map->lines[x][y - 1] = 'P';
		mlx->map->lines[x][y] = '0';
	}
	render_map(mlx->map->lines, mlx);
}

int	main(int ac, char **av)
{
	t_data	*mlx;
	// int	i;

	// i = 0;
	if (ac == 2)
	{
		mlx = malloc(sizeof(t_data));
		mlx->map = malloc(sizeof(t_map));
		map_init(mlx->map, av);
		parsing(av, mlx->map);
		// genkidama(mlx->map);
		// free(mlx);
		my_mlx_init(mlx);
		init_window(mlx);
		render_map(mlx->map->lines, mlx);
		// mlx.win = mlx_new_window(mlx.ptr, 1920, 1080, "So long");
		mlx_key_hook(mlx->win, on_keypress, mlx);
		mlx_hook(mlx->win, 17, 0, free_all, mlx);
		mlx_loop(mlx->ptr);
		free_all(mlx);
	}
	return (0);
}
