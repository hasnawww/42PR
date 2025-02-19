/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilhasnao <ilhasnao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 19:17:31 by ilhasnao          #+#    #+#             */
/*   Updated: 2025/02/17 17:37:21 by ilhasnao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	map_init(t_map *map, char **av)
{
	map->map_items = malloc(sizeof(t_items));
	map->lines = get_map(av[1]);
	map->height = count_lines(map->lines);
	map->length = ft_strlength(map->lines[0]);
	map->map_items->C_coin = 0;
	map->map_items->E_coin = 0;
	map->copy = map_copy(map->lines);
	get_coordinates(map->copy, &map->x, &map->y);
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
		// ft_putstr_fd(line, 1);
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
