/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moeota <moeota@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 22:58:35 by moeota            #+#    #+#             */
/*   Updated: 2023/03/10 16:46:00 by moeota           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"///server

// void	send_char(pid_t pid, char c)
// {
// 	static int	bit;
// 	static int i;
// 	static unsigned char uc;
	
// 	uc = (unsigned char)c;
// 	while (bit < 8)
// 	{
// 		usleep(100);
// 		bit = (uc >> i) & 0x01;
//         // if (kill(pid, SIGUSR1 + i) == -1)
// 		// {
//         //     ft_printf("kill error", 1);
// 		// 	exit(EXIT_FAILURE);
// 		// }
// 		usleep(100);
// 		i++;
// 	}
// }
// void    send_char(pid_t pid, char c)
// {
//     int             bit;
//     int             i;
//     unsigned char   uc;

//     uc = (unsigned char)c;
//     i = 0;
//     while (i < 8)
//     {
//         usleep(50);
//         bit = (uc >> i) & 0x01;
//         if (kill(pid, SIGUSR1 + bit) == -1)
//             fatal("kill error");
//         i++;
//     }
// }

void	send_char(pid_t pid, char i)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		usleep(100);
		if ((i & (0x01 << bit)) != 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		
		usleep(100);
		bit++;
	}
}

int	main(int argc, char **argv)
{
	int i;

	i = 0;
	if (argc != 3 || !(argv[1]) || !(argv[2]))
		exit(EXIT_FAILURE);
	while(argv[2][i] != '\0')
	{
		send_char((pid_t)ft_atoi(argv[1]), (argv[2][i]));
		i++;
	}
	exit (EXIT_SUCCESS);
}