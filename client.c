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
	
}
int main(int ac, char **av)
{
	pid_t pid_server;
	if (ac != 3)
		ft_putstr("Attention please ! wrong number of arguments\n");
	if(check_first_argument(av[1]) == 1)
		ft_putstr("Your PID is not correct\n");
	pid_server = atoi(av[1]);

	

}