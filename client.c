/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fboumell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 11:08:39 by fboumell          #+#    #+#             */
/*   Updated: 2021/10/05 11:08:42 by fboumell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	check_first_argument(char *pid)
{
	while(*pid)
	{
		if(*pid < '0' || *pid > '9')
			return (1);
		pid++;
	}
	return(0);
}

void	send_signal(pid_t pid, char c)
{
	int i;

	i = 7;
	while(i >= 0)
	{
		if (c & (1 << i))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		i--;
		usleep(200);
	}
}

int main(int ac, char **av)
{
	int i;
	pid_t pid_server;

	i = 0;
	if (ac != 3)
		ft_putstr("Attention please ! wrong number of arguments\n");
	if(check_first_argument(av[1]) == 1)
		ft_putstr("Your PID is not correct\n");
	pid_server = atoi(av[1]);
	while(av[2][i] != '/0')
	{
		send_signal(pid_server, av[2][i]);
		i++;
	}
	return(0);
}