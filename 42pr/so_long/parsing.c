/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilhasnao <ilhasnao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 16:20:50 by hasnawww          #+#    #+#             */
/*   Updated: 2025/02/19 15:17:28 by ilhasnao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"
#include "errordef.h"

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

void	ft_error(t_map *map, char *msg)
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

void	check_characters(t_map *map)
{
	int		i;
	int		j;
	int		E_coin;
	int		P_coin;
	int		C_coin;

	i = 0;
	C_coin = 0;
	E_coin = 0;
	P_coin = 0;
	while(map->lines[i])
	{
		j = 0;
		while(map->lines[i][j])
		{
			if (valid_characters(map->lines[i][j], &C_coin) || map->lines[i][j] == '\n')
				j++;
			else if (duplicate_characters(map->lines[i][j], &E_coin, &P_coin))
				j++;
			else
			{
				ft_error(map, BAD_SYMBOL);
			}
		}
		i++;
	}
	if (E_coin == 0|| P_coin == 0 || C_coin == 0)
	{
		ft_error(map, MISSING_SYMBOL);
	}
}

int	is_rectangular(t_map *map)
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
	int	C;
	int	x;
	int	y;

	x = 0;
	y = 0;
	C = 0;
	while (map[x])
	{
		y = 0;
		while (map[x][y])
		{
			if (map[x][y] == 'C')
				C++;
			y++;
		}
		x++;
	}
	return(C);
}

void	flood_fill(int x, int y, t_map *map)
{
	if (x < 0 || y < 0 || x >= map->height || y >= map->length)
		return ;
	if (map->copy[x][y] == 'V' || map->copy[x][y] == '1')
		return ;
	if (map->copy[x][y] == 'E')
		map->map_items->E_coin = 1;
	if (map->copy[x][y] == 'C')
		map->map_items->C_coin += 1;
	if (map->copy[x][y] == '0' || map->copy[x][y] == 'C')
		map->copy[x][y] = 'V';
	flood_fill(x + 1, y, map);
	flood_fill(x, y + 1, map);
	flood_fill(x - 1, y, map);
	flood_fill(x, y - 1, map);
}

void	parsing(char **av, t_map *map)
{
	int	Cs;

	Cs = get_Cs(map->lines);
	printf("CS = %d\n", Cs);
	if (!is_ber(av[1]))
		ft_error(map, FILE_EXTENSION);
	if (!is_rectangular(map))
		ft_error(map, MAP_FORM);
	check_characters(map);
	if (!((vertical_border(map->lines)) 
			&& (horizontal_border(map->lines[0])) 
				&& (horizontal_border(map->lines[count_lines(map->lines) - 1]))))
		ft_error(map, MAP_BORDER);
	flood_fill(map->x, map->y, map);
	if ((map->map_items->C_coin != Cs)
			&& map->map_items->E_coin != 1)
		ft_error(map, FLOOD_FILL);
}

// int	parsing(char **av, t_map *map)
// {
// 	int	Cs;

// 	Cs = get_Cs(map->lines);
// 	printf("CS = %d\n", Cs);
// 	is_ber(av[1]);
// 	is_rectangular(map);
// 	check_characters(map->lines);
// 	vertical_border(map->lines); 
// 	if (horizontal_border(map->lines[0]);
// 	horizontal_border(map->lines[count_lines(map->lines) - 1]);
// 	flood_fill(map->x, map->y, map);
// 	if ((map->map_items->C_coin != Cs)
// 			&& map->map_items->E_coin != 1)
// 		ft_error(map, FLOOD_FILL);
// }


// int	parsing(char **av, int ac)
// {
// 	t_map	*map;
// 	int		x;
// 	int		y;
// 	int		Cs;

// 	Cs = get_Cs(map->lines);
// 	if (ac == 2)
// 	{
// 		if (is_ber(av[1]))
// 		{
// 			flood_fill(x, y, map);
// 		}
// 		if ((map->map_items->C_coin == Cs)
// 		 && map->map_items->E_coin == 1)
// 			printf("La carte est valide\n");
// 		else
// 			printf("La carte n'est pas valide\n");
// 		printf("%d\n", Cs);
// 	}
// 	return(0);
// }

void	print_map(t_map *map)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (map->copy[x])
	{
		printf("%s", map->copy[x]);
		x++;
	}
}

void	genkidama(t_map *map)
{
	big_free(map->lines);
	big_free(map->copy);
	free(map->map_items);
	free(map);
}

int	main(int ac, char **av)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	if (ac == 2)
	{
		map_init(map, av);
	// if (parsing(av, map))
	// 	printf("la map est valideuh\n");
	// else
	// 	printf("non\n");
		parsing(av, map);
		genkidama(map);
	}
	return(0);
}
