/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilhasnao <ilhasnao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 14:17:10 by ilhasnao          #+#    #+#             */
/*   Updated: 2025/03/06 13:45:58 by ilhasnao         ###   ########.fr       */
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
	init_cam(mlx);
	update_cam(mlx);
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
	mlx->win = mlx_new_window(mlx->ptr, mlx->cam_length * 64, mlx->cam_height * 64, "So long");
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
	if (mlx->map->lines[y - 1][x] == '1')
		return ;
	if (mlx->map->lines[y - 1][x] == 'E' && mlx->map->map_items->C_coin != 0)
		return ;
	else if (mlx->map->lines[y - 1][x] == 'E'
		&& mlx->map->map_items->C_coin == 0)
		mlx_loop_end(mlx->ptr);
	else if (mlx->map->lines[y - 1][x] == 'C')
	{
		mlx->map->lines[y - 1][x] = 'P';
		mlx->map->lines[y][x] = '0';
		mlx->map->map_items->C_coin--;
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
	if (mlx->map->lines[y + 1][x] == 'E' && mlx->map->map_items->C_coin != 0)
		return ;
	else if (mlx->map->lines[y + 1][x] == 'E'
		&& mlx->map->map_items->C_coin == 0)
		mlx_loop_end(mlx->ptr);
	else if (mlx->map->lines[y + 1][x] == 'C')
	{
		mlx->map->lines[y + 1][x] = 'P';
		mlx->map->lines[y][x] = '0';
		mlx->map->map_items->C_coin--;
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
		return;
	ft_putstr_fd(str, 1);
	ft_putstr_fd("\n", 1);
	free(str);
	free(temp);
}

void	move_right(t_data *mlx)
{
	int	x;
	int	y;

	get_coordinates(mlx->map->lines, &x, &y);
	if (mlx->map->lines[y][x + 1] == '1')
		return ;
	if (mlx->map->lines[y][x + 1] == 'E' && mlx->map->map_items->C_coin != 0)
		return ;
	else if (mlx->map->lines[y][x + 1] == 'E'
		&& mlx->map->map_items->C_coin == 0)
		mlx_loop_end(mlx->ptr);
	else if (mlx->map->lines[y][x + 1] == 'C')
	{
		mlx->map->lines[y][x + 1] = 'P';
		mlx->map->lines[y][x] = '0';
		mlx->map->map_items->C_coin--;
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
	if (mlx->map->lines[y][x - 1] == 'E' && mlx->map->map_items->C_coin != 0)
		return ;
	else if (mlx->map->lines[y][x - 1] == 'E'
		&& mlx->map->map_items->C_coin == 0)
		mlx_loop_end(mlx->ptr);
	else if (mlx->map->lines[y][x - 1] == 'C')
	{
		mlx->map->lines[y][x - 1] = 'P';
		mlx->map->lines[y][x] = '0';
		mlx->map->map_items->C_coin--;
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

int	main(int ac, char **av)
{
	t_data	*mlx;

	if (ac == 2)
	{
		mlx = malloc(sizeof(t_data));
		mlx->map = malloc(sizeof(t_map));
		map_init(mlx->map, av);
		parsing(av, mlx->map);
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
