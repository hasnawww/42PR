/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilhasnao <ilhasnao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 17:22:01 by ilhasnao          #+#    #+#             */
/*   Updated: 2025/03/07 17:38:24 by ilhasnao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/solongbonus.h"
#include "../../includes/errordefbonus.h"

void	moves(t_datab *mlx)
{
	mlx->move_count++;
	render_mapb(mlx->map->lines, mlx);
	update_camb(mlx);
}

void	move_upb(t_datab *mlx)
{
	int	x;
	int	y;

	get_coordinates(mlx->map->lines, &x, &y);
	if (mlx->map->lines[y - 1][x] == 'O')
		mlx_loop_end(mlx->ptr);
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
	moves(mlx);
}

void	move_downb(t_datab *mlx)
{
	int	x;
	int	y;

	get_coordinates(mlx->map->lines, &x, &y);
	if (mlx->map->lines[y + 1][x] == '1')
		return ;
	if (mlx->map->lines[y + 1][x] == 'O')
		mlx_loop_end(mlx->ptr);
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
	moves(mlx);
}

void	move_writingb(t_datab *mlx)
{
	char	*str;
	char	*temp;

	temp = ft_itoa(mlx->move_count);
	str = ft_strjoin("number of moves: ", temp);
	if (!str)
		return ;
	mlx_string_put(mlx->ptr, mlx->win, 10, 10, 0xFFFFFF, str);
	free(str);
	free(temp);
}

void	move_rightb(t_datab *mlx)
{
	int	x;
	int	y;

	get_coordinates(mlx->map->lines, &x, &y);
	if (mlx->map->lines[y][x + 1] == 'O')
		mlx_loop_end(mlx->ptr);
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
	moves(mlx);
}
