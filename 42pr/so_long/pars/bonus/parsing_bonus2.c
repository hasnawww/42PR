/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bonus2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilhasnao <ilhasnao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 11:58:56 by ilhasnao          #+#    #+#             */
/*   Updated: 2025/03/07 17:37:06 by ilhasnao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/solongbonus.h"
#include "../../includes/errordefbonus.h"

void	ft_errorb(t_datab *map, char *msg)
{
	if (map)
		genkidamab(map);
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

int	valid_charactersb(char c, int *C_coin, int *O_coin)
{
	if (c == 'C' && *C_coin == 0)
	{
		*C_coin = 1;
		return (1);
	}
	if (c == 'O' && *O_coin == 0)
	{
		*O_coin = 1;
		return (1);
	}
	if (c == '1' || c == '0' || c == 'C' || c == 'O')
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

void	check_charactersb(t_datab *mlx)
{
	int		i;
	int		j;

	i = 0;
	while (mlx->map->lines[i])
	{
		j = 0;
		while (mlx->map->lines[i][j])
		{
			if (valid_charactersb(mlx->map->lines[i][j],
				&mlx->map->map_items->cc, &mlx->map->map_items->oo)
				|| mlx->map->lines[i][j] == '\n')
				j++;
			else if (duplicate_characters(mlx->map->lines[i][j],
				&mlx->map->map_items->ee, &mlx->map->map_items->pp))
				j++;
			else
				ft_errorb(mlx, BAD_SYMBOL_B);
		}
		i++;
	}
	if (mlx->map->map_items->ee == 0 || mlx->map->map_items->pp == 0
		|| mlx->map->map_items->cc == 0 || mlx->map->map_items->oo == 0)
		ft_errorb(mlx, MISSING_SYMBOL_B);
}
