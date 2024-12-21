/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilhasnao <ilhasnao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 08:41:35 by ilhasnao          #+#    #+#             */
/*   Updated: 2024/12/03 13:30:57 by ilhasnao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char		*s3;
	char		*start;

	s3 = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!s1 && !s2)
		return (NULL);
	if (s3 == NULL)
	{
		if (s1)
			free(s1);
		return (NULL);
	}
	start = s3;
	if (s1)
	{
		while (*s1)
			*s3++ = *s1++;
	}
	if (s2)
	{
		while (*s2)
			*s3++ = *s2++;
	}
	*s3 = '\0';
	return (start);
}

char	*ft_strdup(char *s)
{
	int		i;
	char	*dest;

	if (!s)
	{
		return (NULL);
	}
	dest = malloc(sizeof(char) * ft_strlen(s) + 2);
	i = 0;
	if (dest == NULL)
	{
		return (NULL);
	}
	while (s[i] != '\0' && s[i] != '\n')
	{
		dest[i] = s[i];
		i++;
	}
	if (s[i] == '\n')
	{
		dest[i] = '\n';
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int	ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
		{
			return (1);
		}
		i++;
	}
	return (0);
}

void	*ft_free(char *buffer, char *temp)
{
	if (buffer)
	{
		free(buffer);
		buffer = NULL;
	}
	if (temp)
	{
		free(temp);
	}
	return (NULL);
}
