/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fboumell <fboumell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 11:08:50 by fboumell          #+#    #+#             */
/*   Updated: 2021/11/24 17:52:37 by fboumell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	get_my_pid(void)
{
	pid_t	pid;

	pid = getpid();
	ft_putstr("Hello my PID is : ");
	ft_putnbr(pid);
	ft_putchar('\n');
}

void	handler(int signum)
{
	char	c;
	int		i;

	c = 0;
	i = 0;
	if (signum == SIGUSR1)
		c |= 1 << i;
	i++;
	if (i == 8)
	{
		if (c == '\0')
			ft_putchar('\n');
		else
			ft_putchar(c);
		c = 0;
		i = 0;
	}
}

int	main()
{
	struct sigaction	sa;
	
	get_my_pid();
	sa.sa_handler = handler;
	sa.sa_flags = 0;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
	{
		pause();
	}
	return (0);
}
