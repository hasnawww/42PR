/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilhasnao <ilhasnao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 17:20:12 by ilhasnao          #+#    #+#             */
/*   Updated: 2025/03/07 17:48:53 by ilhasnao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/solongbonus.h"
#include "../../includes/errordefbonus.h"

int	on_keypressb(int keycode, t_datab *mlx)
{
	if (keycode == ESC)
		mlx_loop_end(mlx->ptr);
	if (keycode == 100)
		move_rightb(mlx);
	if (keycode == 97)
		move_leftb(mlx);
	if (keycode == 119)
		move_upb(mlx);
	if (keycode == 115)
		move_downb(mlx);
	return (0);
}

void	my_mlx_initb(t_datab *mlx)
{
	mlx->ptr = mlx_init();
	if (!mlx->ptr)
	{
		ft_putstr_fd("Error: MLX initialization failed\n", 2);
		exit(1);
	}
	init_camb(mlx);
	update_camb(mlx);
	init_frames1(mlx);
	init_frames2(mlx);
	mlx->current_frame = 0;
	mlx->frame_counter = 0;
}

void	init_frames1(t_datab *mlx)
{
	mlx->player_frames[0] = mlx_xpm_file_to_image(mlx->ptr,
			"texture/1igor.xpm", &mlx->img_x, &mlx->img_y);
	mlx->player_frames[1] = mlx_xpm_file_to_image(mlx->ptr,
			"texture/2igor.xpm", &mlx->img_x, &mlx->img_y);
	mlx->player_frames[2] = mlx_xpm_file_to_image(mlx->ptr,
			"texture/3igor.xpm", &mlx->img_x, &mlx->img_y);
	mlx->player_frames[3] = mlx_xpm_file_to_image(mlx->ptr,
			"texture/4igor.xpm", &mlx->img_x, &mlx->img_y);
	mlx->coin_frames[0] = mlx_xpm_file_to_image(mlx->ptr,
			"texture/1C.xpm", &mlx->img_x, &mlx->img_y);
	mlx->coin_frames[1] = mlx_xpm_file_to_image(mlx->ptr,
			"texture/2C.xpm", &mlx->img_x, &mlx->img_y);
	mlx->coin_frames[2] = mlx_xpm_file_to_image(mlx->ptr,
			"texture/3C.xpm", &mlx->img_x, &mlx->img_y);
	mlx->coin_frames[3] = mlx_xpm_file_to_image(mlx->ptr,
			"texture/4C.xpm", &mlx->img_x, &mlx->img_y);
	mlx->opps_frames[0] = mlx_xpm_file_to_image(mlx->ptr,
			"texture/1cb.xpm", &mlx->img_x, &mlx->img_y);
	mlx->opps_frames[1] = mlx_xpm_file_to_image(mlx->ptr,
			"texture/2cb.xpm", &mlx->img_x, &mlx->img_y);
	mlx->opps_frames[2] = mlx_xpm_file_to_image(mlx->ptr,
			"texture/3cb.xpm", &mlx->img_x, &mlx->img_y);
	mlx->opps_frames[3] = mlx_xpm_file_to_image(mlx->ptr,
			"texture/4cb.xpm", &mlx->img_x, &mlx->img_y);
}

void	init_frames2(t_datab *mlx)
{
	mlx->exit_frames[0] = mlx_xpm_file_to_image(mlx->ptr,
			"texture/1exit.xpm", &mlx->img_x, &mlx->img_y);
	mlx->exit_frames[1] = mlx_xpm_file_to_image(mlx->ptr,
			"texture/2exit.xpm", &mlx->img_x, &mlx->img_y);
	mlx->exit_frames[2] = mlx_xpm_file_to_image(mlx->ptr,
			"texture/3exit.xpm", &mlx->img_x, &mlx->img_y);
	mlx->exit_frames[3] = mlx_xpm_file_to_image(mlx->ptr,
			"texture/4exit.xpm", &mlx->img_x, &mlx->img_y);
	mlx->floor_frames[0] = mlx_xpm_file_to_image(mlx->ptr,
			"texture/1flowers.xpm", &mlx->img_x, &mlx->img_y);
	mlx->floor_frames[1] = mlx_xpm_file_to_image(mlx->ptr,
			"texture/2flowers.xpm", &mlx->img_x, &mlx->img_y);
	mlx->floor_frames[2] = mlx_xpm_file_to_image(mlx->ptr,
			"texture/3flowers.xpm", &mlx->img_x, &mlx->img_y);
	mlx->floor_frames[3] = mlx_xpm_file_to_image(mlx->ptr,
			"texture/4flowers.xpm", &mlx->img_x, &mlx->img_y);
	mlx->wall_frames[0] = mlx_xpm_file_to_image(mlx->ptr,
			"texture/1bee.xpm", &mlx->img_x, &mlx->img_y);
	mlx->wall_frames[1] = mlx_xpm_file_to_image(mlx->ptr,
			"texture/2bee.xpm", &mlx->img_x, &mlx->img_y);
	mlx->wall_frames[2] = mlx_xpm_file_to_image(mlx->ptr,
			"texture/3bee.xpm", &mlx->img_x, &mlx->img_y);
	mlx->wall_frames[3] = mlx_xpm_file_to_image(mlx->ptr,
			"texture/4bee.xpm", &mlx->img_x, &mlx->img_y);
}

void	init_windowb(t_datab *mlx)
{
	mlx->win = mlx_new_window(mlx->ptr, mlx->cam_length * 64,
			mlx->cam_height * 64, "So long");
	if (!mlx->win)
	{
		ft_putstr_fd("Error: Failed to create window\n", 2);
		mlx_loop_end(mlx->ptr);
	}
	mlx->move_count = 0;
	move_writingb(mlx);
}
