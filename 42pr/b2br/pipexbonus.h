/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipexbonus.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilhasnao <ilhasnao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 20:45:16 by ilhasnao          #+#    #+#             */
/*   Updated: 2025/02/24 21:20:02 by ilhasnao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEXBONUS_H
# define PIPEXBONUS_H

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <string.h>
# include <sys/wait.h>
# include "libft/libft.h"

typedef struct s_pipex_struct
{
	int		command_count;
	char	**new_av;
	char	**av;
	char	**envp;
	int		ac;
	int		infile;
}					t_pipex_struct;

void	dree_split(char **result);
char	*path_line(char **env);
char	*get_path(char *cmd, char **envp);
int		processs(t_pipex_struct *pipex);
void	last_process(char **av, char **env, int *p, int ac);
void	here_doc(char **av, t_pipex_struct *pipex);
void	ft_error(char **cmd, int exit_code);
void	child_process(t_pipex_struct *p, int **pipe, int index, int *pids);
void	free_pipes(int **pipes, int command_count);
int		*child_support(int command_count);
int		**pipe_alloc(int command_count);
void	close_pipes(int **pipes, int command_count);
int		**pipe_alloc(int command_count);
int		father(int **pipes, t_pipex_struct *pipex, int *pids);
void	exec(char *cmd, char **envp, int *pids);
void	free_lfile(int **pipes, int *pids, t_pipex_struct *pipex);
void	first_cmd(t_pipex_struct *p, int fd, int **pipe, int *pids);

#endif