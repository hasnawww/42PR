/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasnawww <hasnawww@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 16:25:31 by hasnawww          #+#    #+#             */
/*   Updated: 2025/03/01 17:21:07 by hasnawww         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef SOLONG_H
# define SOLONG_H

#include "errordef.h"
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdlib.h>
# include "libft/libft.h"
# include "mlx/mlx.h"
# include "mlx/mlx_int.h"

#define ESC 65307
#define TILE_SIZE 64

typedef struct s_items
{
	int			C_coin;
	int			E_coin;
	int			P_coin;
}	t_items;

typedef struct s_map
{
	char			**lines;
	char			**copy;
	int				length;
	int				height;
	int				x;
	int				y;
	t_items			*map_items;
}	t_map;


typedef struct s_data {
	void	*ptr;
	void	*win;
	void	*wall;
	void	*floor;
	void	*player;
	void	*coin;
	void	*exit;
	char	*path_exit;
	char	*path_coin;
	char	*path_wall;
	char	*path_floor;
	char	*path_player;
	int		win_y;
	int		win_x;
	int		img_x;
	int		img_y;
	int		move_count;
	int		first_token;
	int		cam_x;
	int		cam_y;
	int		cam_length;
	int		cam_height;
	t_map	*map;
}	t_data;

int		map_init(t_map *map, char **av);
void	get_coordinates(char **map, int *x, int *y);
int		ft_strlength(const char *c);
int		count_lines(char **map);
char	**get_map(char *filename);
int		is_ber(char *av);
int		horizontal_border(char *line);
int		vertical_border(char **map);
void	ft_error();
void	big_free(char **map);
int		valid_characters(char c, int *C_coin);
int		duplicate_characters(char c, int *E_coin, int *P_coin);
void	check_characters(t_map *map);
int		is_rectangular(t_map *map);
int		get_Cs(char **map);
char	**map_copy(char **map);
void	flood_fill(int x, int y, t_map *map);
void	parsing(char **av, t_map *map);
void	print_map(char **map);
void	genkidama(t_map *map);
int		close_win(int keycode, void *mlx);
void	move_right(t_data *mlx);
void	move_left(t_data *mlx);
void	move_up(t_data *mlx);
void	move_down(t_data *mlx);
void	move_writing(t_data *mlx);
void	update_cam(t_data *mlx);
void	init_cam(t_data *mlx);

#endif