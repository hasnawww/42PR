/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solongbonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilhasnao <ilhasnao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 16:25:31 by hasnawww          #+#    #+#             */
/*   Updated: 2025/03/07 17:51:56 by ilhasnao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLONGBONUS_H
# define SOLONGBONUS_H

# include "../includes/errordefbonus.h"
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdlib.h>
# include "../libft/libft.h"
# include "../mlx/mlx.h"
# include "../mlx/mlx_int.h"

# define ESC 65307
# define TILE_SIZE 64

typedef struct s_itemsb
{
	int			c_coin;
	int			e_coin;
	int			cc;
	int			ee;
	int			pp;
	int			oo;
}	t_itemsb;

typedef struct s_mapb
{
	char			**lines;
	char			**copy;
	int				length;
	int				height;
	int				x;
	int				y;
	t_itemsb		*map_items;
}	t_mapb;

typedef struct s_datab
{
	void	*ptr;
	void	*win;
	void	*wall_frames[4];
	void	*floor_frames[4];
	void	*player_frames[4];
	void	*coin_frames[4];
	void	*exit_frames[4];
	void	*opps_frames[4];
	int		current_frame;
	int		frame_counter;
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
	t_mapb	*map;
}	t_datab;

void	ft_errorb(t_datab *map, char *msg);
int		map_initb(t_datab *map, char **av);
void	get_coordinates(char **map, int *x, int *y);
int		ft_strlength(const char *c);
int		count_lines(char **map);
char	**get_mapb(char *filename, t_datab *map);
int		is_ber(char *av);
int		h_bb(char *line);
int		vertical_border(char **map);
void	ft_error_voidb(t_datab *map);
void	big_free(char **map);
int		valid_characters(char c, int *C_coin);
int		duplicate_characters(char c, int *E_coin, int *P_coin);
void	check_charactersb(t_datab *mlx);
int		is_rectangularb(t_mapb *map);
int		get_cs(char **map);
char	**map_copy(char **map);
void	flood_fillb(int x, int y, t_mapb *map);
void	parsingb(char **av, t_datab *map);
void	print_map(char **map);
void	genkidamab(t_datab *map);
int		close_win(int keycode, void *mlx);
void	move_rightb(t_datab *mlx);
void	move_leftb(t_datab *mlx);
void	move_upb(t_datab *mlx);
void	move_downb(t_datab *mlx);
void	move_writingb(t_datab *mlx);
void	update_camb(t_datab *mlx);
void	init_camb(t_datab *mlx);
void	destroy_frames(t_datab *mlx);
void	init_frames1(t_datab *mlx);
void	init_frames2(t_datab *mlx);
void	put_imageb(char c, t_datab *mlx, int i, int j);
void	render_mapb(char **map, t_datab *mlx);
int		on_keypressb(int keycode, t_datab *mlx);
int		free_allb(t_datab *mlx);
void	moves(t_datab *mlx);
int		map_initb(t_datab *map, char **av);
void	init_windowb(t_datab *mlx);
int		update_anim(t_datab *mlx);
void	my_mlx_initb(t_datab *mlx);

#endif