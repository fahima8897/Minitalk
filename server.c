/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fboumell <fboumell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 11:08:50 by fboumell          #+#    #+#             */
/*   Updated: 2021/11/26 17:21:01 by fboumell         ###   ########.fr       */
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

void	handler(int signum)
{
	static char	c;
	static int	i;

	if (signum == SIGUSR1)
		c |= 1 << i;
	i++;
	if (i == 8)
	{
		ft_putchar(c);
		i = 0;
		c = 0;
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
