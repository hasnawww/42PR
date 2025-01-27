/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasnawww <hasnawww@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 11:57:02 by hasnawww          #+#    #+#             */
/*   Updated: 2025/01/27 17:59:18 by hasnawww         ###   ########.fr       */
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
	fd1 = open(av[1], O_RDONLY);
	if (fd1 == -1)
	{
		return ;
	}
	dup2(fd1, 0);
	dup2(p[1], 1);
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
	fd2 = open(av[4], 1);
	if (fd2 == -1)
	{
		return ;
	}
	dup2(fd2, 1);
	dup2(p[0], 0);
	if (execve(get_path(av[3], envp), big_cmd2, envp) == -1)
	{
		perror("error");
	}
	waitpid(pid, NULL, 0);
}

// int	main(int ac, char **av, char **envp)
// {
// 	int		**p;
// 	__pid_t	pid;
// 	int		i;
// 	int		j;

// 	j = 0;
// 	i = 2;
// 	p = malloc(sizeof(int) * 2);
// 	while (i < ac - 2)
// 	{
// 		pipe(p[j]);
// 		pid = fork();
// 		if (pid == 0 && i + 1 < ac)
// 			child(p[j], av, envp);
// 		else if (i + 1 < ac)
// 			parent(p[j], av, envp, pid);
// 		j++;
// 	}
// 	free (p);
// 	return (0);
// }

void	processs(char *cmd, char **envp, int fd)
{
	int		p[2];
	pid_t	pid;
	char	**big_cmd;

	pipe(p);
	pid = fork();
	if (pid == 0)
	{
		big_cmd = ft_split(cmd, ' ');
		close(p[0]);
		dup2(p[1], fd);
		if (execve(get_path(cmd, envp), big_cmd, envp) == -1)
		{
			perror("error");
		}
	}
	else
	{
		close(p[1]);
		dup2(p[0], 0);
		waitpid(pid, NULL, 0);
	}
}

int	main(int ac, char **av, char **envp)
{
	int		fd1;
	int		fd2;
	int		i;
	char	**last_cmd;

	i = 3;
	last_cmd = ft_split(av[ac - 2], ' ');
	if (ac >= 5)
	{		
		fd1 = open(av[1], O_RDONLY);
		fd2 = open(av[ac - 1], O_WRONLY | O_CREAT | O_TRUNC);
		if((fd1) < 0|| (fd2) < 0)
		{
			perror("error");
			exit(1);
		}
		dup2(fd1, 0);
		dup2(fd2, 1);
		processs(av[i++], envp, fd1);
		while (i < ac - 2)
			processs(av[i++], envp, 1);
		if (execve(get_path(av[i], envp), last_cmd, envp) == -1)
			perror("error");
	}
	return (0);
}

// int	main(int ac, char **av, char **envp)
// {
// 	char 	**big_cmd1;
// 	// char	**big_cmd2;
// 	int		**p;
// 	__pid_t	child;
// 	int		fd1;
// 	int		fd2;
// 	int		i;
// 	int		j;

// 	j = 0;
// 	i = 2;
// 	if (ac >= 5)
// 	{		
// 		fd1 = open(av[1], O_RDONLY);
// 		fd2 = open(av[ac - 1], O_WRONLY | O_CREAT | O_TRUNC);
// 		p = malloc(sizeof(int *) * (ac - 3));
// 		while (i < ac - 1)
// 		{
// 			if (j != ac -2)
// 			{
// 				p[j] = malloc(sizeof(int) * 2);
// 				pipe(p[j]);
// 			}
// 			child = fork();
// 			if (child == 0)
// 			{
// 				big_cmd1 = ft_split(av[i], ' ');
// 				if (j == 0)
// 				{
// 					dup2(fd1, STDIN_FILENO);
// 					dup2(p[j][1], 1);
// 				}
// 				else if (j == ac - 2)
// 				{
// 					dup2(fd2, STDOUT_FILENO);
// 					dup2(p[j][0], 0);
// 				}
// 				else
// 				{
// 					dup2(p[j - 1][0], 0);
// 					dup2(p[j][1], 1);
// 				}
// 				close(p[j][0]);
// 			   close(p[j][1]);
// 				if (execve(get_path(av[i], envp), big_cmd1, envp) == -1)
// 				{
// 					perror("error");
// 				}
// 			}
// 			else
// 			{
// 				// big_cmd2 = ft_split(av[ac - 2], ' ');
// 				close(p[j][1]);
// 				// fd2 = open(av[ac - 1], 1);
// 				// if (fd2 == -1)
// 				// {
// 				// 	return (0);
// 				// }
// 				// dup2(fd2, 1);
// 				// dup2(p[j][0], 0);
// 				// if (execve(get_path(av[3], envp), big_cmd2, envp) == -1)
// 				// {
// 				// 	perror("error");
// 				// }
// 				waitpid(child, NULL, 0);
// 			}
// 			i++;
// 			j++;
// 		}
// 	  for (int k = 0; k < ac - 3; k++)
//         {
//             free(p[k]);
//         }
//         free(p);
// 		close(fd1);
// 		close(fd2);
// 		return (0);
// 	}
// 	return (1);
// }
