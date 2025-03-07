/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilhasnao <ilhasnao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 17:21:12 by ilhasnao          #+#    #+#             */
/*   Updated: 2025/03/07 17:59:38 by ilhasnao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/solongbonus.h"
#include "../../includes/errordefbonus.h"

void	put_imageb(char c, t_datab *mlx, int i, int j)
{
	int	x;
	int	y;

	x = (j - mlx->cam_x) * 64;
	y = (i - mlx->cam_y) * 64;
	if (c == '1')
		mlx_put_image_to_window(mlx->ptr,
			mlx->win, mlx->wall_frames[mlx->current_frame], x, y);
	else if (c == '0')
		mlx_put_image_to_window(mlx->ptr,
			mlx->win, mlx->floor_frames[mlx->current_frame], x, y);
	else if (c == 'O')
		mlx_put_image_to_window(mlx->ptr,
			mlx->win, mlx->opps_frames[mlx->current_frame], x, y);
	else if (c == 'P')
		mlx_put_image_to_window(mlx->ptr,
			mlx->win, mlx->player_frames[mlx->current_frame], x, y);
	else if (c == 'C')
		mlx_put_image_to_window(mlx->ptr,
			mlx->win, mlx->coin_frames[mlx->current_frame], x, y);
	else if (c == 'E')
		mlx_put_image_to_window(mlx->ptr,
			mlx->win, mlx->exit_frames[mlx->current_frame], x, y);
}

void	render_mapb(char **map, t_datab *mlx)
{
	int	i;
	int	j;

	i = mlx->cam_y;
	while (i < mlx->cam_y + mlx->cam_height && i < mlx->map->height)
	{
		j = mlx->cam_x;
		while (j < mlx->cam_x + mlx->cam_length && j < mlx->map->length)
		{
			if (i >= 0 && i < mlx->map->height
				&& j >= 0 && j < mlx->map->length)
				put_imageb(map[i][j], mlx, i, j);
			j++;
		}
		i++;
	}
	move_writingb(mlx);
}

void	destroy_frames(t_datab *mlx)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (mlx->wall_frames[i])
			mlx_destroy_image(mlx->ptr, mlx->wall_frames[i]);
		if (mlx->player_frames[i])
			mlx_destroy_image(mlx->ptr, mlx->player_frames[i]);
		if (mlx->floor_frames[i])
			mlx_destroy_image(mlx->ptr, mlx->floor_frames[i]);
		if (mlx->coin_frames[i])
			mlx_destroy_image(mlx->ptr, mlx->coin_frames[i]);
		if (mlx->exit_frames[i])
			mlx_destroy_image(mlx->ptr, mlx->exit_frames[i]);
		if (mlx->opps_frames[i])
			mlx_destroy_image(mlx->ptr, mlx->opps_frames[i]);
		i++;
	}
}

int	update_anim(t_datab *mlx)
{
	// usleep(10000);
	mlx->frame_counter++;
	if (mlx->frame_counter >= 10)
	{
		mlx->current_frame = (mlx->current_frame + 1) % 3;
		mlx->frame_counter = 0;
		render_mapb(mlx->map->lines, mlx);
	}
	return (0);
}

int	free_allb(t_datab *mlx)
{
	destroy_frames(mlx);
	if (mlx->win)
		mlx_destroy_window(mlx->ptr, mlx->win);
	if (mlx->ptr)
	{
		mlx_destroy_display(mlx->ptr);
		free(mlx->ptr);
	}
	if (mlx->map)
		genkidamab(mlx);
	exit(0);
	return (0);
}
