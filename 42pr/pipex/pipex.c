/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasnawww <hasnawww@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 11:57:02 by hasnawww          #+#    #+#             */
/*   Updated: 2025/01/20 20:52:21 by hasnawww         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void    dree_split(char **result)
{
		int     i;

		i = 0;
		while (result[i])
			free(result[i++]);
		free(result);
}


char	*get_path(char *cmd, char **env)
{
	int		i;
	char	**paths;
	char	*PATH;
	char	*final_path;
	char	**big_cmd;
	char	*linked_path;

	i = 0;
	while (env[i])
	{
		if(ft_strncmp(env[i], "PATH=", 5) == 0)
		{
			PATH = env[i] + 5;
			break;
		}
		i++;
	}
	if (!PATH)
		return (NULL);
	paths = ft_split(PATH, ':');
	big_cmd = ft_split(cmd, ' ');
	if (!paths | !big_cmd)
		return (NULL);
	i = 0;
	while (paths[i])
	{
		linked_path = ft_strjoin(paths[i], "/");
		final_path = ft_strjoin(linked_path, big_cmd[0]);
		free (linked_path);
		if (access(final_path, F_OK) == 0)
		{
			dree_split(big_cmd);
			return (final_path);
		}
		i++;
	}
	dree_split(paths);
	dree_split(big_cmd);
	return(NULL);
}

int	main(int ac, char **av, char **envp)
{
	char 	**big_cmd1;
	char	**big_cmd2;
	int		p[2];
	__pid_t	child;
	int		fd1;
	int		fd2;
	
	printf("eioaw");
	big_cmd1 = ft_split(av[2], ' ');
	big_cmd2 = ft_split(av[3], ' ');
	pipe(p);
	child = fork();
	printf("eioaw");
	if (ac > 1)
	{
		if (child == 0)
		{
			close(p[0]);
			fd1 = open(av[1], O_RDONLY);
			if (fd1 == -1)
			{
				printf("eioaw");
				return (0);
			}
			dup2(fd1, 0);
			dup2(p[1], 1);
			if (execve(get_path(av[2], envp), big_cmd1, envp) == -1)
			{
				perror("error");
			}
		}
		else
		{
			close(p[1]);
			fd2 = open(av[4], 1);
			if (fd2 == -1)
			{
				printf("io");
				return (0);
			}
			dup2(fd2, 1);
			dup2(p[0], 0);
			close(p[1]);
			if (execve(get_path(av[3], envp), big_cmd2, envp) == -1)
			{
				perror("error");
			}
			printf("uies");
			waitpid(child, NULL, 0);
		}
	}
	return (0);
}
