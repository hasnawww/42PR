/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasnawww <hasnawww@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 16:20:50 by hasnawww          #+#    #+#             */
/*   Updated: 2025/02/07 17:51:51 by hasnawww         ###   ########.fr       */
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
	close(fd);
	return (i);
}

int	check_border(char *line)
{
	int	i;

	if (!line)
		exit(0);
	i = 0;
	while (line[i] && line[i] != '0')
	{
		// if (line[i] == '0')
		// 	return (0);
		i++;
	}
	if (line[i] == '0')
			return (0);
	return (1);
}

// int	main(int ac, char **av)
// {
// 	// int	i;
// 	int	fd;
// 	char	*lines = "11111";

// 	// i = 0;
// 	if (ac == 2){
//  	fd = open(av[1], O_RDONLY);
// 	if (!fd)
// 	{
// 		perror("error");
// 		exit(0);
// 	}
// 	if (check_border(lines))
// 	{
// 		printf("ouioui");
// 	}
// 	else
// 	{
// 		printf("non");
// 	}
// 	}
// 	return(0);
// }

void	ft_error()
{
	perror("ERROR MALLOC");
	exit(0);
}

void	get_map(char **av, char ** lines)
{
	int	i;
	int	fd;
	int	size;

	i = 0;
	fd = open(av[1], O_RDONLY);
	size = dbstrlen(fd);
	fd = open(av[1], O_RDONLY);
	lines = malloc(sizeof(char *) * size);
	if (!lines || !fd)
	{
		if (!lines)
			free(lines);
		ft_error();
	}
	if (is_ber(av[1]))
	{
		while(i < size)
		{
			lines[i] = get_next_line(fd);
			i++;
		}
	}
	int j = 0;
	while (j < i) 
	{
	printf("j = %d\n", j);
	printf("%s", lines[3]);
	j++;
	}
	close(fd);
}

int	parsing(char **lines, char **av, int ac)
{
	int	fd;

	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		get_map(av, lines);
		if (is_ber(av[1]))
		{
			if (check_border(lines[0]) && check_border(lines[dbstrlen(fd) - 1]))
			{
				printf("hatem ben arfa > messi");
			}
		}
	}
	return(0);
}

int	main(int ac, char **av)
{
	// int 	i;
	char	**lines;

	// i = 0;
	lines = NULL;
	if (ac == 2)
	{
		parsing(lines, av, ac);
	}
	return(0);
}
// }
