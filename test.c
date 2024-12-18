int main ()
{
    int 
}


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moeota <moeota@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 22:58:35 by moeota            #+#    #+#             */
/*   Updated: 2023/03/09 03:43:45 by moeota           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void signal_handler(int signum)
{
	
	static int 				bit = 0;
	static unsigned char 	c = 0;

	c |= (signum == SIGUSR2);
	// c = 0;
	// i = 0;

	// if (signum == SIGUSR2)
	// {
	// 	c |= 1 << i;
	// }
	// c |= (signum == SIGUSR2);
	
	///2
	// if (signal == SIGUSR2)
	// {
	// 	c |= (1 << i);
	// }
	// i++;
	
	if (!c)
		exit (EXIT_FAILURE);
	bit++;
	
	if (bit == 8)
	{
		ft_putchar_fd((char)c, 1);
		bit = 0;
		c = 0;
	}
	c >>= 1;
}

int main ()
{
    struct sigaction sa;

    sigemptyset(&sa.sa_mask);
    sa.sa_handler = signal_handler;
    sa.sa_flags = 0;
    sigaction(SIGUSR1, &sa, NULL);
    sigaction(SIGUSR2, &sa, NULL);
	
    while(1)
	{
		pause();
    }
	exit (EXIT_SUCCESS);
}


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moeota <moeota@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 22:58:35 by moeota            #+#    #+#             */
/*   Updated: 2023/03/09 03:42:03 by moeota           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"///server

void    send_char(pid_t pid, char c)
{
    int             bit;
    int             i;
    unsigned char   uc;

    uc = (unsigned char)c;
    i = 0;
    while (i < 8)
    {
        usleep(100);
        bit = (uc >> i) & 1;
        if (kill(pid, SIGUSR1 + bit) == -1)
		{
            ft_putchar_fd("kill error", 1);
			exit(EXIT_FAILURE);
		}
        i++;
    }
}

int	main(int argc, char **argv)
{
	size_t	i;

    i = 0;

    if (argc != 3 || (!(argv[2])))
    {
       return (EXIT_FAILURE);
    }
    // signal (SIGUSR1, send_char);
    // signal (SIGUSR2, send_char);

    while (!(argv[2][i]))
        send_char((pid_t)ft_atoi(argv[1]), argv[2][i++]);
    while (1)
    {
        pause();
    }
    exit (EXIT_SUCCESS);
}