/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilhasnao <ilhasnao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 17:09:33 by ilhasnao          #+#    #+#             */
/*   Updated: 2025/02/24 20:18:33 by ilhasnao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipexbonus.h"

int	**pipe_alloc(int command_count)
{
	int	rows;
	int	i;
	int	**pipes;

	rows = command_count - 1;
	pipes = malloc(sizeof(int *) * rows);
	if (!pipes)
		exit(1);
	i = 0;
	while (i < rows)
	{
		pipes[i] = malloc(sizeof(int) * 2);
		if (!pipes[i])
			exit(1);
		if (pipe(pipes[i]) == -1)
			exit(1);
		i++;
	}
	return (pipes);
}

void	close_pipes(int **pipes, int command_count)
{
	int	i;

	i = 0;
	while (i < command_count - 1)
	{
		close(pipes[i][0]);
		close(pipes[i][1]);
		i++;
	}
	free_pipes(pipes, command_count - 1);
}

void	free_pipes(int **pipes, int command_count)
{
	int	i;

	i = 0;
	while (i < command_count)
	{
		free (pipes[i]);
		i++;
	}
	free(pipes);
}

int	*child_support(int command_count)
{
	int	*pids;

	pids = malloc(sizeof(int) * command_count);
	if (!pids)
		exit(1);
	return (pids);
}

int	father(int **pipes, t_pipex_struct *pipex, int *pids)
{
	int	i;
	int	child_code;

	i = 0;
	close_pipes(pipes, pipex->command_count);
	while (i < pipex->command_count)
	{
		waitpid(pids[i], &child_code, 0);
		i++;
	}
	free(pids);
	return (child_code >> 8);
}
