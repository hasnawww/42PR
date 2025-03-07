/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilhasnao <ilhasnao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 19:17:31 by ilhasnao          #+#    #+#             */
/*   Updated: 2025/03/07 17:37:37 by ilhasnao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/solongbonus.h"
#include "../../includes/errordefbonus.h"

int	map_initb(t_datab *map, char **av)
{
	map->map->map_items = malloc(sizeof(t_itemsb));
	map->map->lines = get_mapb(av[1], map);
	map->map->height = count_lines(map->map->lines);
	map->map->length = ft_strlength(map->map->lines[0]);
	map->map->map_items->ee = 0;
	map->map->map_items->oo = 0;
	map->map->map_items->cc = 0;
	map->map->map_items->pp = 0;
	map->map->map_items->c_coin = 0;
	map->map->map_items->e_coin = 0;
	map->map->copy = map_copy(map->map->lines);
	get_coordinates(map->map->copy, &map->map->x, &map->map->y);
	return (1);
}

void	get_coordinates(char **map, int *x, int *y)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
			{
				*y = i;
				*x = j;
				return ;
			}
			j++;
		}
		i++;
	}
}

void	ft_error_voidb(t_datab *map)
{
	if (map)
		genkidamab(map);
	exit(0);
}

char	**get_mapb(char *filename, t_datab *map)
{
	int		fd;
	char	**lines;
	int		line_count;
	char	*line;

	line_count = 0;
	fd = open(filename, O_RDONLY);
	if (fd == -1 || !is_ber(filename))
		ft_error_voidb(map);
	lines = malloc(sizeof(char *) * 1000);
	if (!lines)
		ft_error_voidb(map);
	line = get_next_line(fd);
	while (line != NULL)
	{
		lines[line_count++] = line;
		if (line_count >= 1000)
			ft_error_voidb(map);
		line = get_next_line(fd);
	}
	lines[line_count] = NULL;
	return (lines);
}

char	**map_copy(char **map)
{
	int		i;
	int		j;
	char	**copy;

	i = 0;
	j = 0;
	while (map[i])
		i++;
	copy = malloc(sizeof(char *) * (i + 1));
	while (map[j])
	{
		if (!map[j])
			break ;
		copy[j] = ft_strdup(map[j]);
		if (!copy[j])
		{
			big_free(copy);
			return (NULL);
		}
		j++;
	}
	copy[i] = NULL;
	return (copy);
}
