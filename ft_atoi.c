/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moeota <moeota@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 22:58:58 by moeota            #+#    #+#             */
/*   Updated: 2023/03/09 04:21:30 by moeota           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "minitalk.h"

static int	skip(unsigned char *str2, int *minus)
{
	int	i;

	i = 0;
	while (((str2[i] >= 9) && (str2[i] <= 13)) || (str2[i] == 32))
		i++;
	if (str2[i] == 43 || str2[i] == 45)
	{
		if (str2[i] == 45)
			*minus = -1;
		i++;
	}
	return (i);
}

static int	my_plusatol(long num, unsigned char *str, int i)
{
	if (num == INT32_MAX / 10 && str[i + 1] > '7')
		return ((int)(num * 10 + str[i + 1] - '0'));
	if (num < __LONG_MAX__ / 100)
		return ((int)(num * 10 + str[i + 1] - '0'));
	if ((num == __LONG_MAX__ / 10 && str[i + 1] < '8'))
		return ((int)(num * 10 + str[i + 1] - '0'));
	if (num == __LONG_MAX__ / 100 && str[i + 1] >= '8')
		return ((int)__LONG_MAX__);
	if (num > __LONG_MAX__ / 100)
		return ((int)__LONG_MAX__);
	return (0);
}

static int	my_minusatol(long num, unsigned char *str, int i)
{
	if (num == INT32_MAX / 10 && str[i + 1] > '8')
		return ((int)((num * 10 + str[i + 1] - '0') * (-1)));
	if (num < LONG_MAX / 100)
		return ((int)(num * 10 * (-1) + str[i + 1] - '0'));
	if ((num == LONG_MAX / 10 && str[i + 1] < '9'))
		return ((int)((num * 10 + str[i + 1] - '0') * (-1)));
	if (num == LONG_MAX / 100 && str[i + 1] >= '9')
		return ((int)LONG_MIN);
	if (num > LONG_MAX / 100)
		return ((int)LONG_MIN);
	return (0);
}

int	ft_atoi(const char *str)
{
	long			num;
	int				i;
	int				minus;
	unsigned char	*str2;

	str2 = (unsigned char *)str;
	num = 0;
	minus = 1;
	i = skip(str2, &minus);
	while ((str2[i] >= 48) && (str2[i] <= 57))
	{
		if (num * 100 / 100 != num)
		{
			if (minus == 1)
				return (my_plusatol(num, str2, i));
			if (minus == -1)
				return (my_minusatol(num, str2, i));
		}
		num = num + str[i] - 48;
		num = num * 10;
		i++;
	}
	num = num / 10;
	return (num * minus);
}

// int main()
// {
// 	char *str = "-100";
// 	// ft_atoi(str);
// 	printf("%d\n", ft_atoi(str));
// }
// 