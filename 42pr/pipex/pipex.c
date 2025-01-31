/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilhasnao <ilhasnao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 11:57:02 by hasnawww          #+#    #+#             */
/*   Updated: 2025/01/31 17:44:42 by ilhasnao         ###   ########.fr       */
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


char	*path_line(char **env)
{
	int		i;
	char	*PATH;

	i = 0;
	PATH = NULL;
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
	return (PATH);
}

char	*get_path(char *cmd, char **envp)
{
	char	**paths;
	char	**big_cmd;
	char	*PATH;
	char	*linked_path;
	char	*final_path;
	int		i;

	PATH = path_line(envp);
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
			return (dree_split(big_cmd), final_path);
		i++;
	}
	dree_split(paths);
	dree_split(big_cmd);
	return(NULL);
}

void	child(int *p, char **av, char **envp)
{
	char 	**big_cmd1;
	int		fd1;

	big_cmd1 = ft_split(av[2], ' ');
	close(p[0]);
	fd1 = open(av[1], O_RDONLY, 0777);
	if (fd1 == -1)
	{
		return ;
	}
	dup2(fd1, 0);
	close(fd1);
	dup2(p[1], 1);
	close(p[1]);
	if (execve(get_path(av[2], envp), big_cmd1, envp) == -1)
	{
		perror("error");
	}
}

void	parent(int *p, char **av, char **envp, int pid)
{
	char	**big_cmd2;
	int		fd2;

	big_cmd2 = ft_split(av[3], ' ');
	close(p[1]);
	fd2 = open(av[4], O_WRONLY | O_CREAT | O_APPEND, 0777);
	if (fd2 == -1)
	{
		return ;
	}
	dup2(fd2, 1);
	close(fd2);
	dup2(p[0], 0);
	close(p[0]);
	waitpid(pid, NULL, 0);
	if (execve(get_path(av[3], envp), big_cmd2, envp) == -1)
	{
		perror("error");
	}
}

int	main(int ac, char **av, char **envp)
{
	int		p[2];
	__pid_t	pid;
	
	pipe(p);
	pid = fork();
	if (ac > 1)
	{
		if (pid == 0)
			child(p, av, envp);
		else
			parent(p, av, envp, pid);
	}
	return (0);
}

