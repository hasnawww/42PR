/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilhasnao <ilhasnao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 11:53:33 by ilhasnao          #+#    #+#             */
/*   Updated: 2025/03/07 17:37:24 by ilhasnao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/solong.h"
#include "../../includes/errordef.h"

void	ft_error(t_data *map, char *msg)
{
	if (map)
		genkidama(map);
	ft_putstr_fd("ERROR: ", 2);
	ft_putstr_fd(msg, 2);
	ft_putstr_fd("\n", 2);
	exit(0);
}

void	big_free(char **map)
{
	int	i;

	i = 0;
	if (!map)
		return ;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

int	valid_characters(char c, int *C_coin)
{
	if (c == 'C' && *C_coin == 0)
	{
		*C_coin = 1;
		return (1);
	}
	if (c == '1' || c == '0' || c == 'C')
	{
		return (1);
	}
	return (0);
}

int	duplicate_characters(char c, int *E_coin, int *P_coin)
{
	if (c == 'E' && *E_coin == 0)
	{
		*E_coin = 1;
		return (1);
	}
	else if (c == 'P' && *P_coin == 0)
	{
		*P_coin = 1;
		return (1);
	}
	return (0);
}

void	check_characters(t_data *map)
{
	int		i;
	int		j;

	i = 0;
	while (map->map->lines[i])
	{
		j = 0;
		while (map->map->lines[i][j])
		{
			if (valid_characters(map->map->lines[i][j], &map->map->map_items->c)
								|| map->map->lines[i][j] == '\n')
				j++;
			else if (duplicate_characters(map->map->lines[i][j],
				&map->map->map_items->e, &map->map->map_items->p))
				j++;
			else
				ft_error(map, BAD_SYMBOL);
		}
		i++;
	}
	if (map->map->map_items->e == 0 || map->map->map_items->p == 0
		|| map->map->map_items->c == 0)
		ft_error(map, MISSING_SYMBOL);
}
