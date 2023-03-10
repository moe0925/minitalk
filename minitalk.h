/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moeota <moeota@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 22:58:35 by moeota            #+#    #+#             */
/*   Updated: 2023/03/09 09:14:19 by moeota           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <signal.h>
# include <stdint.h>
# include <limits.h>
# include "ft_printf/ft_printf.h"
# include <stdio.h>

int	    ft_atoi(const char *str);
void	ft_putchar_fd(char c, int fd);

#endif