/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasnawww <hasnawww@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 16:20:50 by hasnawww          #+#    #+#             */
/*   Updated: 2025/02/06 18:36:11 by hasnawww         ###   ########.fr       */
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

int	main(int ac, char **av)
{
	int 	i;
	int		fd;
	char	**lines;
	int		size;

	i = 0;
	fd = open(av[1], O_RDONLY);
	size = dbstrlen(fd);
	close(fd);
	fd = open(av[1], O_RDONLY);
	lines = malloc(sizeof(char) * size);
	if (!lines)
	{
		printf("ojui");
		perror("ERROR MALLOC");
		exit(0);
	}
	if (fd == -1)
	{
		perror("ERROR FD");
		exit(0);
	}
	if (ac == 2)
	{
		if (is_ber(av[1]))
		{
				while(i < size){
				lines[i] = get_next_line(fd);
				i++;
				}
				// printf("%s\n", lines[i]);
				int j = 0;
				while (j < i) {
				printf("%s", lines[j]);
				j++;
				}
				printf("\n");
				// free(lines[i]);
		}
			if (check_border(lines[0]) && check_border(lines[i - 1]))
			{
				printf("%d\n", i);
				printf("elleveutelleveut\n");
			}
			else
			{
				printf("elle veut grv pas bahahhaha\n");
			}
		}
	free(lines);
	return(0);
	}
// }
