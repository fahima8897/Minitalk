/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fboumell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 11:59:34 by fboumell          #+#    #+#             */
/*   Updated: 2021/10/05 11:02:34 by fboumell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include <stdio.h>

int main()
{
	int pid;

	pid = getpid();
	printf("Mon PID est : %d", pid);
/*	int ret;
	ret = kill(pid, SIGUSR1);
	if (ret == -1)
		printf("kill error");
	return 0;*/
}
