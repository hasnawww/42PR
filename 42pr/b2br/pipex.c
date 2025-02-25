/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilhasnao <ilhasnao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 11:57:02 by hasnawww          #+#    #+#             */
/*   Updated: 2025/02/24 09:39:09 by ilhasnao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char **av, char **envp)
{
	int		p[2];
	__pid_t	pid;

	if (ac == 5 && av[2][0] && av[3][0])
	{
		if (pipe(p) == -1)
		{
			perror("error");
			exit(EXIT_FAILURE);
		}
		pid = fork ();
		if (pid == -1)
		{
			perror("error");
			exit(EXIT_FAILURE);
		}
		if (pid == 0)
			child(p, av, envp);
		else
		{
			waitpid(pid, NULL, 0);
			parent(p, av, envp);
		}
	}
	return (0);
}
