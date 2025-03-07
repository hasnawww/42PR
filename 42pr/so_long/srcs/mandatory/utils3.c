/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilhasnao <ilhasnao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 17:24:12 by ilhasnao          #+#    #+#             */
/*   Updated: 2025/03/07 17:38:42 by ilhasnao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/solong.h"
#include "../../includes/errordef.h"

void	render_map(char **map, t_data *mlx)
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
				put_image(map[i][j], mlx, i, j);
			j++;
		}
		i++;
	}
	move_writing(mlx);
}

int	free_all(t_data *mlx)
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
		genkidama(mlx);
	exit(0);
	return (0);
}

void	move_up(t_data *mlx)
{
	int	x;
	int	y;

	get_coordinates(mlx->map->lines, &x, &y);
	if (mlx->map->lines[y - 1][x] == '1')
		return ;
	if (mlx->map->lines[y - 1][x] == 'E' && mlx->map->map_items->c_coin != 0)
		return ;
	else if (mlx->map->lines[y - 1][x] == 'E'
		&& mlx->map->map_items->c_coin == 0)
		mlx_loop_end(mlx->ptr);
	else if (mlx->map->lines[y - 1][x] == 'C')
	{
		mlx->map->lines[y - 1][x] = 'P';
		mlx->map->lines[y][x] = '0';
		mlx->map->map_items->c_coin--;
	}
	else if (mlx->map->lines[y - 1][x] == '0')
	{
		mlx->map->lines[y - 1][x] = 'P';
		mlx->map->lines[y][x] = '0';
	}
	mlx->move_count++;
	render_map(mlx->map->lines, mlx);
	update_cam(mlx);
}

void	move_down(t_data *mlx)
{
	int	x;
	int	y;

	get_coordinates(mlx->map->lines, &x, &y);
	if (mlx->map->lines[y + 1][x] == '1')
		return ;
	if (mlx->map->lines[y + 1][x] == 'E' && mlx->map->map_items->c_coin != 0)
		return ;
	else if (mlx->map->lines[y + 1][x] == 'E'
		&& mlx->map->map_items->c_coin == 0)
		mlx_loop_end(mlx->ptr);
	else if (mlx->map->lines[y + 1][x] == 'C')
	{
		mlx->map->lines[y + 1][x] = 'P';
		mlx->map->lines[y][x] = '0';
		mlx->map->map_items->c_coin--;
	}
	else if (mlx->map->lines[y + 1][x] == '0')
	{
		mlx->map->lines[y + 1][x] = 'P';
		mlx->map->lines[y][x] = '0';
	}
	mlx->move_count++;
	render_map(mlx->map->lines, mlx);
	update_cam(mlx);
}

void	move_writing(t_data *mlx)
{
	char	*str;
	char	*temp;

	temp = ft_itoa(mlx->move_count);
	str = ft_strjoin("number of moves: ", temp);
	if (!str)
		return ;
	ft_putstr_fd(str, 1);
	ft_putstr_fd("\n", 1);
	free(str);
	free(temp);
}
