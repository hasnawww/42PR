/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   get_next_line.c									:+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: ilhasnao <ilhasnao@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/11/25 09:16:49 by ilhasnao		  #+#	#+#			 */
/*   Updated: 2024/11/26 13:26:04 by ilhasnao		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	ft_oldbuffer(char **buffer, char *temp)
{
	char	*old_buffer;

	old_buffer = *buffer;
	*buffer = ft_strjoin(*buffer, temp);
	free(old_buffer);
}

char	*ft_update_buffer(char const *lean, char *buffer)
{
	int		i;
	int		index;
	char	*updated_buffer;

	i = 0;
	while (buffer[i] != '\n' && buffer[i] != '\0')
		i++;
	index = ft_strlen(lean);
	if (buffer[i] == '\0')
	{
		return (ft_free(buffer, NULL));
	}
	i++;
	updated_buffer = malloc(sizeof(char) * (ft_strlen(buffer) - index + 1));
	if (!updated_buffer)
	{
		return (ft_free(buffer, NULL));
	}
	i = 0;
	while (buffer[index] != '\0')
		updated_buffer[i++] = buffer[index++];
	updated_buffer[i] = '\0';
	free(buffer);
	return (updated_buffer);
}

char	*get_next_line(int fd)
{
	static char		*buffer[4096];
	char			*temp;
	char			*line;
	ssize_t			r_b;

	temp = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!temp)
		return (ft_free(buffer[fd], NULL));
	while (!ft_strchr(buffer[fd], '\n'))
	{
		r_b = read(fd, temp, BUFFER_SIZE);
		if (r_b <= 0)
		{
			if (r_b == 0)
				break ;
			return (ft_free(buffer[fd], temp));
		}
		temp[r_b] = '\0';
		ft_oldbuffer(&buffer[fd], temp);
	}
	if (!buffer[fd] || buffer[fd][0] == '\0')
		return (ft_free(buffer[fd], temp));
	line = ft_strdup(buffer[fd]);
	buffer[fd] = ft_update_buffer(line, buffer[fd]);
	return (free(temp), line);
}

// int main(void)
// {
//     int fd1, fd2, fd3;
//     char *line;

//     // Ouvrir plusieurs fichiers pour tester le bonus
//     fd1 = open("file1.txt", O_RDONLY);
//     fd2 = open("file2.txt", O_RDONLY);
//     fd3 = open("file3.txt", O_RDONLY);

//     if (fd1 < 0 || fd2 < 0 || fd3 < 0)
//     {
//         perror("Error opening files");
//         return (1);
//     }

//     printf("=== Reading file1.txt ===\n");
//     line = get_next_line(fd1);
//     while (line)
//     {
//         printf("%s", line);
//         free(line);
//         line = get_next_line(fd1);
//     }

//     printf("\n=== Reading file2.txt ===\n");
//     line = get_next_line(fd2);
//     while (line)
//     {
//         printf("%s", line);
//         free(line);
//         line = get_next_line(fd2);
//     }

//     printf("\n=== Reading file3.txt ===\n");
//     line = get_next_line(fd3);
//     while (line)
//     {
//         printf("%s", line);
//         free(line);
//         line = get_next_line(fd3);
//     }

//     // Fermer les fichiers
//     close(fd1);
//     close(fd2);
//     close(fd3);

//     return (0);
// }
