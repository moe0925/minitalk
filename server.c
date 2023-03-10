/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moeota <moeota@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 22:58:35 by moeota            #+#    #+#             */
/*   Updated: 2023/03/10 16:50:15 by moeota           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	signal_handler(int signal)
{
	static int	bit = 0;
	static int	i = 0;

	if (signal == SIGUSR1)
		i |= (1 << bit);
	bit++;
	if (bit == 8)
	{
		ft_putchar_fd(i, 1);
		bit = 0;
		i = 0;
	}
}


int main ()
{
    struct sigaction sa;

	ft_printf("PIDID: %d\n",(pid_t)getpid());
    sigemptyset(&sa.sa_mask);
    sa.sa_handler  = signal_handler;
    sa.sa_flags = 0;
    sigaction(SIGUSR1, &sa, NULL);
    sigaction(SIGUSR2, &sa, NULL);
    while(1)
	{
		pause();
    }
	exit (EXIT_SUCCESS);
}


// int	main(int argc, char **argv)
// {
// 	int	pid;

// 	(void)argv;
// 	if (argc != 1)
// 	{
// 		ft_printf("\033[91mError: wrong format.\033[0m\n");
// 		ft_printf("\033[33mTry: ./server\033[0m\n");
// 		return (0);
// 	}
// 	pid = getpid();
// 	ft_printf("\033[94mPID\033[0m \033[96m->\033[0m %d\n", pid);
// 	ft_printf("\033[90mWaiting for a message...\033[0m\n");
// 	while (argc == 1)
// 	{
// 		signal(SIGUSR1, ft_handler);
// 		signal(SIGUSR2, ft_handler);
// 		pause ();
// 	}
// 	return (0);
// }
