/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilhasnao <ilhasnao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 16:20:50 by hasnawww          #+#    #+#             */
/*   Updated: 2025/02/08 20:29:57 by ilhasnao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	is_ber(char *av)
{
	int	j;
	int	i;

	i = 0;
	j = ft_strlen(av) - 4;
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

// PROBLEME AVEC COUNT LINES ET TT CA

int	dbstrlen(int fd)
{
	int		i;
	char	*line;

	i = 0;
	while((line = get_next_line(fd)))
	{
		i++;
		free(line);
	}
	return (i);
}

int count_lines(const char *filename)
{
    int     fd;
    int     line_count;
    char    *line;

    fd = open(filename, O_RDONLY);
    if (fd < 0)
        return -1;  // Error opening file

    line_count = 0;
    while ((line = get_next_line(fd)) != NULL)
    {
        line_count++;
        free(line);
    }
    close(fd);

    return line_count;
}

int	check_border(char *line)
{
	int	i;

	if (!line)
		exit(0);
	i = 0;
	while (line[i] && line[i] != '0')
	{
		i++;
	}
	if (line[i] == '0')
			return (0);
	return (1);
}

void	ft_error()
{
	perror("ERROR MALLOC");
	exit(0);
}

char **get_map(char *filename)
{
	int fd;
	char **lines;
	int line_count = 0;
	char *line;

	fd = open(filename, O_RDONLY);
	if (fd == -1 || !is_ber(filename))
	{
		ft_error();
	}

	lines = malloc(sizeof(char *) * 1000); // Still using a fixed size, consider dynamic allocation
	if (!lines)
	{
		ft_error();
		close(fd);
		return NULL;
	}

	while ((line = get_next_line(fd)) != NULL)
	{
		lines[line_count++] = line;
		ft_putstr_fd(line, 1);
		if (line_count >= 1000) // Safety check
		{
			ft_error();
			break;
		}
	}
	lines[line_count] = NULL; // Null-terminate the array
	close(fd);
	return lines;
}

int	parsing(char **av, int ac)
{
	int	fd;
	char **map;

	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		map = get_map(av[1]);
		if (is_ber(av[1]))
		{
			if (check_border(map[0]) && check_border(map[3]))
			{
				ft_putstr_fd("oui\n", 1);
			}
		}
		free(map);
	}
	return(0);
}

int	main(int ac, char **av)
{
	// int 	i;

	if (ac == 2)
	{
		parsing(av, ac);
	}
	return(0);
}
