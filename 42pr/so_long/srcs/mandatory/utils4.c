/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilhasnao <ilhasnao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 17:24:47 by ilhasnao          #+#    #+#             */
/*   Updated: 2025/03/07 17:38:45 by ilhasnao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/solong.h"
#include "../../includes/errordef.h"

void	move_right(t_data *mlx)
{
	int	x;
	int	y;

	get_coordinates(mlx->map->lines, &x, &y);
	if (mlx->map->lines[y][x + 1] == '1')
		return ;
	if (mlx->map->lines[y][x + 1] == 'E' && mlx->map->map_items->c_coin != 0)
		return ;
	else if (mlx->map->lines[y][x + 1] == 'E'
		&& mlx->map->map_items->c_coin == 0)
		mlx_loop_end(mlx->ptr);
	else if (mlx->map->lines[y][x + 1] == 'C')
	{
		mlx->map->lines[y][x + 1] = 'P';
		mlx->map->lines[y][x] = '0';
		mlx->map->map_items->c_coin--;
	}
	else if (mlx->map->lines[y][x + 1] == '0')
	{
		mlx->map->lines[y][x + 1] = 'P';
		mlx->map->lines[y][x] = '0';
	}
	mlx->move_count++;
	render_map(mlx->map->lines, mlx);
	update_cam(mlx);
}

void	move_left(t_data *mlx)
{
	int	x;
	int	y;

	get_coordinates(mlx->map->lines, &x, &y);
	if (mlx->map->lines[y][x - 1] == '1')
		return ;
	if (mlx->map->lines[y][x - 1] == 'E' && mlx->map->map_items->c_coin != 0)
		return ;
	else if (mlx->map->lines[y][x - 1] == 'E'
		&& mlx->map->map_items->c_coin == 0)
		mlx_loop_end(mlx->ptr);
	else if (mlx->map->lines[y][x - 1] == 'C')
	{
		mlx->map->lines[y][x - 1] = 'P';
		mlx->map->lines[y][x] = '0';
		mlx->map->map_items->c_coin--;
	}
	else if (mlx->map->lines[y][x - 1] == '0')
	{
		mlx->map->lines[y][x - 1] = 'P';
		mlx->map->lines[y][x] = '0';
	}
	mlx->move_count++;
	render_map(mlx->map->lines, mlx);
	update_cam(mlx);
}

void	init_cam(t_data *mlx)
{
	mlx->cam_x = 0;
	mlx->cam_y = 0;
	mlx->cam_height = 10;
	mlx->cam_length = 20;
	if (mlx->cam_length > mlx->map->length)
		mlx->cam_length = mlx->map->length;
	if (mlx->cam_height > mlx->map->height)
		mlx->cam_height = mlx->map->height;
}

void	update_cam(t_data *mlx)
{
	int	x;
	int	y;

	get_coordinates(mlx->map->lines, &x, &y);
	mlx->cam_x = x - (mlx->cam_length / 2);
	mlx->cam_y = y - (mlx->cam_height / 2);
	if (mlx->cam_x < 0)
		mlx->cam_x = 0;
	if (mlx->cam_y < 0)
		mlx->cam_y = 0;
	if (mlx->cam_y + mlx->cam_height > mlx->map->height)
		mlx->cam_y = mlx->map->height - mlx->cam_height;
	if (mlx->cam_x + mlx->cam_length > mlx->map->length)
		mlx->cam_x = mlx->map->length - mlx->cam_length;
}
