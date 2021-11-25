/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fboumell <fboumell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 11:08:50 by fboumell          #+#    #+#             */
/*   Updated: 2021/11/25 15:27:17 by fboumell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int len;

void	get_my_pid(void)
{
	pid_t	pid;

	pid = getpid();
	ft_putstr("Hello my PID is : ");
	ft_putnbr(pid);
	ft_putchar('\n');
}

void	convert_bits(char *s)
{
	char	c;
	int	i;

	c = 0;
	i = 7;
	while (i >= 0)
	{
		if (s[i] == '1')
			c |= 1 << (7 - i);
		i--;
	}
	free(s);
	ft_putchar(c);
	
}

void	handler(int signum)
{
	char *s;
	
	if (len == 0)
		s = malloc(sizeof(char) * (8 + 1));
	if (signum == SIGUSR1)
		s[len] = '1';
	if (signum == SIGUSR2)
		s[len] = '0';
	len++;
	if (len == 8)
	{
		s[len] = '\0';
		convert_bits(s);
		len = 0;
	}
}

int	main()
{
	struct sigaction	sa;
	
	len = 0;
	sa.sa_handler = handler;
	sa.sa_flags = 0;
	get_my_pid();
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
	{
		pause();
	}
	return (0);
}
