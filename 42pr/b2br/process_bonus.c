/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilhasnao <ilhasnao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 14:49:00 by ilhasnao          #+#    #+#             */
/*   Updated: 2025/02/24 21:32:51 by ilhasnao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipexbonus.h"

void	exec(char *cmd, char **envp, int *pids)
{
	char	**big_cmd;
	char	*path;

	if (cmd[0] == '\0')
	{
		free(pids);
		exit(1);
	}
	path = get_path(cmd, envp);
	if (!path)
	{
		free(pids);
		free(path);
		exit(127);
	}
	big_cmd = ft_split(cmd, ' ');
	if (execve(path, big_cmd, envp) == -1)
	{
		ft_putstr_fd("pipex: command not found: ", 2);
		ft_putendl_fd(big_cmd[0], 2);
		ft_error (big_cmd, 1);
	}
}

void	first_cmd(t_pipex_struct *p, int fd, int **pipe, int *pids)
{
	if (ft_strncmp(p->av[1], "here_doc", ft_strlen("here_doc")) == 0)
		fd = p->infile;
	else
		fd = open(p->av[1], O_RDONLY, 0777);
	if (fd == -1)
		free_lfile(pipe, pids, p);
	dup2(fd, 0);
	close (fd);
}

void	child_process(t_pipex_struct *p, int **pipe, int index, int *pids)
{
	int	fd;
	int	fd2;

	fd = 0;
	if (index == 0)
		first_cmd(p, fd, pipe, pids);
	else
		dup2(pipe[index - 1][0], 0);
	if (index == p->command_count - 1)
	{
		if (ft_strncmp(p->av[1], "here_doc", ft_strlen("here_doc")) == 0)
			fd2 = open(p->av[p->ac -1], O_WRONLY | O_CREAT | O_APPEND, 0777);
		else
			fd2 = open(p->av[p->ac -1], O_WRONLY | O_CREAT | O_TRUNC, 0777);
		if (fd2 == -1)
			free_lfile(pipe, pids, p);
		dup2(fd2, 1);
		close(fd2);
	}
	else
		dup2(pipe[index][1], 1);
	close_pipes(pipe, p->command_count);
	exec(p->new_av[index], p->envp, pids);
}

int	processs(t_pipex_struct *pipex)
{
	int	**pipes;
	int	*pids;
	int	i;

	i = 0;
	pipes = pipe_alloc(pipex->command_count);
	pids = child_support(pipex->command_count);
	while (i < pipex->command_count)
	{
		pids[i] = fork();
		if (pids[i] == -1)
			exit(1);
		if (pids[i] == 0)
			child_process(pipex, pipes, i, pids);
		i++;
	}
	return (father(pipes, pipex, pids));
}

void	here_doc(char **av, t_pipex_struct *pipex)
{
	int		fd;
	char	*line;

	fd = open("temp.txt", O_WRONLY | O_CREAT, 0777);
	if (fd == -1)
		exit(1);
	ft_putstr_fd("here_doc> ", 1);
	line = get_next_line(0);
	while (line)
	{
		if (ft_strncmp(line, av[2], ft_strlen(av[2])) == 0)
		{
			get_next_line(-1);
			break ;
		}
		ft_putstr_fd(line, fd);
		free(line);
		ft_putstr_fd("here_doc> ", 1);
		line = get_next_line(0);
	}
	free(line);
	close(fd);
	pipex->infile = open("temp.txt", O_RDONLY);
	if (pipex->infile == -1)
		exit (1);
}
