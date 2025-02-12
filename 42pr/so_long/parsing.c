/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilhasnao <ilhasnao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 16:20:50 by hasnawww          #+#    #+#             */
/*   Updated: 2025/02/11 18:37:01 by ilhasnao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

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
		line_len = ft_strlength(map[i]) - 2;
		if((map[i][0] == '1') && (map[i][line_len] == '1'))
		{
			if (i == count_lines(map))
				break;
			i++;
		}
		else
		{
			printf("\ngrrrrr\n");
			return(0);
		}
	}
	return (1);
}

void	ft_error()
{
	perror("ERROR");
	exit(0);
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
		ft_putstr_fd(line, 1);
		if (line_count >= 1000)
			ft_error();
	}
	lines[line_count] = NULL;
	return (lines);
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

int	valid_characters(char c)
{
	if (c == '1' || c == '0' || c == 'C')
	{
		return (1);
	}
	return (0);
}

int	duplicate_characters(char c, int E_coin, int P_coin)
{
	if (c == 'E' && E_coin == 0)
	{
		printf("\njousuila\n");
		E_coin = 1;
		return (1);
	}
	else if (c == 'P' && P_coin == 0)
	{
		printf("\njousuila\n");
		P_coin = 1;
		return (1);
	}
	return (0);
}

int	check_characters(char **map)
{
	int	i;
	int	j;
	int	E_coin;
	int	P_coin;

	j = 0;
	i = 0;
	E_coin = 0;
	P_coin = 0;
	while(map[i])
	{
		while(map[i][j])
		{
			if (valid_characters(map[i][j]) || map[i][j] == '\n')
				j++;
			else if (duplicate_characters(map[i][j], E_coin, P_coin))
			{
				printf("fewfwf\n");
				j++;
			}
			else
			{
				return(0);
			}
		}
		i++;
	}
	if (E_coin == 0|| P_coin == 0)
	{
		return(0);
	}
	return (1);
}

int	is_rectangular(char **map)
{
	int	line;
	
	line = 0;
	printf("\nlines = %d\n", count_lines(map));
	while (map[line])
	{
		if ((line) == count_lines(map) - 1)
			break;
		printf("strlen de line = %d\n", ft_strlength(map[line]));
		printf("strlen de line + 1 = %d\n", ft_strlength(map[line + 1]));
		if (ft_strlength(map[line]) != ft_strlength(map[line + 1]))
			return(0);
		line++;
	}
	if (ft_strlength(map[0]) < count_lines(map) || ft_strlength(map[0]) > count_lines(map))
		return (1);
	return (0);
}

int	parsing(char **av, int ac)
{
	char	**map;
	int		i;

	map = get_map(av[1]);
	i = count_lines(map);
	if (ac == 2)
	{
		if (is_ber(av[1]))
		{
			if (!check_characters(map))
			{
				ft_putstr_fd("\nnon\n", 1);
			}
		}
		big_free(map);
	}
	return(0);
}

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		parsing(av, ac);
	}
	return(0);
}
