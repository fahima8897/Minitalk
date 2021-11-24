/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fboumell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 11:08:50 by fboumell          #+#    #+#             */
/*   Updated: 2021/10/05 12:10:50 by fboumell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	get_my_pid(void)
{
	pid_t pid;

	pid = getpid();
	ft_putstr("Hello my PID is : ");
	ft_putnbr(pid);
	ft_putchar('\n');
}

void	handler(int signum)
{
	char c;
	int i;

	c = 0;
	i = 0;
	if (signum == SIGUSR1)
			c |= 1 << i;
	i++;
	if (i == 8)
		ft_putchar(c);
}

int	main()
{
	struct sigaction	sa;

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
