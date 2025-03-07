/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bonus4.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilhasnao <ilhasnao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 12:02:54 by ilhasnao          #+#    #+#             */
/*   Updated: 2025/03/07 17:37:14 by ilhasnao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/solongbonus.h"
#include "../../includes/errordefbonus.h"

int	ft_strlength(const char *c)
{
	int	i;

	i = 0;
	while (c[i] != '\0')
	{
		if (c[i] == '\n')
			break ;
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
			return (0);
		}
	}
	if (ft_strncmp(&av[j], ".ber", 4) == 0)
		return (1);
	else
		return (0);
}

int	count_lines(char **map)
{
	int	line_count;

	line_count = 0;
	while (map[line_count])
	{
		if (map[line_count][0] == '\n')
			break ;
		line_count++;
	}
	return (line_count);
}
