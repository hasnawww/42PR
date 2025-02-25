/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilhasnao <ilhasnao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 07:47:41 by ilhasnao          #+#    #+#             */
/*   Updated: 2025/02/24 21:40:40 by ilhasnao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_grr(char **cmd, int exit_code)
{
	dree_split(cmd);
	perror("error");
	exit(exit_code);
}

void	child(int *p, char **av, char **envp)
{
	char	**big_cmd1;
	int		fd1;
	char	*path;

	big_cmd1 = ft_split(av[2], ' ');
	close(p[0]);
	fd1 = open(av[1], O_RDONLY, 0777);
	if (fd1 == -1)
		ft_grr(big_cmd1, 1);
	path = get_path(av[2], envp);
	if (!path)
		ft_grr(big_cmd1, EXIT_FAILURE);
	dup2(fd1, 0);
	close(fd1);
	dup2(p[1], 1);
	close(p[1]);
	if (execve(path, big_cmd1, envp) == -1)
	{
		free(path);
		ft_putstr_fd("pipex: command not found: ", 2);
		ft_putendl_fd(big_cmd1[0], 2);
		ft_grr(big_cmd1, EXIT_FAILURE);
	}
}

void	parent(int *p, char **av, char **envp)
{
	char	**big_cmd2;
	int		fd2;
	char	*path;

	big_cmd2 = ft_split(av[3], ' ');
	close(p[1]);
	fd2 = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (fd2 == -1)
		ft_grr(big_cmd2, 1);
	dup2(fd2, 1);
	close(fd2);
	dup2(p[0], 0);
	close(p[0]);
	path = get_path(av[3], envp);
	if (!path)
		ft_grr(big_cmd2, 127);
	if (execve(path, big_cmd2, envp) == -1)
	{
		ft_putstr_fd("pipex: command not found: ", 2);
		ft_putendl_fd(big_cmd2[0], 2);
		free(path);
		ft_grr(big_cmd2, 127);
	}
}
