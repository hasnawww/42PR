/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasnawww <hasnawww@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 11:57:02 by hasnawww          #+#    #+#             */
/*   Updated: 2025/02/03 15:38:30 by hasnawww         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipexbonus.h"

void	dree_split(char **result)
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
			break ;
		}
		i++;
	}
	if (!PATH)
		exit(1);
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

void	processs(char *cmd, char **envp, int *p)
{
	pid_t	pid;
	char	**big_cmd;

	if (pipe(p) == -1)
	{	
		perror("error");
		exit(1);
	}
	pid = fork();
	if (pid == 0)
	{
		close(p[0]);
		big_cmd = ft_split(cmd, ' ');
		dup2(p[1], 1);
		if (execve(get_path(cmd, envp), big_cmd, envp) == -1)
		{
			perror("error");
			exit(1);
		}
	}
	else
	{
		close(p[1]);
		dup2(p[0], 0);
	}
}

void	last_process(char **av, char **env, int *p, int ac)
{
	char	**last_cmd;
	
	last_cmd = ft_split(av[ac - 2], ' ');
	dup2(p[0], STDIN_FILENO);
	close(p[0]);
	close(p[1]);
	if(execve(get_path(av[ac - 2], env), last_cmd, env) == -1)
	{
		perror("error");
		exit(1);
	}
}

void	here_doc(char **av)
{
	int		pid;
	int		p[2];

	if(pipe(p) == -1)
	{
		perror("error");
		exit(1);
	}
	pid = fork();
	if (pid == 0)
	{
		if (!get_line(av[2], p))
		{
			close(p[1]);
			dup2(p[0], 0);
			wait(NULL);
		}
	}
	else
	{
		close(p[1]);
		dup2(p[0], 0);
		wait(NULL);
	}
}

int	get_line(char *limiter, int *p)
{
	char	*line;

	limiter = ft_strjoin(limiter, "\n");
	if(!(limiter))
	{
		perror("error");
		exit(1);
	}
	while(1)
	{
		line = get_next_line(0);
		if (!line)
			exit (-1);
		if (ft_strncmp(line, limiter, ft_strlen(limiter)) == 0)
		{
			free(line);
			get_next_line(-1);
			free(limiter);
			exit(1);
		}
		ft_putstr_fd(line, p[1]);
		free(line);
	}
	return (0);
}

void	ft_error()
{
	perror("error");
	exit(1);
}

int	main(int ac, char **av, char **envp)
{
	int		fd1;
	int		fd2;
	int		i;
	int		p[2];

	if (ac >= 5 && ft_strncmp(av[1], "here_doc", ft_strlen("here_doc")) == 0)
	{
		i = 3;
		here_doc(av);
		fd2 = open(av[ac - 1], O_WRONLY | O_CREAT | O_APPEND, 0777);
	}
	else if (ac >= 5)
	{
		fd1 = open(av[1], O_RDONLY, 0777);
		fd2 = open(av[ac - 1], O_WRONLY | O_CREAT | O_TRUNC, 0777);
		i = 2;
		dup2(fd1, 0);
	}
	while (i < ac - 2)
		processs(av[i++], envp, p);
	dup2(fd2, 1);
	last_process(av, envp, p, ac);
	wait(0);
	exit(1);
	return (1);
}

// int	main(int ac, char **av, char **envp)
// {
// 	int		fd1;
// 	int		fd2;
// 	int		i;
// 	char	**last_cmd;
// 	int		p[2];

// 	i = 2;
// 	last_cmd = ft_split(av[ac - 2], ' ');
// 	fd1 = open(av[1], O_RDONLY);
// 	fd2 = open(av[ac - 1], O_WRONLY | O_CREAT | O_APPEND);
// 	if(fd1 == -1 || fd2 == -1)
// 		ft_error();
// 	if (ac >= 5 && ft_strncmp(av[1], "here_doc", ft_strlen("here_doc")) == 0)
// 	{
// 		here_doc(av);
// 		while (i < ac - 2)
// 			processs(av[i++], envp, p);
// 		last_process(av, envp, p, ac);
// 		wait(0);
// 		exit(1);
// 	}
// 	else
// 	{
// 		dup2(fd1, 0);
// 		dup2(fd2, 1);
// 		processs(av[i++], envp, p);
// 		while (i < ac - 2)
// 			processs(av[i++], envp, p);
// 		if (execve(get_path(av[i], envp), last_cmd, envp) == -1)
// 			ft_error();
// 	}
// 	return (1);
// }
