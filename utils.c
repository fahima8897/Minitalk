/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 13:57:12 by marvin            #+#    #+#             */
/*   Updated: 2021/11/04 13:57:12 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void    ft_putchar(char c)
{
    write(1, &c, 1);
}

char    *ft_putstr(char *str)
{
    int i;

    i = 0;
    while(str[i] != '\0')
    {
        ft_putchar(str[i]);
        i++;
    }
    return (str);
}

void    ft_putnbr(int n)
{
    long long c;

    c = n;
    if (c < 0)
    {
        c = -c;
        ft_putchar('-');
    }
    if (c >= 0 && c < 9)
        ft_putchar(c + 48);
    if (c > 9)
    {
        ft_putnbr(c / 10);
        ft_putnbr(c % 10);
    }
}

int ft_atoi(const char *str)
{
    int	i;
	int	res;
	int	sign;

	i = 0;
	res = 0;
	sign = 1;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v' || str[i] == '\f'
		   || str[i] == '\r' || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	return (res * sign);    
}

