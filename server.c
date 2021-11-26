/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fboumell <fboumell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 11:08:50 by fboumell          #+#    #+#             */
/*   Updated: 2021/11/26 16:23:30 by fboumell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	get_my_pid(int ac)
{
	pid_t	pid;

	if (ac > 1)
		ft_putstr("Too many arguments!\n");
	if (ac == 1)
	{	
		pid = getpid();
		ft_putstr("Hello my PID is : ");
		ft_putnbr(pid);
		ft_putchar('\n');
	}
}

void	convert_bits(int *s)
{
	char	c;
	int		i;

	c = 0;
	i = 7;
	while (i >= 0)
	{
		if (s[i] == '1')
			c |= 1 << (7 - i);
		i--;
	}
	ft_putchar(c);
}

void	handler(int signum)
{
	static int	s[8];
	static int	len = 0;

	if (signum == SIGUSR1)
		s[len] = '1';
	else if (signum == SIGUSR2)
		s[len] = '0';
	len++;
	if (len == 8)
	{
		s[len] = '\0';
		convert_bits(s);
		len = 0;
	}
}

int	main(int ac, char **av)
{
	struct sigaction	sa;

	(void)av;
	sa.sa_handler = handler;
	sa.sa_flags = 0;
	get_my_pid(ac);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
	{
		pause();
	}
	return (0);
}
