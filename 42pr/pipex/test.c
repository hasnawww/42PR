/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasnawww <hasnawww@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 17:35:58 by hasnawww          #+#    #+#             */
/*   Updated: 2025/01/20 17:21:51 by hasnawww         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <string.h>

// int main()
// {
//     int     fd = open("zibiw.txt", O_WRONLY);
//     int     wiwi = dup2(fd, 1);
//     char    msg[] = "nikwebi\n";

//     printf("fd = %d", fd);
//     write(1, msg, strlen(msg));
//     write(wiwi, "tweaker\n", strlen("tweaker") + 1);
//     return (0);
// }

// int main()
// {
//     __pid_t pid = fork();
//     if (pid < 0)
//     {
//         write(2, "Fork failed\n", 12);
//         return (-1);
//     }
//     printf("pid: %d\n", pid);
//     write(1, "Hello World!\n", 13);
//     return (0);
// }