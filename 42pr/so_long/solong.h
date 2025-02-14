/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilhasnao <ilhasnao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 16:25:31 by hasnawww          #+#    #+#             */
/*   Updated: 2025/02/14 15:04:40 by ilhasnao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef SOLONG_H
# define SOLONG_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdlib.h>
# include "libft/libft.h"

typedef struct s_items
{
	int			C_coin;
	int			E_coin;
	int			P_coin;
}	t_items;

typedef struct s_map
{
	char			**lines;
	int				i;
	int				y;
	t_items			*map_items;
}	t_map;

#endif