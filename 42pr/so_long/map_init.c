/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilhasnao <ilhasnao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 19:17:31 by ilhasnao          #+#    #+#             */
/*   Updated: 2025/02/26 20:47:40 by ilhasnao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	map_init(t_map *map, char **av)
{
	if (!(map->map_items = malloc(sizeof(t_items))))
	{
		printf("deosjfpe");
		return (0);
	}
	if (!(map->lines = get_map(av[1])))
	{
		printf("dwadwafdwaf");
		return (0);
	}
	if (!(map->height = count_lines(map->lines)))
	{
		printf("dwadwafdwaf");
		return (0);
	}
	if (!(map->length = ft_strlength(map->lines[0])))
	{
		printf("cxvxcv");
		return (0);
	}
	map->map_items->C_coin = 0;
	map->map_items->E_coin = 0;
	map->copy = map_copy(map->lines);
	get_coordinates(map->copy, &map->x, &map->y);
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
				*x = i;
				*y = j;
				return ;
			}
			j++;
		}
		i++;
	}
}

char **get_map(char *filename)
{
	int fd;
	char **lines;
	int line_count;
	char *line;

	line_count = 0;
	fd = open(filename, O_RDONLY);
	if (fd == -1 || !is_ber(filename))
		ft_error();
	lines = malloc(sizeof(char *) * 1000);
	if (!lines)
		ft_error();	
	while ((line = get_next_line(fd)) != NULL)
	{
		lines[line_count++] = line;
		if (line_count >= 1000)
			ft_error();
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
			break;
		copy[j] = ft_strdup(map[j]);
		j++;
	}
	copy[i] = NULL;
	return (copy);
}
