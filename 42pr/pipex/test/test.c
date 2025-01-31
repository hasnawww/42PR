/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilhasnao <ilhasnao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 17:35:58 by hasnawww          #+#    #+#             */
/*   Updated: 2025/01/31 16:32:47 by ilhasnao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>

// int	main(int ac, char **av, char **env)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	j = 0;
// 	if (av[0])
// 		printf("oui\n");
// 	if (ac > 0)
// 	{
// 		printf("oui\n");
// 		while (env[i])
// 		{
// 			printf("oui\n");
// 			printf("%s", env[i]);
// 			i++;
// 		}
// 	}
// 	return (0);
// }

// int main(int ac, char **av)
// {
//     int i = 0;
//     int j = 0;
//     int k = 0;
//     int **pid;
//     int *range;

//     range = malloc(sizeof(int) * 1000);
//     pid = malloc(sizeof(int *) * 1000);
//     av[0] = "a.out";
//     while (ac - j > 0)
//     {
//         range[j] = ac - j;
//         printf(" range = %d\n", range[j]);
//         j++;
//     }
//     while (j > 0)
//     {
//         pid[k] = malloc(sizeof(int));
//         pid[k][i] = range[j];
//         printf("pid = %d\n", pid[k][i]);
//         free (pid[k]);
//         i++;
//         k++;
//         j--;
//     }
//     free (range);
//     free (pid);
//     return (0);
// }

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

// int main(int ac, char **av)
// {
//     __pid_t pid = fork();
//     int i = 1;

//     if (ac > 1)
//         av[1][0] += 9;
//     while (i < ac)
//     {
//         pid = fork();
//         if (pid < 0)
//         {
//             write(2, "Fork failed\n", 12);
//             return (-1);
//         }
//     printf("pid: %d\n", pid);
//     write(1, "Hello World!\n", 13);
//     if (pid == 0)
//         break;
//     i++;
//     }
//     return (0);
// }

// int main ()
// {
// pid_t pid = fork();

// pid = fork();
// if (pid == 0) {
//       // Code exécuté par l'enfant
//       printf("Je suis l'enfant avec PID = %d\n", getpid());
//     } 
//     else if (pid > 0) {
//         // Code exécuté par le parent
//       printf("Je suis le parent, mon enfant a le PID = %d\n", pid);
//     } else {
//       perror("fork failed");
//     }
// }