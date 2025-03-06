/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilhasnao <ilhasnao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 14:17:10 by ilhasnao          #+#    #+#             */
/*   Updated: 2025/03/06 17:34:08 by ilhasnao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "errordefbonus.h"
#include "solongbonus.h"

int	on_keypress(int keycode, t_datab *mlx)
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
	// if (!mlx->wall_frames || !mlx->floor_frames || !mlx->player_frames)
	// {
	// 	ft_putstr_fd("Error: Failed to load textures\n", 2);
	// 	mlx_loop_end(mlx->ptr);
	// }
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
	mlx->win = mlx_new_window(mlx->ptr, mlx->cam_length * 64, mlx->cam_height * 64, "So long");
	if (!mlx->win)
	{
		ft_putstr_fd("Error: Failed to create window\n", 2);
		mlx_loop_end(mlx->ptr);
	}
	mlx->move_count = 0;
	move_writingb(mlx);
}

void	put_image(char c, t_datab *mlx, int i, int j)
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
				put_image(map[i][j], mlx, i, j);
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
	while (i < 3)
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
	mlx->frame_counter++;
	if (mlx->frame_counter >= 10000)
	{
		mlx->current_frame = (mlx->current_frame + 1) % 3;
		mlx->frame_counter = 0;
		render_mapb(mlx->map->lines,mlx);
	}
	return (0);
}

int	free_all (t_datab *mlx)
{
	destroy_frames(mlx);
	if (mlx->ptr)
	{
		mlx_destroy_display(mlx->ptr);
		free(mlx->ptr);
	}
	if (mlx->map)
		genkidamab(mlx);
cd 	exit(0);
	return (0);
}

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
	moves(mlx);
}

void	move_writingb(t_datab *mlx)
{
	char	*str;
	char	*temp;

	temp = ft_itoa(mlx->move_count);
	str = ft_strjoin("number of moves: ", temp);
	if (!str)
		return;
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
	moves(mlx);
}

void	move_leftb(t_datab *mlx)
{
	int	x;
	int	y;

	get_coordinates(mlx->map->lines, &x, &y);
	if (mlx->map->lines[y][x - 1] == 'O')
		mlx_loop_end(mlx->ptr);
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
	moves(mlx);
}

void	init_camb(t_datab *mlx)
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

void	update_camb(t_datab *mlx)
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
	t_datab	*mlx;

	if (ac == 2)
	{
		mlx = malloc(sizeof(t_datab));
		mlx->map = malloc(sizeof(t_map));
		map_initb(mlx->map, av);
		parsingb(av, mlx);
		my_mlx_initb(mlx);
		init_windowb(mlx);
		render_mapb(mlx->map->lines, mlx);
		mlx_key_hook(mlx->win, on_keypress, mlx);
		mlx_hook(mlx->win, 17, 0, free_all, mlx);
		mlx_loop_hook(mlx->ptr, update_anim, mlx);
		mlx_loop(mlx->ptr);
		free_all(mlx);
	}
	return (0);
}
