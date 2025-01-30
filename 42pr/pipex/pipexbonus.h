/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipexbonus.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasnawww <hasnawww@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 20:45:16 by ilhasnao          #+#    #+#             */
/*   Updated: 2025/01/30 11:46:39 by hasnawww         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEXBONUS_H
# define PIPEXBONUS_H

#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <sys/wait.h>
# include "libft/libft.h"

int	get_line(char *limiter, int *p);

#endif