/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilhasnao <ilhasnao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 16:25:31 by hasnawww          #+#    #+#             */
/*   Updated: 2025/02/17 15:24:19 by ilhasnao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef SOLONG_H
# define SOLONG_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdlib.h>
# include "libft/libft.h"

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

void	map_init(t_map *map, char **av);
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
int		check_characters(char **map);
int		is_rectangular(char **map);
int		get_Cs(char **map);
char	**map_copy(char **map);
void	flood_fill(int x, int y, t_map *map);
int		parsing(char **av, t_map *map);
void	print_map(t_map *map);
void	genkidama(t_map *map);

#endif