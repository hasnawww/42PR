/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilhasnao <ilhasnao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 06:57:00 by ilhasnao          #+#    #+#             */
/*   Updated: 2024/11/18 10:17:34 by ilhasnao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

int	count_words(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		while (s[i] && s[i] == c)
		{
			i++;
		}
		if (s[i] && s[i] != c)
		{
			count++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (count);
}

static size_t	word_len(char const	*s, char c)
{
	int	j;

	j = 0;
	while (s[j] && s[j] != c)
	{
		j++;
	}
	return (j);
}

char	**ft_split(char const *s, char c)
{
	char		**result;
	size_t		len;
	size_t		i;
	size_t		j;

	i = 0;
	j = 0;
	result = malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!result || !s)
		return (NULL);
	while (s[i] != '\0')
	{
		while (s[i] != '\0' && s[i] == c)
			i++;
		len = word_len(&s[i], c);
		if (s[i] != '\0')
		{
			result[j] = ft_substr(s, i, len);
			j++;
			i = i + len;
		}
	}
	result[j] = NULL;
	return (result);
}

// #include <stdio.h>
// void print_split(char **result)
//  {
//     int i = 0;
//     while (result[i]) {
//         printf("Word %d: %s$\n", i, result[i]);
//         i++;
//     }
// }
// int main() 
// {
//     char **result;

//     // Cas standard avec plusieurs mots
//     result = ft_split("       Hello world    from ft_split", ' ');
//     printf("Test 1:\n");
//     print_split(result);

//     // Cas avec des délimiteurs consécutifs
//     result = ft_split("Hello,,world,,ft_split", ',');
//     printf("\nTest 2:\n");
//     print_split(result);

//     // Cas avec des espaces au début et à la fin
//     result = ft_split("   Leading and trailing spaces   ", ' ');
//     printf("\nTest 3:\n");
//     print_split(result);

//     // Cas avec un seul mot
//     result = ft_split("OnlyOneWord", ' ');
//     printf("\nTest 4:\n");
//     print_split(result);

//     // Cas avec une chaîne vide
//     result = ft_split("", ' ');
//     printf("\nTest 5:\n");
//     print_split(result);

//     // Cas avec des espaces et tabulations multiples
//     result = ft_split("   Mixed \t delimiters\t and spaces   ", ' ');
//     printf("\nTest 6:\n");
//     print_split(result);

//     return 0;
// }