/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilhasnao <ilhasnao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 09:16:49 by ilhasnao          #+#    #+#             */
/*   Updated: 2024/11/26 11:47:21 by ilhasnao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"
#include <stdlib.h>
#include <unistd.h>

char	*ft_get_next_line(int fd)
{
		char	*zumba;
		char	mem;
		int		i;
		ssize_t	r_b;

		i = 0;
		zumba = malloc(sizeof(char) * BUFFER_SIZE);
		// mem = malloc(1024);
		// if (!mem)
		// {
		// 	printf("erreur mem");
		// 	return (NULL);
		// }
		if (fd == -1)
		{
			printf("t'es juste un mec chill qui apprend a du mal a ouvrir un fichier");
		}
		if (!zumba)
		{
			printf("non");
			return (0);
		}
		while ((r_b = read(fd, &mem, 1)) > 0)
		{
			if (mem == '\n' || mem == '\0')
			{
				break;
			}
			zumba[i++] = mem;
			if (i >= BUFFER_SIZE - 1)
			{
				break;
			}
		}
		if (r_b == -1 || r_b == 0)
		{
			printf("stop read");
			free (zumba);
			return (NULL);
		}
		zumba[i] = '\0';
		return (zumba);
}

int	main(void)
{
	const char	*filename = "Bomboclaat.txt";
	int			fd;
	char		*line;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		perror("Error opening file");
		return (1);
	}

	while ((line = ft_get_next_line(fd)) != NULL)
	{
		printf("%s\n", line);
		free(line);
	}

	close(fd);
	return (0);
}

int main(void)
{
	int fd = open("Bomboclaat.txt", O_RDWR);
	// int	nb_read;
	char	*zumba = malloc(sizeof(char) * BUFFER_SIZE);
	// char	buffer[1024];

	printf("fd = %d\n", fd);
	if (!fd)
	{
		printf("ca marche pas mec");
		return (-1);
	}
	// ft_get_next_line(fd);
	int	bobo = read(fd, zumba, BUFFER_SIZE);
	printf("nb_char = %d\n", bobo);
	printf(".txt = %s\n", zumba);
	free(zumba);
	return (0);
}