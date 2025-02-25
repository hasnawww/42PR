/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilhasnao <ilhasnao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 14:48:35 by ilhasnao          #+#    #+#             */
/*   Updated: 2025/02/24 20:17:17 by ilhasnao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipexbonus.h"

int	main(int ac, char **av, char **envp)
{
	t_pipex_struct	pipex_vars;

	pipex_vars.ac = ac;
	pipex_vars.av = av;
	pipex_vars.envp = envp;
	if (ac < 5)
	{
		return (1);
	}
	if (ft_strncmp(av[1], "here_doc", ft_strlen("here_doc")) == 0)
	{
		here_doc(av, &pipex_vars);
		pipex_vars.command_count = ac - 4;
		pipex_vars.new_av = av + 3;
	}
	else
	{
		pipex_vars.command_count = ac - 3;
		pipex_vars.new_av = av + 2;
	}
	return (processs(&pipex_vars));
}
