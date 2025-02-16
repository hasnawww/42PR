/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilhasnao <ilhasnao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 19:17:31 by ilhasnao          #+#    #+#             */
/*   Updated: 2025/02/16 19:18:13 by ilhasnao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	map_init(t_map *map, char **av)
{
	map->map_items = malloc(sizeof(t_items));
	map->lines = get_map(av[1]);
	map->height = count_lines(map->lines);
	map->length = ft_strlen(map->lines[0]) - 1;
	map->map_items->C_coin = 0;
	map->map_items->E_coin = 0;
	map->copy = map_copy(map->lines);
	get_coordinates(map->copy, &map->x, &map->y);
}

