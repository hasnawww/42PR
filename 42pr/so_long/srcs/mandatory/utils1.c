/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilhasnao <ilhasnao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 14:00:17 by ilhasnao          #+#    #+#             */
/*   Updated: 2025/03/07 17:38:35 by ilhasnao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/solong.h"
#include "../../includes/errordef.h"

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

void	assign_images(t_data *mlx)
{
	mlx->exit = mlx_xpm_file_to_image(mlx->ptr, mlx->path_exit,
			&mlx->img_x, &mlx->img_y);
	mlx->coin = mlx_xpm_file_to_image(mlx->ptr, mlx->path_coin,
			&mlx->img_x, &mlx->img_y);
	mlx->wall = mlx_xpm_file_to_image(mlx->ptr, mlx->path_wall,
			&mlx->img_x, &mlx->img_y);
	mlx->floor = mlx_xpm_file_to_image(mlx->ptr, mlx->path_floor,
			&mlx->img_x, &mlx->img_y);
	mlx->player = mlx_xpm_file_to_image(mlx->ptr, mlx->path_player,
			&mlx->img_x, &mlx->img_y);
}

void	my_mlx_init(t_data *mlx)
{
	mlx->ptr = mlx_init();
	if (!mlx->ptr)
	{
		ft_putstr_fd("Error: MLX initialization failed\n", 2);
		exit(1);
	}
	init_cam(mlx);
	update_cam(mlx);
	mlx->path_wall = "textures/wall.xpm";
	mlx->path_floor = "textures/floor.xpm";
	mlx->path_player = "textures/player.xpm";
	mlx->path_coin = "textures/coin.xpm";
	mlx->path_exit = "textures/exit.xpm";
	assign_images(mlx);
	if (!mlx->wall || !mlx->floor || !mlx->player)
	{
		ft_putstr_fd("Error: Failed to load textures\n", 2);
		mlx_loop_end(mlx->ptr);
	}
}

void	init_window(t_data *mlx)
{
	mlx->win = mlx_new_window(mlx->ptr, mlx->cam_length * 64,
			mlx->cam_height * 64, "So long");
	if (!mlx->win)
	{
		ft_putstr_fd("Error: Failed to create window\n", 2);
		mlx_loop_end(mlx->ptr);
	}
	mlx->move_count = 0;
}

void	put_image(char c, t_data *mlx, int i, int j)
{
	int	x;
	int	y;

	x = (j - mlx->cam_x) * 64;
	y = (i - mlx->cam_y) * 64;
	if (c == '1')
		mlx_put_image_to_window(mlx->ptr,
			mlx->win, mlx->wall, x, y);
	else if (c == '0')
		mlx_put_image_to_window(mlx->ptr,
			mlx->win, mlx->floor, x, y);
	else if (c == 'P')
		mlx_put_image_to_window(mlx->ptr,
			mlx->win, mlx->player, x, y);
	else if (c == 'C')
		mlx_put_image_to_window(mlx->ptr,
			mlx->win, mlx->coin, x, y);
	else if (c == 'E')
		mlx_put_image_to_window(mlx->ptr,
			mlx->win, mlx->exit, x, y);
}
