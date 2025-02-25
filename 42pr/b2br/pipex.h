/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilhasnao <ilhasnao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 20:45:16 by ilhasnao          #+#    #+#             */
/*   Updated: 2025/02/24 09:26:40 by ilhasnao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <string.h>
# include <sys/wait.h>
# include "libft/libft.h"

char	*get_path(char *cmd, char **envp);
char	*path_line(char **env);
void	dree_split(char **result);
void	child(int *p, char **av, char **envp);
void	parent(int *p, char **av, char **envp);
void	ft_grr(char **cmd, int exit_code);

#endif