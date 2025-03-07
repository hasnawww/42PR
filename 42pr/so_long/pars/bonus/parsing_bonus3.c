/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bonus3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilhasnao <ilhasnao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 12:01:15 by ilhasnao          #+#    #+#             */
/*   Updated: 2025/03/07 17:37:11 by ilhasnao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/solongbonus.h"
#include "../../includes/errordefbonus.h"

int	get_cs(char **map)
{
	int	c;
	int	x;
	int	y;

	x = 0;
	y = 0;
	c = 0;
	while (map[x])
	{
		y = 0;
		while (map[x][y])
		{
			if (map[x][y] == 'C')
				c++;
			y++;
		}
		x++;
	}
	return (c);
}

void	flood_fillb(int x, int y, t_mapb *map)
{
	if (x < 0 || y < 0 || x >= map->height || y >= map->length)
		return ;
	if (map->copy[x][y] == 'V' || map->copy[x][y] == '1')
		return ;
	if (map->copy[x][y] == 'O')
		return ;
	if (map->copy[x][y] == 'E')
	{
		map->map_items->e_coin = 1;
		return ;
	}
	if (map->copy[x][y] == 'C')
		map->map_items->c_coin += 1;
	if (map->copy[x][y] == '0' || map->copy[x][y] == 'C')
		map->copy[x][y] = 'V';
	flood_fillb(x + 1, y, map);
	flood_fillb(x, y + 1, map);
	flood_fillb(x - 1, y, map);
	flood_fillb(x, y - 1, map);
}

void	parsingb(char **av, t_datab *mlx)
{
	int	cs;

	cs = get_cs(mlx->map->lines);
	if (!is_ber(av[1]))
		ft_errorb(mlx, FILE_EXTENSION_B);
	if (!is_rectangularb(mlx->map))
		ft_errorb(mlx, MAP_FORM);
	check_charactersb(mlx);
	if (!((vertical_border(mlx->map->lines))
			&& (h_bb(mlx->map->lines[0]))
			&& (h_bb(mlx->map->lines[count_lines(mlx->map->lines) - 1]))))
		ft_errorb(mlx, MAP_BORDER_B);
	flood_fillb(mlx->map->y, mlx->map->x, mlx->map);
	if ((mlx->map->map_items->c_coin != cs)
		|| mlx->map->map_items->e_coin != 1)
		ft_errorb(mlx, FLOOD_FILL_B);
}

void	print_map(char **map)
{
	int	x;
	int	y;

	x = 0;
	while (map[x])
	{
		y = 0;
		while (map[x][y])
		{
			ft_putchar_fd(map[x][y], 1);
			y++;
		}
		x++;
	}
}

void	genkidamab(t_datab *map)
{
	if (map->map->lines)
		big_free(map->map->lines);
	if (map->map->copy)
		big_free(map->map->copy);
	if (map->map->map_items)
		free(map->map->map_items);
	free(map->map);
	free(map);
}
