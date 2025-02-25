/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilhasnao <ilhasnao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 07:41:24 by ilhasnao          #+#    #+#             */
/*   Updated: 2025/02/24 09:40:47 by ilhasnao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	dree_split(char **result)
{
	int	i;

	i = 0;
	while (result[i])
		free(result[i++]);
	free(result);
}

char	*path_line(char **env)
{
	int		i;
	char	*path;

	i = 0;
	path = NULL;
	while (env[i])
	{
		if (ft_strncmp(env[i], "PATH=", 5) == 0)
		{
			path = env[i] + 5;
			break ;
		}
		i++;
	}
	if (!path)
		return (NULL);
	return (path);
}

char	*get_path(char *cmd, char **envp)
{
	char	**paths;
	char	**big_cmd;
	char	*linked_path;
	char	*final_path;
	int		i;

	paths = ft_split(path_line(envp), ':');
	big_cmd = ft_split(cmd, ' ');
	if (!paths | !big_cmd)
		return (dree_split(paths), dree_split(big_cmd), NULL);
	i = 0;
	while (paths[i])
	{
		linked_path = ft_strjoin(paths[i], "/");
		final_path = ft_strjoin(linked_path, big_cmd[0]);
		free (linked_path);
		if (access(final_path, F_OK) == 0)
			return (dree_split(big_cmd), dree_split(paths), final_path);
		free (final_path);
		i++;
	}
	return (dree_split(paths), dree_split (big_cmd), NULL);
}
