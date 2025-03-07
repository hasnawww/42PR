/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilhasnao <ilhasnao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 16:20:50 by hasnawww          #+#    #+#             */
/*   Updated: 2025/03/07 17:37:19 by ilhasnao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/solong.h"
#include "../../includes/errordef.h"

int	h_b(char *line)
{
	int	i;

	if (!line)
		exit (0);
	i = 0;
	while (line[i] && line[i] != '\n')
	{
		if (line[i] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	vertical_border(char **map)
{
	int	i;
	int	line_len;

	i = 1;
	while (map[i])
	{
		line_len = ft_strlength(map[i]) - 1;
		if ((map[i][0] == '1') && (map[i][line_len] == '1'))
		{
			if (i == count_lines(map))
				break ;
			i++;
		}
		else
		{
			return (0);
		}
	}
	return (1);
}

int	is_rectangular(t_data *map)
{
	int	i;

	i = 0;
	while (map->map->lines[i])
	{
		if (ft_strlength(map->map->lines[i]) != map->map->length)
			return (0);
		i++;
	}
	if (map->map->length > map->map->height
		|| map->map->length < map->map->height)
		return (1);
	return (0);
}
