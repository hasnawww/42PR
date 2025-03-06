/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilhasnao <ilhasnao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 16:20:50 by hasnawww          #+#    #+#             */
/*   Updated: 2025/03/06 17:08:19 by ilhasnao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solongbonus.h"
#include "errordefbonus.h"

int	ft_strlength(const char *c)
{
	int	i;

	i = 0;
	while (c[i] != '\0')
	{
		if (c[i] == '\n')
			break;
		i++;
	}
	return (i);
}

int	is_ber(char *av)
{
	int	j;
	int	i;

	i = 0;
	j = ft_strlength(av) - 4;
	while (i != j - 1)
	{
		i++;
		if (av[i] == '.')
		{
			return(0);
		}
	}
	if (ft_strncmp(&av[j], ".ber", 4) == 0)
		return (1);
	else
		return (0);
}

int count_lines(char **map)
{
	int		line_count;

	line_count = 0;
	while (map[line_count])
	{
		if(map[line_count][0] == '\n')
			break;
		line_count++;
	}
	return (line_count);
}

int horizontal_border(char *line)
{
	int i;

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
		if((map[i][0] == '1') && (map[i][line_len] == '1'))
		{
			if (i == count_lines(map))
				break;
			i++;
		}
		else
		{
			return(0);
		}
	}
	return (1);
}

void	ft_error(t_datab *map, char *msg)
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
		return;
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
	while(mlx->map->lines[i])
	{
		j = 0;
		while(mlx->map->lines[i][j])
		{
			if (valid_charactersb(mlx->map->lines[i][j], &mlx->map->map_items->cc, &mlx->map->map_items->oo) || mlx->map->lines[i][j] == '\n')
				j++;
			else if (duplicate_characters(mlx->map->lines[i][j], &mlx->map->map_items->ee, &mlx->map->map_items->pp))
				j++;
			else
				ft_error(mlx, BAD_SYMBOL_B);
		}
		i++;
	}
	if (mlx->map->map_items->ee == 0|| mlx->map->map_items->pp == 0
			 || mlx->map->map_items->cc == 0 || mlx->map->map_items->oo == 0)
		ft_error(mlx, MISSING_SYMBOL_B);
}

int	is_rectangularb(t_mapb *map)
{
	int	i;
	
	i = 0;
	while (map->lines[i])
	{
		if (ft_strlength(map->lines[i]) != map->length)
			return (0);
		i++;
	}
	if (map->length > map->height || map->length < map->height)
		return (1);
	return (0);
}

int	get_Cs(char **map)
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
	return(c);
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
		map->map_items->E_coin = 1;
	if (map->copy[x][y] == 'C')
		map->map_items->C_coin += 1;
	if (map->copy[x][y] == '0' || map->copy[x][y] == 'C')
		map->copy[x][y] = 'V';
	flood_fillb(x + 1, y, map);
	flood_fillb(x, y + 1, map);
	flood_fillb(x - 1, y, map);
	flood_fillb(x, y - 1, map);
}

void	parsingb(char **av, t_datab *mlx)
{
	int	Cs;

	Cs = get_Cs(mlx->map->lines);
	if (!is_ber(av[1]))
		ft_error(mlx, FILE_EXTENSION_B);
	if (!is_rectangularb(mlx->map))
		ft_error(mlx, MAP_FORM);
	check_charactersb(mlx);
	if (!((vertical_border(mlx->map->lines)) 
			&& (horizontal_border(mlx->map->lines[0])) 
				&& (horizontal_border(mlx->map->lines[count_lines(mlx->map->lines) - 1]))))
		ft_error(mlx, MAP_BORDER_B);
	flood_fillb(mlx->map->y, mlx->map->x, mlx->map);
	if ((mlx->map->map_items->C_coin != Cs)
			&& mlx->map->map_items->E_coin != 1)
		ft_error(mlx, FLOOD_FILL_B);
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
