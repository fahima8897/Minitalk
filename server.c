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

#include <signal.h>
#include <unistd.h>
#include <stdio.h>

void	handle_sigusr1(int sig)
{
	printf("alors comment ca va");
}

int main()
{
	int pid;
    struct sigaction sa;
	sa.sa_handler = &handle_sigusr1;
    sigaction(SIGUSR2, &sa, NULL);

	pid = getpid();
	printf("Mon PID est : %d", pid);
	kill(pid,SIGUSR2);
	
}
