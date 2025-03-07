/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilhasnao <ilhasnao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 11:54:33 by ilhasnao          #+#    #+#             */
/*   Updated: 2025/03/07 17:37:28 by ilhasnao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/solong.h"
#include "../../includes/errordef.h"

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

void	flood_fill(int x, int y, t_map *map)
{
	if (x < 0 || y < 0 || x >= map->height || y >= map->length)
		return ;
	if (map->copy[x][y] == 'V' || map->copy[x][y] == '1')
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
	flood_fill(x + 1, y, map);
	flood_fill(x, y + 1, map);
	flood_fill(x - 1, y, map);
	flood_fill(x, y - 1, map);
}

void	parsing(char **av, t_data *map)
{
	int	cs;

	cs = get_cs(map->map->lines);
	if (!is_ber(av[1]))
		ft_error(map, FILE_EXTENSION);
	if (!is_rectangular(map))
		ft_error(map, MAP_FORM);
	check_characters(map);
	if (!((vertical_border(map->map->lines))
			&& (h_b(map->map->lines[0]))
			&& (h_b(map->map->lines[count_lines(map->map->lines) - 1]))))
		ft_error(map, MAP_BORDER);
	flood_fill(map->map->y, map->map->x, map->map);
	if ((map->map->map_items->c_coin != cs)
		|| map->map->map_items->e_coin != 1)
		ft_error(map, FLOOD_FILL);
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

void	genkidama(t_data *map)
{
	if (map->map->lines)
		big_free(map->map->lines);
	if (map->map->copy)
		big_free(map->map->copy);
	if (map->map->map_items)
		free(map->map->map_items);
	free(map->map);
	if (map)
		free(map);
}
