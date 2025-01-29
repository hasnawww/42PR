/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasnawww <hasnawww@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 11:57:02 by hasnawww          #+#    #+#             */
/*   Updated: 2025/01/29 23:25:09 by hasnawww         ###   ########.fr       */
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

	big_cmd1 = ft_split(av[3], ' ');
	close(p[0]);
	dup2(p[1], 1);
	close(p[1]);
	if (execve(get_path(av[3], envp), big_cmd1, envp) == -1)
	{
		perror("error");
	}
}

void	parent(int *p, char **av, char **envp, int pid)
{
	char	**big_cmd2;
	int		fd2;

	big_cmd2 = ft_split(av[4], ' ');
	close(p[1]);
	fd2 = open(av[5], O_WRONLY | O_CREAT | O_TRUNC, 0666);
	if (fd2 == -1)
	{
		return ;
	}
	dup2(fd2, 1);
	dup2(p[0], 0);
	close(p[0]);
	waitpid(pid, NULL, 0);
	if (execve(get_path(av[4], envp), big_cmd2, envp) == -1)
	{
		perror("error");
		exit(1);
	}
}

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

// void	here_doc(char **av, char **env)
// {
// 	char	*line;
// 	int		p[2];
// 	int		pid;
// 	// int		zumba;
// 	// int		fd;

// 	pipe(p);
// 	// fd = open("file3.txt", O_RDWR | O_CREAT | O_APPEND, 0666);
// 	// if(fd == -1)
// 	// {
// 	// 	perror("error");
// 	// 	exit(1);
// 	// }
// 	// zumba = 0;
// 	pid = fork();
// 	if (pid == 0)
// 	{
// 		close(p[0]);
// 		while(1)
// 		{
// 			line = get_next_line(0);
// 			if (!line)
// 			break;
// 			if (ft_strncmp(line, av[2], ft_strlen(av[2])) == 0)
// 			{
// 				free(line);
// 				break;
// 			}
// 			write(p[1], line, ft_strlen(line));
// 			free(line);
// 		}
// 		dup2(p[0], 0);
// 		close(p[0]);
// 		child(p, av, env);
// 	}
// 	else
// 	{
// 		parent(p, av, env, pid);
// 	}
// }

void	here_doc(char *limiter)
{
	pid_t	reader;
	int		fd[2];
	char	*line;

	reader = fork();
	pipe(fd);
	if (reader == 0)
	{
		while(1)
		{
			line = get_next_line(0);
			if (!line)
			break;
			if (ft_strncmp(line, limiter, ft_strlen(limiter)) == 0)
			{
				free(line);
				break;
			}
			write(fd[1], line, ft_strlen(line));
			free(line);
		}
	}
	else
	{
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		wait(NULL);
	}
}

int	main(int ac, char **av, char **envp)
{
	int		fd1;
	int		fd2;
	int		i;
	char	**last_cmd;
	// int		pid;

	i = 3;
	last_cmd = ft_split(av[ac - 2], ' ');
	fd1 = open(av[1], O_RDONLY);
	fd2 = open(av[ac - 1], O_WRONLY | O_CREAT | O_APPEND);
	if (ac >= 5 && ft_strncmp(av[1], "here_doc", ft_strlen("here_doc")) == 0)
	{
		here_doc(av[2]);
		while (i < ac - 2)
			processs(av[i++], envp, 1);
		dup2(fd2, STDOUT_FILENO);
		if (execve(get_path(av[ac - 2], envp), last_cmd, envp) == -1)
			perror("error");
	}
	else
	{
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
