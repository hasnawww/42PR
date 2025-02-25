/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilhasnao <ilhasnao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 07:30:49 by ilhasnao          #+#    #+#             */
/*   Updated: 2025/02/24 18:57:17 by ilhasnao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*s3;

	i = 0;
	j = 0;
	s3 = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!s3)
		return (NULL);
	while (i < ft_strlen(s1))
	{
		s3[j] = s1[i];
		j++;
		i++;
	}
	i = 0;
	while (i < ft_strlen(s2))
	{
		s3[j] = s2[i];
		j++;
		i++;
	}
	s3[j] = '\0';
	return (s3);
}

// char	*ft_strjoin(char const *s1, char const *s2)
// {
// 	char		*s3;
// 	char		*start;

// 	s3 = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
// 	if (!s3)
// 	{
// 		// free(s3);
// 		return (NULL);
// 	}
// 	start = s3;
// 	while (*s1)
// 	{
// 		*s3++ = *s1++;
// 	}
// 	while (*s2)
// 	{
// 		*s3++ = *s2++;
// 	}
// 	*s3 = '\0';
// 	return (start);
// }

/*#include <stdio.h>
int	main(void)
{
	char const	s1[] = "dddd";
	char const	s2[] = "pppp";
	char		*boogie = ft_strjoin(s1, s2);

	printf("%s", boogie);
	free (boogie);
	return (0);
}*/
