/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilhasnao <ilhasnao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 20:19:24 by ilhasnao          #+#    #+#             */
/*   Updated: 2025/02/24 20:20:55 by ilhasnao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipexbonus.h"

void	free_lfile(int **pipes, int *pids, t_pipex_struct *pipex)
{
	free(pids);
	free_pipes(pipes, pipex->command_count - 1);
	exit(1);
}

void	ft_error(char **cmd, int exit_code)
{
	dree_split(cmd);
	perror("error");
	exit(exit_code);
}
